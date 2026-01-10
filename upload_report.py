import json
import requests

SCRIPT_URL = "https://script.google.com/macros/s/AKfycbyZqDDwLGSYzgSJHqlblxrelLziI7Kvu1I4njUF83DIms08Ysvq5t5bL_yCdLNg9lav/exec"

with open("report_0.json", "r") as f:
    data = json.load(f)

payload = {
    "latitude": data["latitude"],
    "longitude": data["longitude"],
    "priority": "High",
    "status": data["status"],
    "damageDetected": True
}

r = requests.post(SCRIPT_URL, json=payload)

print("Uploaded:", r.text)