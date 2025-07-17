#include "poly.hpp"

Polynomial::Polynomial(size_t degree)
    : coefficients(degree + 1), zeros(degree) {}

Complex Polynomial::evalPolynomial(Complex z) {
  Complex res;
  for (size_t k = 0; k <= getDegree(); ++k) {
    res = res + z.pow(k) * coefficients[k];
  }
  return res;
}

Complex Polynomial::evalDerivative(Complex z) {
  Complex res;
  for (size_t k = 0; k < getDegree(); ++k) {
    res = res + z.pow(k) * (coefficients[k + 1] * (k + 1));
  }
  return res;
}

int Polynomial::getZeroIdx(Complex z, double zero_eps) {
  for (size_t i = 0; i < getDegree(); i++) {
    Complex delta = (z - zeros[i]);
    if (delta.magnitude() < zero_eps * zero_eps) {
      return static_cast<int>(i);
    }
  }
  return Polynomial::NO_ZERO;
}