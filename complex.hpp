#ifndef _FRACTALS_COMPLEX_HPP_
#define _FRACTALS_COMPLEX_HPP_

#include <cstddef>

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0);

  Complex operator+(const Complex &other) const;
  Complex operator-(const Complex &other) const;
  Complex operator*(const Complex &other) const;
  Complex operator/(const Complex &other) const;

  Complex pow(size_t exp) const;
  double magnitude() const;
  double abs() const;

  void print() const;
  double re() const { return _re; }
  double im() const { return _im; }

private:
  double _re;
  double _im;
};

#endif
