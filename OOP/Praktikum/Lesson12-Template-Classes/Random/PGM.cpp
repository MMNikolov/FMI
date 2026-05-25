#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Struct containing RGB values
struct RGB {
    unsigned r;
    unsigned g;
    unsigned b;
};

// Abstract base class
class Image {
protected:
    int width;
    int height;
    std::vector<RGB> pixels; // Flat array for cache efficiency

public:
    Image(int w, int h) : width(w), height(h) {
        pixels.resize(width * height, {255, 255, 255});
    }

    // Virtual destructor for safe polymorphic deletion
    virtual ~Image() = default;

    void setPixel(int x, int y, const RGB& color) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[y * width + x] = color;
        }
    }

    // Pure virtual function makes Image an abstract class
    virtual void save(const std::string& filename) const = 0;
};

// Derived PBM class
class PBM : public Image {
public:
    PBM(int w, int h) : Image(w, h) {}

    void save(const std::string& filename) const override {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error: Could not open file for writing.\n";
            return;
        }

        // P1 is the magic number for ASCII PBM (monochrome)
        file << "P1\n";
        file << width << " " << height << "\n";

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                const RGB& p = pixels[y * width + x];
                
                // Convert RGB to grayscale
                int gray = (p.r + p.g + p.b) / 3;
                
                // Threshold to 0 (white) or 1 (black) for standard PBM
                file << (gray < 128 ? "1 " : "0 ");
            }
            file << "\n";
        }
    }
};

int main() {
    PBM myImage(10, 10);

    // Draw an 'X' using black pixels {0, 0, 0}
    for (int i = 0; i < 10; ++i) {
        myImage.setPixel(i, i, {0, 0, 0});           // Top-left to bottom-right
        myImage.setPixel(i, 9 - i, {0, 0, 0});       // Top-right to bottom-left
    }

    myImage.save("output.pbm");
    return 0;
}