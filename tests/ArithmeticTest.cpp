#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(ArithmeticTest, Negation) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    -w;
    ASSERT_EQ(-1, w[0]);
    ASSERT_EQ(-2, w[1]);
    ASSERT_EQ(-3, w[2]);
}

TEST(ArithmeticTest, NegativesNegation) {
    polynomial w;
    w << -1 << -2 << -3;//w = -3x^2 - 2x - 1
    -w;
    ASSERT_EQ(1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(3, w[2]);
}

TEST(ArithmeticTest, MixedNegation) {
    polynomial w;
    w << 1 << -2 << 3;//w = 3x^2 - 2x + 1
    -w;
    ASSERT_EQ(-1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(-3, w[2]);
}

TEST(ArithmeticTest, Addition) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    polynomial v(4, 5); //v = 4x + 5
    polynomial z = w+v; //z = 3x^2 + 6x + 6
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(6, z[1]);
    ASSERT_EQ(3, z[2]);
}

TEST(ArithmeticTest, AdditionInverted) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    polynomial v(4, 5); //v = 4x + 5
    polynomial z = v+w; //z = 3x^2 + 6x + 6
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(6, z[1]);
    ASSERT_EQ(3, z[2]);
}


TEST(ArithmeticTest, MixedAddition) {
    polynomial w;
    w << 1 << -2 << 3;//w = 3x^2 - 2x + 1
    polynomial v(4, -5); //v = 4x - 5
    polynomial z = w+v; //z = 3x^2 + 2x - 4
    ASSERT_EQ(-4, z[0]);
    ASSERT_EQ(2, z[1]);
    ASSERT_EQ(3, z[2]);
}
