#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(ArithmeticTest, Negation) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    -w;
    ASSERT_EQ(-1, w[0]);
    ASSERT_EQ(-2, w[1]);
    ASSERT_EQ(-3, w[2]);
}

TEST(ArithmeticTest, NegativesNegation) {
    polynomial w = {-3, -2, -1};//w = -3x^2 - 2x - 1
    -w;
    ASSERT_EQ(1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(3, w[2]);
}

TEST(ArithmeticTest, MixedNegation) {
    polynomial w = {3, -2, 1};//w = 3x^2 - 2x + 1
    -w;
    ASSERT_EQ(-1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(-3, w[2]);
}

TEST(ArithmeticTest, Addition) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    polynomial v = {4, 5}; //v = 4x + 5
    polynomial z = w+v; //z = 3x^2 + 6x + 6
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(6, z[1]);
    ASSERT_EQ(3, z[2]);
}

TEST(ArithmeticTest, AdditionInverted) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    polynomial v = {4, 5}; //v = 4x + 5
    polynomial z = v+w; //z = 3x^2 + 6x + 6
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(6, z[1]);
    ASSERT_EQ(3, z[2]);
}


TEST(ArithmeticTest, MixedAddition) {
    polynomial w = {3, -2, 1};//w = 3x^2 - 2x + 1
    polynomial v = {4, -5}; //v = 4x - 5
    polynomial z = w+v; //z = 3x^2 + 2x - 4
    ASSERT_EQ(-4, z[0]);
    ASSERT_EQ(2, z[1]);
    ASSERT_EQ(3, z[2]);
}

TEST(ArithmeticTest, Substraction) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    polynomial v = {4, 5}; //v = 4x + 5
    polynomial z = w-v; //z = 3x^2 - 2x - 4
    ASSERT_EQ(-4, z[0]);
    ASSERT_EQ(-2, z[1]);
    ASSERT_EQ(3, z[2]);
}

TEST(ArithmeticTest, SustractionInverted) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    polynomial v = {4, 5}; //v = 4x + 5
    polynomial z = v-w; //z = -3x^2 + 2x + 4
    ASSERT_EQ(4, z[0]);
    ASSERT_EQ(2, z[1]);
    ASSERT_EQ(-3, z[2]);
}


TEST(ArithmeticTest, MixedSubsraction) {
    polynomial w = {3, -2, 1};//w = 3x^2 - 2x + 1
    polynomial v = {4, -5}; //v = 4x - 5
    polynomial z = w-v; //z = 3x^2 - 6x + 6
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(-6, z[1]);
    ASSERT_EQ(3, z[2]);
}

TEST(ArithmeticTest, BasicMultiplicatin) {
    polynomial w = {1, 3};
    polynomial v = {1, 2};
    polynomial z = w*v;
    ASSERT_EQ(6, z[0]);
    ASSERT_EQ(5, z[1]);
    ASSERT_EQ(1, z[2]);
}

TEST(ArithmeticTest, ComplexMultiplicatin) {
    polynomial w = {3, -9, 5};
    polynomial v = {2, 4, -7};
    polynomial z = w*v;
    ASSERT_EQ(-35,	z[0]);
    ASSERT_EQ(83,	z[1]);
    ASSERT_EQ(-47,	z[2]);
    ASSERT_EQ(-6,	z[3]);
    ASSERT_EQ(6,	z[4]);
}
