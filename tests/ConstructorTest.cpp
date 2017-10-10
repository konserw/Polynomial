#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(ConstructorTest, ByDefaultEmptyPolynomial) {
    polynomial w;
    ASSERT_TRUE(w.isEmpty());
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(0, w.at(0));
}

TEST(ConstructorTest, ConstantTerm) {
    polynomial w(1);//w = 1
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(1, w[0]);
}

TEST(ConstructorTest, Binomial) {
    polynomial w {1, 2};//w = x + 2
    ASSERT_EQ(1, w.degree());
    ASSERT_EQ(2, w[0]);
    ASSERT_EQ(1, w[1]);
}

TEST(ConstructorTest, 3DegreePolinomial) {
    polynomial w = {3, 2, 1};//w = 3x^2 + 2x + 1
    ASSERT_EQ(2, w.degree());
    ASSERT_EQ(1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(3, w[2]);
}
