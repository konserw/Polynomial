#include <sstream>
#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(FillTest, Integers1) {
    polynomial w;
    w << 1;
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(1, w[0]);
}

TEST(FillTest, Integers2) {
    polynomial w;
    w << 2 << 1;
    ASSERT_EQ(1, w.degree());
    ASSERT_EQ(2, w[0]);
    ASSERT_EQ(1, w[1]);
}

TEST(FillTest, Integers3) {
    polynomial w;
    w << 1;
    w << 2;
    w << 3;
    ASSERT_EQ(2, w.degree());
    ASSERT_EQ(1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(3, w[2]);
}

TEST(FillTest, Double) {
    polynomial w;
    std::istringstream str("1.123456789");
    str >> w;
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(1.123456789l, w[0]);
}

TEST(FillTest, IntegersFromStream1) {
    polynomial w;
    std::istringstream str("1");
    str >> w;
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(1, w[0]);
}

TEST(FillTest, IntegersFromStream2) {
    polynomial w;
    std::istringstream str("2 1");
    str >> w >> w;
    ASSERT_EQ(1, w.degree());
    ASSERT_EQ(2, w[0]);
    ASSERT_EQ(1, w[1]);
}

TEST(FillTest, IntegersFromStream3) {
    polynomial w;
    std::istringstream str("1 2 3");
    str >> w;
    str >> w;
    str >> w;
    ASSERT_EQ(2, w.degree());
    ASSERT_EQ(1, w[0]);
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(3, w[2]);
}

TEST(FillTest, DoubleFromStream) {
    polynomial w;
    std::istringstream str("1.123456789");
    str >> w;
    ASSERT_EQ(0, w.degree());
    ASSERT_EQ(1.123456789l, w[0]);
}
