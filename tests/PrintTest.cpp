#include <gtest/gtest.h>
#include "polynomial.hpp"

TEST(PrintTest, BasicPrint) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    ASSERT_STREQ("3x^2 + 2x + 1", w.print().c_str());
}

TEST(PrintTest, BasicPrintWith0atEnd) {
    polynomial w;
    w << 0 << 2 << 3;//w = 3x^2 + 2x
    ASSERT_STREQ("3x^2 + 2x", w.print().c_str());
}

TEST(PrintTest, BasicPrintWith0atBegining) {
    polynomial w;
    w << 1 << 2 << 0;//w = 2x + 1
    ASSERT_STREQ("2x + 1", w.print().c_str());
}

TEST(PrintTest, BasicPrintWith0inside) {
    polynomial w;
    w << 1 << 0 << 3;//w = 3x^2 + 1
    ASSERT_STREQ("3x^2 + 1", w.print().c_str());
}

TEST(PrintTest, NegativePrint) {
    polynomial w;
    w << -1 << -2 << -3;//w = -3x^2 - 2x - 1
    ASSERT_STREQ("-3x^2 - 2x - 1", w.print().c_str());
}

TEST(PrintTest, NegativePrintWith0atEnd) {
    polynomial w;
    w << 0 << -2 << -3;//w = -3x^2 - 2x
    ASSERT_STREQ("-3x^2 - 2x", w.print().c_str());
}

TEST(PrintTest, NegativePrintWith0inside) {
    polynomial w;
    w << -1 << 0 << -3;//w = -3x^2 - 1
    ASSERT_STREQ("-3x^2 - 1", w.print().c_str());
}

TEST(PrintTest, HorizontalVectorPrint) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    ASSERT_STREQ("[ 3 2 1 ]", w.printHorizontalVector(0).c_str());
}

TEST(PrintTest, PreciseHorizontalVectorPrint) {
    polynomial w(1.123456789, 0.123456789);
    ASSERT_STREQ("[ 1.123457 0.1234568 ]", w.printHorizontalVector(7).c_str());
}

TEST(PrintTest, NegativeHorizontalVectorPrint) {
    polynomial w;
    w << -1 << -2 << -3;//w = -3x^2 - 2x - 1
    ASSERT_STREQ("[ -3 -2 -1 ]", w.printHorizontalVector(0).c_str());
}

TEST(PrintTest, HorizontalVectorPrintWith0atEnd) {
    polynomial w;
    w << 0 << 2 << 3;//w = 3x^2 + 2x
    ASSERT_STREQ("[ 3 2 0 ]", w.printHorizontalVector(0).c_str());
}

TEST(PrintTest, HorizontalVectorPrintWith0inside) {
    polynomial w;
    w << 1 << 0 << 3;//w = 3x^2 + 1
    ASSERT_STREQ("[ 3 0 1 ]", w.printHorizontalVector(0).c_str());
}

TEST(PrintTest, VerticalVectorPrint) {
    polynomial w;
    w << 1 << 2 << 3;//w = 3x^2 + 2x + 1
    ASSERT_STREQ("[\n3\n2\n1\n]", w.printVerticalVector(0).c_str());
}

TEST(PrintTest, NegativeVerticalVectorPrint) {
    polynomial w;
    w << -1 << -2 << -3;//w = -3x^2 - 2x - 1
    ASSERT_STREQ("[\n-3\n-2\n-1\n]", w.printVerticalVector(0).c_str());
}

TEST(PrintTest, VerticalVectorPrintWith0atEnd) {
    polynomial w;
    w << 0 << 2 << 3;//w = 3x^2 + 2x
    ASSERT_STREQ("[\n3\n2\n0\n]", w.printVerticalVector(0).c_str());
}

TEST(PrintTest, VerticalVectorPrintWith0inside) {
    polynomial w;
    w << 1 << 0 << 3;//w = 3x^2 + 1
    ASSERT_STREQ("[\n3\n0\n1\n]", w.printVerticalVector(0).c_str());
}

TEST(PrintTest, PreciseVerticalVectorPrint) {
    polynomial w(1.123456789, 0.123456789);
    ASSERT_STREQ("[\n1.123457\n0.1234568\n]", w.printVerticalVector(7).c_str());
}
