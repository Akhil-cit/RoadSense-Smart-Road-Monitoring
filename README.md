# 🚦 RoadSense – Smart Road Damage Monitoring System

RoadSense is a real-time road damage detection system that uses a live camera feed and computer vision to automatically identify road surface issues such as potholes and cracks, generate geo-tagged reports, and visualize affected locations on Google Maps.

This project demonstrates how AI-assisted vision systems can improve road maintenance efficiency and transparency in smart cities.

---

## 🎯 Problem Statement

Road damage is often:
- Detected late
- Reported manually
- Repaired without transparency
- Costly due to delayed intervention

There is no automated, scalable system that continuously monitors road conditions and provides actionable insights to authorities.

---

## 💡 Proposed Solution

RoadSense automates the detection and reporting process by:

1. Capturing live road footage using a camera
2. Detecting road surface damage using OpenCV
3. Geo-tagging detected locations
4. Generating structured damage reports (JSON)
5. Visualizing damage locations on Google Maps
6. Enabling future integration with civic authority workflows

---

## ⚙️ System Workflow

Live Camera Feed
↓
Image Processing (OpenCV)
↓
Road Damage Detection
↓
Geo-tagged JSON Report
↓
Google Maps Visualization


---

## 🚀 Features (Implemented – MVP)

- Live camera-based road monitoring
- Real-time damage detection using OpenCV
- Noise reduction and edge-based analysis
- Damage confidence scoring
- Automatic JSON report generation
- Google Maps visualization (API optional)
- Secure design (no API keys in code)

---

## 🛠️ Technologies Used

### Core Stack
- C++
- OpenCV 4.5.5
- HTML / JavaScript
- JSON

### Google Technologies
- Google Maps JavaScript API (Visualization layer)

---

## 📁 Project Structure

RoadSense-Smart-Road-Monitoring/
│
├── road_sense.cpp # Main detection logic (live camera)
├── camera_test.cpp # Camera verification utility
├── map.html # Google Maps visualization
├── README.md # Project documentation
├── .gitignore

RoadSense-Smart-Road-Monitoring/
│
├── road_sense.cpp # Main detection logic (live camera)
├── camera_test.cpp # Camera verification utility
├── map.html # Google Maps visualization
├── README.md # Project documentation
├── .gitignore



Generated files such as .exe and .json are excluded from version control.

---

## 🧠 Detection Algorithm (Overview)

1. Capture frames from the live camera
2. Focus on the lower half of the frame (road region)
3. Convert frame to grayscale
4. Apply Gaussian blur to remove noise
5. Perform Canny edge detection
6. Compute edge density as a damage score
7. If score exceeds threshold:
   - Damage is detected
   - JSON report is generated

---

## 📍 Sample Damage Report (JSON)

```json
{
  "damage_type": "Pothole",
  "severity": "High",
  "latitude": 12.9716,
  "longitude": 77.5946,
  "status": "Pending"
}

🗺️ Google Maps Integration

Detected road damage is visualized as markers on Google Maps

Map visualization works only if a valid API key is provided

If no API key is present:

Detection continues normally

Map step is safely skipped

This ensures security and GitHub-safe deployment

🔐 API Key & Security Considerations

No API keys are hardcoded

No sensitive data pushed to GitHub

API usage is optional and configurable

Suitable for public hackathon submissions

▶️ How to Run the Project
Compile the Code

g++ road_sense.cpp -o road_sense ^
-I"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include" ^
-L"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\lib" ^
-lopencv_core455 -lopencv_imgproc455 -lopencv_highgui455 -lopencv_videoio455

Run Live Detection
road_sense.exe

Opens live camera

Detects road damage

Generates geo-tagged JSON report

Visualize on Map (Optional)

Open map.html in a browser.

Add a Google Maps API key if available to visualize detected locations

🎥 Demo Explanation

Live camera detection shown

Real-time damage detection

Automatic report generation

Map-based visualization

End-to-end system flow explanation

🔮 Future Enhancements

Vertex AI model for advanced damage classification

Firebase/Firestore for cloud-based reporting

Automatic email alerts to authorities

Repair status tracking dashboard

Mobile app integration

🏁 Conclusion

RoadSense demonstrates a practical and scalable approach to smart road monitoring using computer vision and Google Maps.
The system is modular, secure, and designed for real-world deployment in smart city environments.
