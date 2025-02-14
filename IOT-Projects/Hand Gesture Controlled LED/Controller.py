import cv2
import pyfirmata
from cvzone.HandTrackingModule import HandDetector

# Arduino setup
comport = 'COM5'
board = pyfirmata.Arduino(comport)

led_pins = [8, 9, 10, 11, 12]
leds = [board.get_pin(f'd:{pin}:o') for pin in led_pins]

# Hand detector
detector = HandDetector(detectionCon=0.8, maxHands=1)

def control_leds(fingerUp):
    for i in range(5):
        if i < len(fingerUp) and fingerUp[i]:
            leds[i].write(1)
        else:
            leds[i].write(0)

# Webcam setup
cap = cv2.VideoCapture(0)

while True:
    success, img = cap.read()
    if not success:
        break

    # Find the hand and its landmarks
    hands, img = detector.findHands(img)
    
    if hands:
        hand = hands[0]
        fingers = detector.fingersUp(hand)
        control_leds(fingers)

    # Display the image
    cv2.imshow("Image", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Cleanup
cap.release()
cv2.destroyAllWindows()
