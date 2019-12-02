//
// Created by Maor Roizman Gheiler on 1/12/19.
//

#ifndef PC4_IMAGE_H
#define PC4_IMAGE_H

#include "Includes.h"



    vector<unsigned char> rotated_image(vector<unsigned char> image, t_entero height, t_entero width);
    int set_pixel1(char color);
    int set_pixel2(char color);
    void image_set(vector<unsigned char>& image, t_entero height, t_entero partition, t_entero width, char color);
    void color_filter(vector< unsigned char>& image, size_t width, size_t height, char color);



#endif //PC4_IMAGE_H
