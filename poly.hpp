#ifndef _FRACTALS_POLYNOMIAL_HPP_
#define _FRACTALS_POLYNOMIAL_HPP_

#include "complex.hpp"
#include <cstddef>
#include <vector>

struct Polynomial {
  static constexpr int NO_ZERO{-1};

  // allocates enough space for a polynomial a certain degree
  Polynomial(size_t degree);
  Polynomial(std::initializer_list<double> coeffs,
             std::initializer_list<Complex> zs);

  size_t getDegree() const { return zeros.size(); }

  Complex evalPolynomial(Complex z);
  Complex evalDerivative(Complex z);

  // Returns the idx of a zero, if z is close to that zero.
  // Otherwise `NO_ZERO` is returned.
  int getZeroIdx(Complex z, double zero_eps = 0.001);

public:
  std::vector<double> coefficients;
  std::vector<Complex> zeros;
};

#endif
