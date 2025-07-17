#ifndef FILTER_HPP_
#define FILTER_HPP_

#include "image.hpp"
#include <vector>

namespace Filter {
// Applies a 1D filter to the image (useful for seperable filters).
void applyX(Image &res, const Image &img, const std::vector<double> &filter);
void applyY(Image &res, const Image &img, const std::vector<double> &filter);

double gaussianDensity(double x, double sigma);
std::vector<double> gaussianKernel(double sigma);
}; // namespace Filter

#endif // FILTER_HPP_