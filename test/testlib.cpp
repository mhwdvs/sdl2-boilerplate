#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Hello World!\n";
    RUN_ALL_TESTS();
	return 0;
}

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(Factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(8), 40320);
}