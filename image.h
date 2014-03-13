using namespace std;
#include <iostream>
#include <cstring>

class image {
    public:
        const char *filename;

        /* init */
        image(const char *file){
            filename = file;
        }

        const char* get_filename();
        int pixel(int x, int y);
};
