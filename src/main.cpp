#include <iostream>
#include <cstdlib>
#include <SDL.h>

int main(int argc, char** argv) {
    using std::cerr;
    using std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 620, 387, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    bool shouldRender = true;
    if(argc == 2 && std::string(argv[1]) == "--headless"){
        // dont create or destory any renderers
        shouldRender = false;
    }

    SDL_Renderer* ren = nullptr;
    if(shouldRender){
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (ren == nullptr) {
            cerr << "SDL_CreateRenderer Error" << SDL_GetError() << endl;
            SDL_DestroyWindow(win);
            SDL_Quit();
            return EXIT_FAILURE;
        }
    }

    SDL_Surface* bmp = SDL_LoadBMP("img/grumpy-cat.bmp");
    if (bmp == nullptr) {
        cerr << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if(shouldRender){
        SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
        if (tex == nullptr) {
            cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
            SDL_FreeSurface(bmp);
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            SDL_Quit();
            return EXIT_FAILURE;
        }

        SDL_FreeSurface(bmp);

        for (int i = 0; i < 20; i++) {
            SDL_RenderClear(ren);
            SDL_RenderCopy(ren, tex, nullptr, nullptr);
            SDL_RenderPresent(ren);
            SDL_Delay(100);
        }

        SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren);

    }
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}
