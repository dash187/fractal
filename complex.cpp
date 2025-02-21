#include "complex.hpp"
#include <cmath>
#include <cstdio>

Complex::Complex(double _re, double _im) : _re(_re), _im(_im) {}

Complex Complex::operator+(const Complex &other) const {
  return Complex(_re + other._re, _im + other._im);
}

Complex Complex::operator-(const Complex &other) const {
  return Complex(_re - other._re, _im - other._im);
}

Complex Complex::operator*(const Complex &other) const {
  return Complex(_re * other._re - _im * other._im,
                 _re * other._im + _im * other._re);
}

Complex Complex::operator/(const Complex &other) const {
  double mag = other.magnitude();
  double x = (_re * other._re + _im * other._im) / mag;
  double y = (-_re * other._im + _im * other._re) / mag;
  return {x, y};
}

Complex Complex::pow(size_t exp) const {
  Complex res(1);
  for (size_t i = 0; i < exp; i++) {
    res = res * (*this);
  }
  return res;
}

double Complex::magnitude() const { return _re * _re + _im * _im; }

double Complex::abs() const { return sqrt(magnitude()); }

void Complex::print() const { printf("Complex: %f + %fi\n", _re, _im); }
