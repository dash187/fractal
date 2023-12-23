#include <cstdint>
#include <cstddef>

class Color {
	public:
		Color() = default;
		uint8_t r, g, b;
};

class Image {
	public:
		Image(size_t width, size_t height);
		~Image();

		void set_pixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b);
		void fill(uint8_t r, uint8_t g, uint8_t b);
		void save_as_ppm(const char* path);

		int get_width();
		int get_height();
	private:
		Color* pixels;
		size_t width, height;
};
