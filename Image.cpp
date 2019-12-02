//
// Created by Maor Roizman Gheiler on 1/12/19.
//

#include "Image.h"
#include "Includes.h"


vector<unsigned char> rotated_image(vector<unsigned char> image, t_entero height, t_entero width){
    vector<unsigned char> imageRot = image;
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width * 4; j += 4) {
                imageRot[i*width*4+j+0] = image[i * width * 4 + j + 0];
                imageRot[i*width*4+j+1] = image[i * width * 4 + j + 1];
                imageRot[i*width*4+j+2] = image[i * width * 4 + j + 2];
                imageRot[i*width*4+j+3] = image[i * width * 4 + j + 3];
            }
        }
    return imageRot;
};


int set_pixel1(char color){
    int pixel1 = 0;

    if(color == 'r'){
        pixel1 = 1;
    }

    else if(color == 'g'){
        pixel1 = 0;
    }

    else if(color == 'b'){
        pixel1 = 0;
    }
    return pixel1;
}

int set_pixel2(char color){
    int pixel2 = 0;

    if(color == 'r'){
        pixel2 = 2;
    }

    else if(color == 'g'){
        pixel2 = 2;
    }

    else if(color == 'b'){
        pixel2 = 1;
    }
    return pixel2;
}


void color_set(vector<unsigned char>& image, t_entero height, t_entero partition, t_entero width, char color){
    int pixel1 = set_pixel1(color);
    int pixel2 = set_pixel2(color);


    for (size_t i = height; i < partition; i++) {
        for (size_t j = 0; j < width * 4; j += 4) {
            image[i*width*4+j+pixel1] = 0;
            image[i*width*4+j+pixel2] = 0;
        }
    }
}

void color_filter(vector< unsigned char>& image, size_t width, size_t height, char color){
    size_t first_size = height/4;
    size_t second_size = height/2;
    size_t third_size = height*3/4;

    thread t1(color_set, ref(image), 0, first_size, width, color);
    thread t2(color_set, ref(image), first_size, second_size, width, color);
    thread t3(color_set, ref(image), second_size, third_size,width, color);
    thread t4(color_set, ref(image), third_size, height, width, color);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

