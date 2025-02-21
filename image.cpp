#include "image.hpp"
#include <cstdio>

Image::Image(size_t width, size_t height)
    : pixels(new Color[width * height]), width(width), height(height) {}

Image::~Image() { delete[] pixels; }

void Image::setPixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b) {
  if (x >= width || y >= height)
    return;
  Color &pixelData = pixels[x + width * y];
  pixelData.r = r;
  pixelData.g = g;
  pixelData.b = b;
}

void Image::fill(uint8_t r, uint8_t g, uint8_t b) {
  for (size_t i = 0; i < width * height; i++) {
    pixels[i].r = r;
    pixels[i].g = g;
    pixels[i].b = b;
  }
}

void Image::saveAsPPM(const char *path) const {
  FILE *fp = fopen(path, "wb");
  if (!fp)
    return;
  fprintf(fp, "P6\n%zu %zu\n255\n", width, height);

  for (size_t i = 0; i < width * height; i++) {
    uint8_t color_arr[3] = {pixels[i].r, pixels[i].g, pixels[i].b};
    fwrite(color_arr, 1, sizeof(color_arr), fp);
  }

  fclose(fp);
}

size_t Image::getWidth() const { return width; }
size_t Image::getHeight() const { return height; }

void Image::createSample() {
  Image img(255, 255);
  for (size_t x = 0; x < 255; x++) {
    for (size_t y = 0; y < 255; y++) {
      img.setPixel(x, y, x & 0xff, y & 0xff, 0);
    }
  }
  img.saveAsPPM("sample.ppm");
}
