#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    for(size_t i = 0; i < size_t (argc); ++i){
        if(strcmp(argv[i], "--test") == 0){ // only run tests if requested
            ::testing::InitGoogleTest(&argc, argv);
            auto res = RUN_ALL_TESTS();
            std::cout << "Unit tests returned: " << res << '\n';
        }
    }
    std::cout << "Hello World!\n";
	return 0;
}
