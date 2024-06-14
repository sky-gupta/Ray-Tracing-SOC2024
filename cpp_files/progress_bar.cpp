#include <iostream>
#include <iomanip>
using namespace std;

void update_progress_bar(double progress) {
    int bar_width = 50; // Width of the progress bar
    cout << "[";
    int pos = bar_width * progress;
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %\r";
    cout.flush();
}

int main(){
    int image_width = 256;
    int image_height = 256;
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        // Calculate progress and update the progress bar
        double progress = double(j) / (image_height - 1);
        update_progress_bar(progress);
        
        for (int i = 0; i < image_width; i++) {
            auto b = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto r = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    // Print the final progress bar indicating completion
    update_progress_bar(1.0);
    cout << "\nDone.\n";
}
