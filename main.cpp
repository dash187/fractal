#include "image.hpp"
#include "newton_fractal.hpp"
#include <cmath>

int main() {
  size_t degree = 3;
  double coeffs[4] = {-1, 0, 0, 1};
  Complex zeros[3] = {
      {1, 0}, {-0.5, +std::sqrt(3) / 2}, {-0.5, -std::sqrt(3) / 2}};
  Polynomial poly(degree, coeffs, zeros);

  NewtonFractal frac(1000, 1000, poly);
  frac.createFractal(-2, 2, -2, 2, 20);
  frac.save("out.ppm");
}
