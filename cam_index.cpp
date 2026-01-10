#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    for (int i = 0; i < 6; i++) {
        VideoCapture cap(i, CAP_DSHOW);
        cout << "Index " << i << " opened: " << cap.isOpened() << endl;
        if (cap.isOpened()) cap.release();
    }
    system("pause");
    return 0;
}
