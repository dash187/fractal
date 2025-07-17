#include "newton_fractal.hpp"

NewtonFractal::NewtonFractal(size_t width, size_t height, Polynomial &poly)
    : img(width, height), poly(poly) {}

Image &NewtonFractal::createFractal(int re_min, int re_max, int im_min,
                                    int im_max, int max_iterations) {
  double re_step = double(re_max - re_min) / double(img.getWidth() - 1);
  double im_step = double(im_max - im_min) / double(img.getHeight() - 1);

  for (size_t py = 0; py < img.getHeight(); ++py) {
    for (size_t px = 0; px < img.getWidth(); ++px) {
      findZero(px, py, {re_min + re_step * px, im_min + im_step * py},
               max_iterations);
    }
  }
  return img;
}

void NewtonFractal::findZero(int x, int y, Complex z, int max_iterations) {
  int i = 0;
  int zero = poly.getZeroIdx(z);

  while (i < max_iterations && zero == Polynomial::NO_ZERO) {
    z = oneNewtonIteration(z);
    zero = poly.getZeroIdx(z);
    i++;
  }
  setColor(x, y, zero, i, max_iterations);
}

void NewtonFractal::setColor(int x, int y, int zero, int iterations,
                             int max_iterations) {
  double rel = 1.0 - double(iterations) / double(max_iterations);
  uint8_t brightness = static_cast<uint8_t>(rel * 0xff);
  switch (zero) {
  case Polynomial::NO_ZERO:
    img.setPixel(x, y, 0, 0, 0);
    break;
  case 0:
    img.setPixel(x, y, brightness, 0, 0);
    break;
  case 1:
    img.setPixel(x, y, 0, brightness, 0);
    break;
  case 2:
    img.setPixel(x, y, 0, 0, brightness);
    break;
  default:
    img.setPixel(x, y, 0xff, 0, 0xff);
  }
}

Complex NewtonFractal::oneNewtonIteration(const Complex &z) {
  return z - (poly.evalPolynomial(z) / poly.evalDerivative(z));
}

void NewtonFractal::save(const char *path) { img.saveAsPPM(path); }
