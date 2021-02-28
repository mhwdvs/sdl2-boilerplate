#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Hello World!\n";
    EXPECT_TRUE(argc == 0) << "Tests are working!\n";
	return 0;
}
