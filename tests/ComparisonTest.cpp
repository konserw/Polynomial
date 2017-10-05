#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(ComparisonTest, Equality) {
    polynomial w = {3, 2, 1};
    polynomial v = {3, 2, 1};
    polynomial z = {3, 2, 0};
    ASSERT_TRUE(w == v);
    ASSERT_FALSE(w == z);
}

TEST(ComparisonTest, Inequality) {
    polynomial w = {3, 2, 1};
    polynomial v = {3, 2, 1};
    polynomial z = {3, 2, 0};
    ASSERT_FALSE(w != v);
    ASSERT_TRUE(w != z);
}
