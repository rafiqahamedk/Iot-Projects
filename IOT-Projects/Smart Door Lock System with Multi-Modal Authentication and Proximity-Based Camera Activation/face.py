import cv2
import face_recognition
import serial
import time

# Initialize serial communication with Arduino
ser = serial.Serial('COM3', 9600)  # Adjust 'COM3' to your Arduino port

# Load known faces and their encodings
known_face_encodings = []
known_face_names = []

# Add known faces
def load_known_faces():
    face_files = {
        "Person 1": "face_1.jpg",
        "Person 2": "face_2.jpg",
        # Add more faces if needed
    }

    for name, file_path in face_files.items():
        image = face_recognition.load_image_file(file_path)
        encoding = face_recognition.face_encodings(image)[0]
        known_face_encodings.append(encoding)
        known_face_names.append(name)

load_known_faces()

def open_camera():
    video_capture = cv2.VideoCapture(0)
    global faceMatched

    while True:
        ret, frame = video_capture.read()
        rgb_frame = frame[:, :, ::-1]
        face_locations = face_recognition.face_locations(rgb_frame)
        face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

        faceMatched = False

        for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
            matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
            name = "Unknown"

            if True in matches:
                first_match_index = matches.index(True)
                name = known_face_names[first_match_index]

            if name != "Unknown":
                faceMatched = True
                break

        # Send signal to Arduino based on face match status
        if faceMatched:
            ser.write(b'2')  # Signal indicating face match
        else:
            ser.write(b'0')  # Signal indicating no match

        cv2.imshow('Video', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    video_capture.release()
    cv2.destroyAllWindows()

while True:
    if ser.in_waiting > 0:
        data = ser.read()
        if data == b'1':
            open_camera()
