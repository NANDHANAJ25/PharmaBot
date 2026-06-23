
# 💊 PharmaBot 
Digital Prescription & Contactless Medicine Dispensing System

PharmaBot is an IoT-based healthcare solution that combines digital prescription generation with automated medicine dispensing. The system uses QR code technology, cloud communication, and an ESP32 microcontroller to provide a contactless, accurate, and efficient medicine distribution process.

## 🚀 Features

- 🩺 Secure doctor login system
- 📝 Digital prescription generation
- 👤 Patient information management
- 💊 Medicine dosage and frequency selection
- 💰 Payment status tracking
- 📱 QR code generation and WhatsApp sharing
- 🎥 QR code scanning using a webcam
- ☁️ Cloud communication via ThingSpeak
- 📟 LCD display for medicine details
- ⚙️ Automated medicine dispensing using ESP32 and SG90 servo motors

## 🏗️ System Workflow

```text
Doctor Login
      │
      ▼
Enter Patient Details
      │
      ▼
Generate Prescription & QR Code
      │
      ▼
Send QR via WhatsApp
      │
      ▼
Patient Scans QR Code
      │
      ▼
Python Program (Anaconda)
      │
      ▼
ThingSpeak Cloud
      │
      ▼
ESP32 WROOM
      │
      ├──► LCD Display
      │
      └──► Servo Motors
                 │
                 ▼
        Medicine Dispensing
```

## 🛠️ Technologies Used

### Hardware
- ESP32 WROOM-32
- SG90 Servo Motors
- 16×2 LCD with I2C Module
- LM2596 Buck Converter
- 12V DC Adapter
- Webcam

### Software & Platforms
- XAMPP
- Python (Anaconda)
- Visual Studio Code
- Arduino IDE
- ThingSpeak

## 💊 Medicines Supported

| Code | Medicine |
|------|----------|
| P | Paracetamol |
| A | Aspirin |
| D | Dolo |
| M | Metoprolol |
| N | Naproxen |

Example QR data:

```text
P:1
A:2
D:1
```

## 📂 Project Structure

```text
PharmaBot/
│── Arduino_Code/
│── Python_Code/
│── XAMPP_Web_App/
│── Images/
│── README.md
```

## ⚡ Power Supply

- Input: 12V DC Adapter
- Voltage Regulation: LM2596 Buck Converter
- Operating Voltage: 5V for ESP32, LCD, and Servo Motors

## 🌟 Advantages

- Contactless medicine dispensing
- Reduces human error
- Improves dispensing accuracy
- User-friendly digital prescription system
- IoT-enabled communication
- Hygienic and efficient operation

## 🔮 Future Scope

- Mobile application integration
- Online payment gateway
- AI-based prescription validation
- Support for additional medicines
- Enhanced security features
- Direct communication without cloud dependency

## 📸 Screenshots
<table>
  <tr>
    <td><img src="1.jpeg" width="300"></td>
    <td><img src="2.jpeg" width="300"></td>
  </tr>
  <tr>
    <td><img src="3.jpeg" width="300"></td>
    <td><img src="4.jpeg" width="300"></td>
  </tr>
  <tr>
    <td><img src="5.jpeg" width="300"></td>
    <td><img src="PharmaBot.jpeg" width="300"></td>
  </tr>
</table>

## 👨‍💻 Developed As

An academic IoT and Embedded Systems project demonstrating digital prescription generation and automated medicine dispensing using ESP32, Python, QR technology, and cloud communication.

---


