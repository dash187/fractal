#ifndef _FRACTALS_NEWTON_HPP_
#define _FRACTALS_NEWTON_HPP_

#include "complex.hpp"
#include "image.hpp"
#include "poly.hpp"

class NewtonFractal {
public:
  NewtonFractal(size_t width, size_t height, Polynomial &poly);

  void createFractal(int re_min, int re_max, int im_min, int im_max,
                     int max_iterations);
  void save(const char *path);

public: // EDIT LATER
  Complex oneNewtonIteration(const Complex &z);
  void findZero(int x, int y, Complex z, int max_iterations);
  void setColor(int x, int y, int zero, int iterations, int max_iterations);

private:
  Image img;
  Polynomial &poly;
};

#endif
