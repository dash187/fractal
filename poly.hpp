#ifndef _FRACTALS_POLYNOMIAL_HPP_
#define _FRACTALS_POLYNOMIAL_HPP_

#include "complex.hpp"
#include <cstddef>

class Polynomial {
public:
  static constexpr int NO_ZERO{-1};

public:
  Polynomial();
  Polynomial(size_t deg, double *coeffs, Complex *zeros);
  ~Polynomial();

  Complex evalPolynomial(Complex z);
  Complex evalDerivative(Complex z);

  // Returns the idx of a zero, if z is close to that zero.
  // Otherwise `NO_ZERO` is returned.
  int getZeroIdx(Complex z);

private:
  size_t deg;
  double *coeffs;
  Complex *zeros;

  double zero_eps;
};

#endif
