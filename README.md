# 🚧 RoadSense – Smart Road Monitoring System

RoadSense is a **real-time camera-based road damage detection system** built using **OpenCV (C++)**. It detects road surface issues like potholes using a live camera feed and optionally visualizes detected locations on **Google Maps**.

This project is designed specifically for **hackathons**, focusing on real-time detection, minimal setup, and secure public deployment.

---

## 🎯 Problem Statement

Manual road inspection is:
1. **Time-consuming:** Requires physical travel across all roads.
2. **Costly:** High labor and equipment costs.
3. **Inaccurate:** Prone to human oversight.

RoadSense automates this process using **computer vision**, helping authorities identify and fix road damage faster.

---

## 💡 Solution Overview

RoadSense provides an end-to-end workflow:
1. **Live Feed:** Captures video from a vehicle-mounted camera.
2. **Analysis:** Processes the road region using OpenCV.
3. **Detection:** Identifies surface anomalies and calculates a damage score.
4. **Reporting:** Generates localized data for every detection.
5. **Visualization:** Maps the data points for easy maintenance planning.

---

## ⚙️ System Workflow

1. **Capture:** The system takes a live video stream.
2. **Region of Interest:** The bottom half of the frame is analyzed (focusing on the road).
3. **Preprocessing:** Grayscale, Gaussian Blur, and Canny Edge detection are applied.
4. **Logic:** The system counts edge density to calculate a "Damage Score."
5. **Detection:** If the score exceeds the threshold:
    - Damage is confirmed.
    - Location data (Latitude/Longitude) is prepared.
6. **Integration:** Results are sent to the map module (if enabled).

---

## ✨ Features

- **Real-time Detection:** Process live frames instantly.
- **Lightweight:** Built in C++ for maximum performance.
- **API-Safe:** No hardcoded keys; works fully offline if needed.
- **Map Ready:** Seamless optional integration with Google Maps.
- **Hackathon Optimized:** Clear logic and easy to demo.

---

## 🗺️ Google Maps Integration (Optional)

Detected road damage locations can be visualized as markers on Google Maps. 

**Note on API Usage:**
- Map visualization works **only if** a valid API key is provided in the configuration.
- **If no API key is present:** Detection continues normally, and the map step is safely skipped.
- This ensures the project is safe for public GitHub repositories.

---

## 🔐 API Key & Security Considerations

- **No Hardcoding:** API keys are never stored directly in the source code.
- **Zero Exposure:** No sensitive credentials are committed to the repository.
- **Configurable:** The system remains functional even without third-party services.

---

## 🚀 How to Run the Project

### 1. Compile the Code
To compile the project on Windows using MinGW, run this command in your terminal:

g++ road_sense.cpp -o road_sense -I"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include" -L"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\lib" -lopencv_core455 -lopencv_imgproc455 -lopencv_highgui455 -lopencv_videoio455

### 2. Run Detection
Execute the generated file:

road_sense.exe

### 3. View Results
- The camera window will open and show real-time detection.
- Detected data will be saved locally.
- Open **map.html** in any browser to see the visualized markers (API key required).

---

## 🏆 Why RoadSense is Hackathon-Ready

- **Working Prototype:** It is a functional, end-to-end system.
- **Scalable:** The logic can be expanded to include AI/ML models (Vertex AI).
- **Civic Impact:** Directly addresses infrastructure maintenance in smart cities.
- **Presentation Clear:** Easy for judges to understand the flow from camera to map.

---

