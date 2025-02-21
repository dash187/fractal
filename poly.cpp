#include "poly.hpp"
#include <cstring>

Polynomial::Polynomial() : deg(0), coeffs(nullptr), zeros(nullptr) {}

Polynomial::Polynomial(size_t deg, double *coeffs, Complex *zeros)
    : deg(deg), coeffs(new double[deg + 1]), zeros(new Complex[deg]),
      zero_eps(0.001) {
  memcpy(this->coeffs, coeffs, (deg + 1) * sizeof(double));
  memcpy(this->zeros, zeros, deg * sizeof(Complex));
}

Polynomial::~Polynomial() {
  delete[] coeffs;
  delete[] zeros;
}

Complex Polynomial::evalPolynomial(Complex z) {
  Complex res;
  for (size_t k = 0; k <= deg; ++k) {
    res = res + z.pow(k) * coeffs[k];
  }
  return res;
}

Complex Polynomial::evalDerivative(Complex z) {
  Complex res;
  for (size_t k = 0; k < deg; ++k) {
    res = res + z.pow(k) * (coeffs[k + 1] * (k + 1));
  }
  return res;
}

int Polynomial::getZeroIdx(Complex z) {
  for (size_t i = 0; i < deg; i++) {
    Complex delta = (z - zeros[i]);
    if (delta.magnitude() < zero_eps * zero_eps) {
      return static_cast<int>(i);
    }
  }
  return NO_ZERO;
}
