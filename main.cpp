#include "filter.hpp"
#include "image.hpp"
#include "newton_fractal.hpp"
#include <cmath>
#include <cstdio>

int main() {
  Polynomial poly({-1, 0, 0, 1},
                  {Complex(1, 0), Complex(-0.5, +std::sqrt(3) / 2),
                   Complex(-0.5, -std::sqrt(3) / 2)});

  NewtonFractal frac(1000, 1000, poly);
  Image &fractalImage = frac.createFractal(-2, 2, -2, 2, 20);

  Image filteredX(fractalImage.getWidth(), fractalImage.getHeight());
  Image filteredXY(fractalImage.getWidth(), fractalImage.getHeight());
  std::vector<double> filter = Filter::gaussianKernel(10.0);
  Filter::applyX(filteredX, fractalImage, filter);
  Filter::applyY(filteredXY, filteredX, filter);

  fractalImage.saveAsPPM("original.ppm");
  filteredXY.saveAsPPM("filtered.ppm");
}
