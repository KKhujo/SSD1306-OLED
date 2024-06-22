#include <iostream>
#include <fstream>
#include <vector>
#include <FreeImage.h>
#include <iomanip> // Include <iomanip> for setfill and setw

void displayBitmapEncoding(const char* filename) {
    // Load image from file
    FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);
    FIBITMAP* image = FreeImage_Load(format, filename, 0);

    if (!image) {
        std::cerr << "Error: Failed to load image: " << filename << std::endl;
        return;
    }

    // Convert image to 24-bit BMP format
    FIBITMAP* convertedImage = FreeImage_ConvertTo24Bits(image);

    // Get image dimensions
    int width = FreeImage_GetWidth(convertedImage);
    int height = FreeImage_GetHeight(convertedImage);

    // Access pixel data
    BYTE* bits = FreeImage_GetBits(convertedImage);

    // Calculate row padding (each row is padded to be a multiple of 4 bytes)
    int padding = (4 - (width * 3) % 4) % 4;

    std::cout << "Bitmap encoding of " << filename << " (in hexadecimal):" << std::endl;

    // Iterate through each pixel row (bottom-up)
    for (int y = height - 1; y >= 0; --y) {
        // Iterate through each pixel in the row
        for (int x = 0; x < width; ++x) {
            // Calculate the index of the current pixel in the pixel data
            int pixelIndex = y * FreeImage_GetPitch(convertedImage) + x * 3;

            // Extract RGB values
            BYTE red = bits[pixelIndex + 2];
            BYTE green = bits[pixelIndex + 1];
            BYTE blue = bits[pixelIndex];

            // Output RGB values in hexadecimal format with proper formatting
            std::cout << std::hex << std::setfill('0') << std::setw(2)
                      << static_cast<int>(red) << std::setw(2)
                      << static_cast<int>(green) << std::setw(2)
                      << static_cast<int>(blue) << " ";
        }
        // Output padding bytes
        for (int p = 0; p < padding; ++p) {
            std::cout << "00 ";
        }
        std::cout << std::endl;
    }

    // Unload images to release memory resources
    FreeImage_Unload(convertedImage);
    FreeImage_Unload(image);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image.png/jpeg>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];

    FreeImage_Initialise();

    displayBitmapEncoding(filename);

    FreeImage_DeInitialise();

    return 0;
}
