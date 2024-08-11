# Displaying Bitmap Images on the SSD1306 OLED

The **SSD1306 OLED** is a versatile display module with a resolution of 128×64 pixels, making it ideal for a wide range of applications. Before encoding your images for display, ensure they are edited to fit the resolution constraints. 

While the bitmap tool provided may not offer extensive features, it efficiently serves its purpose of converting images for the SSD1306 OLED.

To compile the `bitmap.cpp` file, execute the following command:

```bash
g++ bitmap.cpp -o bit -lfreeimage
