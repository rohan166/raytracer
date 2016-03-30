#include <png.h>
#include <Color.h>
#include <cmath>

// from https://gist.github.com/niw/5963798

void write_png_file(FILE* fp, int width, int height, Color* buf) {
    png_bytepp rows = new unsigned char* [height];

    for (int y = 0; y < height; y++) {
        rows[y] = new unsigned char[width * 4];
        for (int x = 0; x < width; x++) {
            for (int i = 0; i < 3; i++) {
                rows[y][x * 4 + i] = (unsigned char) (buf[y * width + x].components[i]*255);
            }
        }
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();

    png_infop info = png_create_info_struct(png);
    if (!info) abort();

    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png, info);

    png_set_filler(png, 0, PNG_FILLER_AFTER);

    png_write_image(png, rows);
    png_write_end(png, NULL);

    for (int y = 0; y < height; y++) delete rows[y];
    delete rows;
}
