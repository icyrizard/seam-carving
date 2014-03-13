using namespace std;
#ifdef STDLIBS
#define STDLIBS
#include <iostream>
#endif
#include "image.h"

const char* image::get_filename(){
    return filename;
}

int image::pixel(int x, int y){
    return x+y;
}
