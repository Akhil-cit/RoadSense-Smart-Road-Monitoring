#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace cv;
using namespace std;

/* ---- GPS (Demo) ---- */
double latitude = 12.9716;
double longitude = 77.5946;

/* ---- DAMAGE DETECTION (UNCHANGED) ---- */
bool detectDamage(Mat &frame, double &score) {

    // Bottom-center road area ONLY
    int x = frame.cols * 0.15;
    int y = frame.rows * 0.55;
    int w = frame.cols * 0.70;
    int h = frame.rows * 0.35;
    Rect roi(x, y, w, h);
    Mat road = frame(roi);

    Mat gray, blurImg, edges;
    cvtColor(road, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurImg, Size(5,5), 0);
    Canny(blurImg, edges, 60, 140);

    double edgeDensity = (double)countNonZero(edges) / edges.total();

    // Dark-region check (potholes are darker)
    Scalar meanIntensity = mean(gray);

    score = edgeDensity;

    return (edgeDensity > 0.010 && meanIntensity[0] < 130);
}

/* ---- SAVE REPORT ---- */
void saveReport(int id, double score) {

    ofstream file("report_" + to_string(id) + ".json");
    time_t now = time(0);

    string ts = ctime(&now);
    ts.pop_back(); // remove newline


    file << "{\n";
    file << "  \"timestamp\": \"" << ts << "\",\n";
    file << "  \"latitude\": " << latitude << ",\n";
    file << "  \"longitude\": " << longitude << ",\n";
    file << "  \"damage_score\": " << score << ",\n";
    file << "  \"status\": \"Pending\"\n";
    file << "}\n";

    file.close();
}

/* ---- MAIN ---- */
int main() {

    cout << "Starting RoadSense (VIDEO MODE ONLY)..." << endl;

    VideoCapture cap("road_demo.mp4");   // 🔒 NO CAMERA

    if (!cap.isOpened()) {
        cout << "ERROR: Video not opened!" << endl;
        return -1;
    }

    Mat frame;
    int reportId = 0;
    bool reported = false;

    while (true) {

        cap >> frame;

        if (frame.empty()) {
            cap.set(CAP_PROP_POS_FRAMES, 0); // loop video
            continue;
        }

        double score = 0.0;
        bool damaged = detectDamage(frame, score);

        string text = damaged ? "DAMAGE DETECTED" : "ROAD NORMAL";
        Scalar color = damaged ? Scalar(0,0,255) : Scalar(0,255,0);

        putText(frame, text, Point(40,50),
                FONT_HERSHEY_SIMPLEX, 1.2, color, 3);

        rectangle(frame,
                  Rect(frame.cols*0.15, frame.rows*0.55,
                       frame.cols*0.70, frame.rows*0.35),
                  Scalar(255,255,0), 2); // show ROI

        imshow("RoadSense - Demo Video", frame);

        // ✅ REPORT LIMIT = 5 (ONLY ADDITION)
        if (damaged && !reported && reportId < 5) {
            saveReport(reportId, score);
            system("python upload_report.py");
            cout << "Report report_" << reportId << ".json created" << endl;
            reported = true;
            reportId++;
        }

        // reset when road becomes normal
        if (!damaged) reported = false;

        if (waitKey(30) == 27) break; // ESC
    }

    cap.release();
    destroyAllWindows();
    return 0;
}