#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "Camera not opening" << endl;
        return -1;
    }

    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow("Camera Test", frame);
        if (waitKey(30) == 27) break; // ESC
    }

    return 0;
}
