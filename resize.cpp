// Project UID af1f95f547e44c8ea88730dfb185559d

using namespace std;
#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Image.h"
#include "processing.h"

int main(int argc, char *argv[]) {
    string input(argv[1]);
    string output(argv[2]);
    int width(atoi(argv[3]));
    Image* inputImg = new Image;
    ifstream fin;
    fin.open(input);
    if(!fin.is_open()) {
        cout << "Error opening file: " << input << endl;
        return 1;
    }
    Image_init(inputImg, fin);
    fin.close();
    int height;
    if(argc == 4) {
        height = Image_height(inputImg);
    }
    else if(argc == 5) {
        height = (atoi(argv[4]));
    }
    if(4 > argc || argc > 5) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
         << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    else if(width < 0 || width > Image_width(inputImg)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
         << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    else if(height < 0 || height > Image_height(inputImg)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
         << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    seam_carve(inputImg, width, height);
    ofstream fout;
    fout.open(output);
    if(!fout.is_open()) {
        cout << "Error opening file: " << output << endl;
        return 1;
    }
    Image_print(inputImg, fout);
}