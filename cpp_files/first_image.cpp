#include<iostream>
using namespace std;
int main(){
    int image_width = 256;
    int image_height = 256;
    for (int j = 0; j < image_height; j++) {
    	clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
        for (int i = 0; i < image_width; i++) {
            auto b = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto r = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}