import cv2
import serial
import time

# Initialize serial connection to the Arduino
arduino_port = 'COM6'  # Update with your Arduino port (e.g., '/dev/ttyACM0' for Linux)
baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate)

# Function to send commands to Arduino
def send_command(command):
    ser.write(f"{command}\n".encode())

# Initialize webcam
cap = cv2.VideoCapture(0)

# Hand gesture detection (simplified example, requires proper implementation)
def detect_gesture(frame):
    # Convert to grayscale and blur the image
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)

    # Threshold the image to get binary image
    _, thresh = cv2.threshold(blur, 60, 255, cv2.THRESH_BINARY_INV)

    # Find contours
    contours, _ = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    if len(contours) > 0:
        # Find the largest contour
        contour = max(contours, key=cv2.contourArea)

        # Get the bounding box for the largest contour
        x, y, w, h = cv2.boundingRect(contour)

        # Use bounding box size or position to determine the gesture
        if w > h:
            if x < frame.shape[1] // 2:
                return "LEFT"
            else:
                return "RIGHT"
        else:
            if y < frame.shape[0] // 2:
                return "UP"
            else:
                return "DOWN"
    return "NONE"

try:
    print("Starting hand gesture detection...")
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        gesture = detect_gesture(frame)
        if gesture != "NONE":
            print(f"Gesture {gesture} detected")
            send_command(gesture)

        cv2.imshow('Frame', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
except KeyboardInterrupt:
    print("Program interrupted by user")
finally:
    ser.close()
    cap.release()
    cv2.destroyAllWindows()
    print("Program ended")
