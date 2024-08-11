<h1>Using the <em>SSD1306-OLED</em> to display a bitmap image.</h1>
Resolution is 128×64 pixels, so you will need to edit your image prior to getting its encoding. <br>The bitmap tool I made is not that extensive but does its role.<br>
## Compilation

To compile the `bitmap.cpp` file, use the following command:

```bash
g++ bitmap.cpp -o bit -lfreeimage
