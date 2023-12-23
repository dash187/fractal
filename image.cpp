#include "image.hpp"
#include <cstdio>

Image::Image(size_t width, size_t height) : pixels(new Color[width * height]), width(width), height(height) {}

Image::~Image() { delete pixels; }

void Image::set_pixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b) {
	if(x >= width || y >= height) return;
	Color& pixelData = pixels[x + width * y];
	pixelData.r = r;
	pixelData.g = g;
	pixelData.b = b;
}

void Image::fill(uint8_t r, uint8_t g, uint8_t b) {
	for(size_t i = 0; i < width * height; i++) {
		pixels[i].r = r;
		pixels[i].g = g;
		pixels[i].b = b;
	}
}


void Image::save_as_ppm(const char* path) {
	FILE *fp = fopen(path, "wb");
	if(!fp) return;
	fprintf(fp, "P6\n%zu %zu\n255\n", width, height);

	for(size_t i = 0; i < width * height; i++) {
		uint8_t color_arr[3] = {pixels[i].r, pixels[i].g, pixels[i].b};
		fwrite(color_arr, 1, sizeof(color_arr), fp);
	}

	fclose(fp);	
}
