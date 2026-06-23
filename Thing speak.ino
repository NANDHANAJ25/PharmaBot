import cv2
import requests

API_KEY = "YOUR_WRITE_API_KEY"
API_KEY_R = "YOUR_WRITE_API_KEY_R"
THINGSPEAK_URL = "https://api.thingspeak.com/update"
detector = cv2.QRCodeDetector()

cap = cv2.VideoCapture(1)

last_data = None

while True:
    ret, frame = cap.read()
    if not ret:
        break

    data, bbox, _ = detector.detectAndDecode(frame)

    if data and data != last_data:
        print("QR Code Data:", data)

        try:

            values = dict(item.split(":") for item in data.split(","))

            P = values.get("P")
            D = values.get("D")
            A = values.get("A")
            N = values.get("N")
            M = values.get("M")

            print("P =", P)
            print("D =", D)
            print("A =", A)
            print("N =", N)
            print("M =", M)

            payload = {
                "api_key": API_KEY,
                "field1": P,
                "field2": D,
                "field3": A,
                "field4": N,
                "field5": M,
            }

            response = requests.get(THINGSPEAK_URL, params=payload)

            if response.status_code == 200:
                print("Data sent to ThingSpeak")
                
            payload = {
                "api_key": API_KEY_R,
                "field1": '1'
            }

            response = requests.get(THINGSPEAK_URL, params=payload)

            if response.status_code == 200:
                print("Data sent to ThingSpeak refreshed")

        except Exception as e:
            print("Error parsing QR data:", e)

        last_data = data

    cv2.imshow("QR Scanner", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
