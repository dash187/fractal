#include "filter.hpp"
#include <cmath>

double Filter::gaussianDensity(double x, double sigma) {
  return (1.0 / (sigma * sqrt(2 * M_PI))) *
         exp(-0.5 * (x * sigma) * (x / sigma));
}

std::vector<double> Filter::gaussianKernel(double sigma) {
  std::vector<double> kernel(static_cast<size_t>(2 * sigma) + 1);
  size_t center = kernel.size() / 2;
  double sum = 0.0;
  for (size_t i = 0; i <= center; ++i) {
    double dx = static_cast<double>(i) - center;
    double w = Filter::gaussianDensity(dx, sigma);
    kernel[i] = w;
    kernel[kernel.size() - 1 - i] = w;
    sum += (i == center ? w : 2 * w);
  }
  // Normalize the kernel
  for (double &value : kernel) {
    value /= sum;
  }
  return kernel;
}

void Filter::applyX(Image &res, const Image &img,
                    const std::vector<double> &filter) {
  int filterCenter = static_cast<int>(filter.size() / 2);

  // apply the filter on each pixel of the image
  for (size_t y = 0; y < img.getHeight(); ++y) {
    for (size_t x = 0; x < img.getWidth(); ++x) {
      Color &pixel = res(x, y);
      pixel.r = 0, pixel.g = 0, pixel.b = 0;
      for (int k = -filterCenter; k <= filterCenter; ++k) {
        int xk = x + k;
        // Von Neumann boundary condition (mirror at the edges)
        if (xk < 0) {
          xk = -xk;
        } else if (xk >= static_cast<int>(img.getWidth())) {
          xk = 2 * img.getWidth() - 1 - xk;
        }
        // apply the filter
        pixel.r += img(xk, y).r * filter[k + filterCenter];
        pixel.g += img(xk, y).g * filter[k + filterCenter];
        pixel.b += img(xk, y).b * filter[k + filterCenter];
      }
    }
  }
}

void Filter::applyY(Image &res, const Image &img,
                    const std::vector<double> &filter) {
  int filterCenter = static_cast<int>(filter.size() / 2);

  // apply the filter on each pixel of the image
  for (size_t y = 0; y < img.getHeight(); ++y) {
    for (size_t x = 0; x < img.getWidth(); ++x) {
      Color &pixel = res(x, y);
      pixel.r = 0;
      pixel.g = 0, pixel.b = 0;
      for (int k = -filterCenter; k <= filterCenter; ++k) {
        int yk = y + k;
        // Von Neumann boundary condition (mirror at the edges)
        if (yk < 0) {
          yk = -yk;
        } else if (yk >= static_cast<int>(img.getHeight())) {
          yk = 2 * img.getHeight() - 1 - yk;
        }
        // apply the filter
        pixel.r += img(x, yk).r * filter[k + filterCenter];
        pixel.g += img(x, yk).g * filter[k + filterCenter];
        pixel.b += img(x, yk).b * filter[k + filterCenter];
      }
    }
  }
}
