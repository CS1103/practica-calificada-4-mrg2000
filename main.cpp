#include "Includes.h"
#include "Image.h"


int main()
{
    unsigned int w;
    unsigned int h;


    auto imageR = decode("../in.png", w, h);
    color_filter(imageR, w, h, 'r');
    encode("../red_filter.png", imageR, w, h);

    auto imageB = decode("../in.png", w, h);
    color_filter(imageB, w, h, 'b');
    encode("../blue_filter.png", imageB, w, h);

    auto imageG = decode("../in.png", w, h);
    color_filter(imageG, w, h, 'g');
    encode("../green_filter.png", imageG, w, h);


    auto imageRotated = decode("../in.png", w, h);
    vector<unsigned char> img = rotated_image(imageRotated, w, h);
    encode("../rotated.png", img, w, h);






    return 0;
}

