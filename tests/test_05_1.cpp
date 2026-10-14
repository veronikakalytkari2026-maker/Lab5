
#include <gtest/gtest.h>
#include <cmath>

#define main lab5_main
#include "../Lab_05_1.cpp"
#undef main

TEST(FunctionTest, FirstValue)
{
    double expected = 6.0 / (std::sin(2.0) * std::sin(2.0) + 9.0);
    EXPECT_NEAR(f(1.0, 2.0, 3.0), expected, 1e-9);
}

TEST(FunctionTest, SecondValue)
{
    double expected = 3.0 / (std::sin(1.0) * std::sin(1.0) + 1.0);
    EXPECT_NEAR(f(1.0, 1.0, 1.0), expected, 1e-9);
}

TEST(FunctionTest, NegativeValues)
{
    double expected = 0.0;
    EXPECT_NEAR(f(1.0, -1.0, 0.0), expected, 1e-9);
}