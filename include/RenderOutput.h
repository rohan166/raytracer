#include <Color.h>
#include <Sample.h>
#include <forward_list>
#include <vector>
#include <array>
#include <util.h>
#include <cmath>

extern void write_png_file(FILE* fp, int width, int height, Color* buf);

class SampleList : public std::forward_list<Sample> {
    float max_mag = 0;
    Color total;
    int count = 0;

public:
    void push_front(Sample s) {
        std::forward_list<Sample>::push_front(s);
        count++;
        total += s.color;
        for (int i = 0; i < 3; i++) {
            max_mag = max(max_mag, s.color.components[i]);
        }
    }
    Color average() {
        if (count == 0) return Color(1, 0, 1);
        return total * (1.0 / count);
    }

    int size() { return count; }
    float getMaxMag() { return max_mag; }
};

class RenderOutput {
protected:
    SampleList samples;
public:

    virtual void processSample(Sample& s) { };

    void writeSample(Sample s) {

        samples.push_front(s);
        processSample(s);
    }
};

class StdoutOutput : public RenderOutput {
    void processSample(Sample& s) {
        std::cout << s << "\n";
    }
};


class RasterOutput : public RenderOutput {
protected:
    std::vector<Color> pixels;
    int width, height;
public:
    void rasterize(int width_, int height_) {
        width = width_;
        height = height_;
        std::vector<SampleList> pixel_samples;
        pixel_samples.resize(width * height);
        pixels.resize(width * height);
        for (auto sample : samples) {
            sample.x = trunc(sample.x * width);
            sample.y = trunc(sample.y * height);
            pixel_samples[((int) sample.y * width) + ((int) sample.x)].push_front(sample);
        }

        float max_mag = 0;
        for (auto pixel : pixel_samples) max_mag = max(max_mag, pixel.getMaxMag());
        std::cout << max_mag << "\n";
        for (auto pixel : pixel_samples) {
            if (pixel.empty()) continue;
            pixels[pixel.front().y * width + pixel.front().x] = pixel.average() * (1 / max_mag);
        }
    }
};

class PPMOutput : public RasterOutput {
public:
    void writeFile(FILE* fp) {
        fprintf(fp, "P6\n%d %d\n255\n", width, height);
        for (int i = 0; i < width * height; i++) {
            for (int j = 0; j < 3; j++) {
                fputc((unsigned char) (pixels[i].components[j] * 256), fp);
            }
        }
    }
};

class PNGOutput : public RasterOutput {
public:
    void writeFile(FILE* fp) {
        write_png_file(fp, width, height, pixels.data());
    }
};
