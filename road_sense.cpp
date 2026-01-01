#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

/* ---------- Simulated GPS ---------- */
double latitude  = 12.9716;
double longitude = 77.5946;

/* ---------- Damage Detection ---------- */
bool detectDamage(Mat &frame, double &damageScore) {

    // Focus on bottom half (road area)
    Rect roi(0, frame.rows / 2, frame.cols, frame.rows / 2);
    Mat road = frame(roi);

    Mat gray, blurImg, edges;
    cvtColor(road, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurImg, Size(5,5), 0);
    Canny(blurImg, edges, 80, 160);

    damageScore = (double)countNonZero(edges) / edges.total();

    return damageScore > 0.02;   // threshold
}

/* ---------- Store JSON Report ---------- */
void storeReport(int id, double score) {

    ofstream file("report_" + to_string(id) + ".json");

    file << "{\n";
    file << "  \"report_id\": " << id << ",\n";
    file << "  \"latitude\": " << latitude << ",\n";
    file << "  \"longitude\": " << longitude << ",\n";
    file << "  \"damage_score\": " << score << ",\n";
    file << "  \"status\": \"Pending\"\n";
    file << "}\n";

    file.close();
}

/* ---------- MAIN ---------- */
int main() {

    VideoCapture cap(0);  // 👈 CAMERA INPUT

    if (!cap.isOpened()) {
        cout << "❌ ERROR: Camera not accessible" << endl;
        return -1;
    }

    cout << "✅ RoadSense started (Live Camera)" << endl;

    Mat frame;
    int reportId = 0;
    bool reported = false;

    while (true) {

        cap >> frame;
        if (frame.empty()) break;

        double score = 0.0;
        bool damaged = detectDamage(frame, score);

        string text = damaged ? "DAMAGE DETECTED" : "ROAD NORMAL";
        Scalar color = damaged ? Scalar(0,0,255) : Scalar(0,255,0);

        putText(frame, text, Point(30,40),
                FONT_HERSHEY_SIMPLEX, 1, color, 2);

        imshow("RoadSense - Live Road Monitoring", frame);

        if (damaged && !reported) {
            storeReport(reportId, score);
            cout << "📍 Damage detected → report_" 
                 << reportId << ".json created" << endl;
            reported = true;
            reportId++;
        }

        if (waitKey(30) == 27) break;  // ESC
    }

    cap.release();
    destroyAllWindows();

    return 0;
}
