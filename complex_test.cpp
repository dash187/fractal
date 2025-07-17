#include "complex.hpp"
#include "poly.hpp"
#include <cmath>
#include <gtest/gtest.h>

TEST(ComplexTest, PlusMinus) {
  Complex z1(3, 7);
  Complex z2(-4, 2);

  Complex z3 = z1 + z2;
  EXPECT_DOUBLE_EQ(z3.re(), 3 - 4);
  EXPECT_DOUBLE_EQ(z3.im(), 7 + 2);

  z3 = z2 - z1;
  EXPECT_DOUBLE_EQ(z3.re(), -4 - 3);
  EXPECT_DOUBLE_EQ(z3.im(), 2 - 7);

  z1 = z3 + z1;
  EXPECT_DOUBLE_EQ(z1.re(), -7 + 3);
  EXPECT_DOUBLE_EQ(z1.im(), -5 + 7);
}

TEST(ComplexTest, MultDiv) {
  // trivial cases
  Complex z1(-2, 1);
  z1 = z1 * 1;
  EXPECT_EQ(z1.re(), -2);
  EXPECT_EQ(z1.im(), 1);

  Complex z2 = z1.pow(0);
  EXPECT_EQ(z2.re(), 1);
  EXPECT_EQ(z2.im(), 0);

  // squaring
  Complex z3 = z1 * z1;
  Complex z4 = z1.pow(2);
  EXPECT_DOUBLE_EQ(z3.re(), 4 - 1);
  EXPECT_DOUBLE_EQ(z3.re(), z4.re());
  EXPECT_DOUBLE_EQ(z3.im(), 2 * -2);
  EXPECT_DOUBLE_EQ(z3.im(), z4.im());

  // random mult
  z1 = Complex(2, 3);
  z2 = Complex(5, -1);
  z3 = z1 * z2;
  EXPECT_DOUBLE_EQ(z3.re(), 13);
  EXPECT_DOUBLE_EQ(z3.im(), 13);

  // odd power
  z3 = z1.pow(5);
  EXPECT_DOUBLE_EQ(z3.re(), 122);
  EXPECT_DOUBLE_EQ(z3.im(), -597);

  // division
  z1 = Complex(2.75, 3.25);
  z2 = Complex(1.5, 0.5);
  z3 = z1 / z2;
  EXPECT_DOUBLE_EQ(z3.re(), 2.3);
  EXPECT_DOUBLE_EQ(z3.im(), 1.4);
}

TEST(PolyTest, evalPoly) {
  Polynomial poly({-1, 0, 0, 1}, {Complex(1, 0), Complex(-0.5, sqrt(3) / 2),
                                  Complex(-0.5, -sqrt(3) / 2)});

  Complex z = Complex(1, -2);
  Complex z2 = poly.evalPolynomial(z);

  ASSERT_DOUBLE_EQ(z2.re(), -12);
  ASSERT_DOUBLE_EQ(z2.im(), 2);

  z2 = poly.evalDerivative(z);
  ASSERT_DOUBLE_EQ(z2.re(), -9);
  ASSERT_DOUBLE_EQ(z2.im(), -12);
}

TEST(PolyTest, isZero) {
  Polynomial poly({-1, 0, 0, 1}, {Complex(1, 0), Complex(-0.5, sqrt(3) / 2),
                                  Complex(-0.5, -sqrt(3) / 2)});
  ASSERT_EQ(Polynomial::NO_ZERO, poly.getZeroIdx({1.1, 0}));
  ASSERT_EQ(0, poly.getZeroIdx({0.9999, 0}));
}
