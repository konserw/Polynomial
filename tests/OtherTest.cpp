#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(OtherTests, ZeroValue) {
    polynomial w = {1, 2, 0, 3};
    ASSERT_EQ(3, w(0));
}

TEST(OtherTests, IntegerValueExample1) {
    polynomial w = {1, 2, 0, 3};
    ASSERT_EQ(48, w(3));
}

TEST(OtherTests, IntegerValueExample2) {
    polynomial w = {0.2, 2.785, 0, -2, 0, 3};
    ASSERT_DOUBLE_EQ(259.185, w(3));
}

TEST(OtherTests, DoubleValueExample1) {
    polynomial w = {1, 2, 0, 3};
    ASSERT_DOUBLE_EQ(-4.569, w(-2.9));
}

TEST(OtherTests, DoubleValueExample2) {
    polynomial w = {0.2, 2.785, 0, -2, 0, 3};
    ASSERT_DOUBLE_EQ(142.1354605l, w(-2.9));
}

TEST(OtherTests, DoubleValueExample3) {
    polynomial w = {0.2, 2.785, 0, -2, 0, 3};
    ASSERT_NEAR(1.12315793459473E+05L, w(12.125), 0.5E-9L);
}

TEST(OtherTests, DerivativeExample1) {
    polynomial w = {1, 0, 0, 0, 0, 0};
    polynomial der = {5, 0, 0, 0, 0};
    EXPECT_EQ (der, w.derivative());
}

TEST(OtherTests, DerivativeExample2) {
    polynomial w = {1, 0, -9, -5, 0};
    polynomial der = {4, 0, -18, -5};
    EXPECT_EQ (der, w.derivative());
}

TEST(OtherTests, DerivativeExample3) {
    polynomial w = {-0.25, 0, 0, 0, 0.5, 0, 0, 0, 9};
    polynomial der = {-2, 0, 0, 0, 2, 0, 0, 0};
    EXPECT_EQ (der, w.derivative());
}
