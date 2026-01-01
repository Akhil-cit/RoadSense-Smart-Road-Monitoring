RoadSense - Smart Road Monitoring System

RoadSense is a real-time, camera-based road damage detection system developed using OpenCV in C++.
The system detects road surface damage such as potholes using a live camera feed and optionally visualizes detected locations on Google Maps.

This project is designed for hackathons with a focus on simplicity, real-world impact, and secure public submission.


Problem Statement

Road maintenance currently relies on manual inspection which is:
- Time-consuming
- Expensive
- Prone to human error

There is a need for an automated, scalable, and real-time solution.


Solution Overview

RoadSense automates road damage detection by:
- Using a live camera feed
- Processing road regions using computer vision
- Detecting anomalies like potholes
- Assigning severity scores
- Preparing location-based reports
- Optionally visualizing detections on a map


System Workflow

1. Camera captures live video feed
2. Bottom portion of the frame is selected as road region
3. Image processing is applied (grayscale, blur, edge detection)
4. Damage score is calculated
5. If score exceeds threshold:
   - Damage is confirmed
   - Location data is prepared
6. Map visualization runs only if API key is available


Features

- Live camera-based detection
- Real-time processing using OpenCV
- Lightweight and fast execution
- Simulated GPS coordinates for demo
- Optional Google Maps visualization
- No mandatory cloud or API dependency
- Fully offline detection support


Google Maps Integration (Optional)

- Detected damage locations can be displayed as markers on Google Maps
- Map visualization works only if a valid Google Maps API key is added
- If no API key is provided:
  - Detection continues normally
  - Map step is skipped safely
  - No errors or crashes occur

This ensures the project is safe for GitHub and hackathon submissions.


API Key & Security Considerations

- No API keys are hardcoded in the source code
- No sensitive credentials are committed to GitHub
- Google Maps usage is optional and configurable
- Suitable for public repositories and hackathon evaluations


How to Run the Project

Step 1: Compile the Code

Use the following command in PowerShell:

g++ road_sense.cpp -o road_sense -I"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include" -L"C:\opencv-mingw\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\lib" -lopencv_core455 -lopencv_imgproc455 -lopencv_highgui455 -lopencv_videoio455


Step 2: Run Live Detection

Run the executable:

road_sense.exe

This will:
- Open the live camera
- Detect road damage in real time
- Display detection results


Step 3: Visualize on Map (Optional)

- Open the file map.html in a browser
- Add Google Maps API key only if available
- If API key is not added, skip this step safely


Why RoadSense is Hackathon-Ready

- Fully working end-to-end prototype
- No paid services required
- Easy to demonstrate and explain
- Secure public GitHub submission
- Strong real-world civic impact


Future Enhancements

- AI-based pothole classification
- Automatic email alerts to authorities
- Cloud-based reporting dashboard
- Mobile app integration
- Vertex AI model training
