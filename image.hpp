#ifndef _FRACTALS_IMAGE_HPP_
#define _FRACTALS_IMAGE_HPP_

#include <cstddef>
#include <cstdint>
#include <vector>

class Color {
public:
  Color() = default;
  uint8_t r, g, b;
};

class Image {
public:
  Image(size_t width, size_t height);
  Image(const Image &);

  void setPixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b);
  void fill(uint8_t r, uint8_t g, uint8_t b);

  Color &operator()(size_t x, size_t y);
  const Color &operator()(size_t x, size_t y) const;

  void saveAsPPM(const char *path) const;
  size_t getWidth() const;
  size_t getHeight() const;

  static void createSample();

private:
  std::vector<Color> pixels;
  size_t width, height;
};

#endif
