
#ifndef PC4_INCLUDES_H
#define PC4_INCLUDES_H


#include <iostream>
#include <vector>
#include <string_view>
#include <thread>
#include <string>
#include "math.h"
#include "lodepng.h"

using namespace std;
typedef unsigned int t_entero;

std::vector<unsigned char> decode(string_view filename, unsigned int& width, unsigned int& height);
void encode(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

#endif //PC4_INCLUDES_H
