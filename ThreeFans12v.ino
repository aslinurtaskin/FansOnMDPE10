#include <IRremote.h> // Include the IRremote library

// Define the pin connections for the fans (assuming PWM control)
const int backFanPin = 5;   // Pin connected to the back fan
const int leftFanPin = 18;  // Pin connected to the left fan
const int rightFanPin = 19; // Pin connected to the right fan

// IR Receiver pin
const int irReceiverPin = 15; // Pin connected to the IR receiver

IRrecv irrecv(irReceiverPin); // Initialize the IR receiver
decode_results results;       // Variable to store the decoded IR signals

// Define the remote button codes (you will need to replace these with your actual button codes)
const long allOnCode = 0xFF30CF;        // Replace with your button code for "All On"
const long allMediumCode = 0xFF18E7;    // Replace with your button code for "All Medium"
const long backFanCode = 0xFF7A85;      // Replace with your button code for "Back Fan"
const long leftFanCode = 0xFF10EF;      // Replace with your button code for "Left Fan"
const long rightFanCode = 0xFF38C7;     // Replace with your button code for "Right Fan"
const long allOffCode = 0xFF42BD;       // Replace with your button code for "All Off"

// Fan speed settings (adjust PWM values according to your needs)
const int fullSpeed = 255;    // Max PWM value (full speed)
const int mediumSpeed = 128;  // Medium speed

void setup() {
  // Set fan pins as output
  pinMode(backFanPin, OUTPUT);
  pinMode(leftFanPin, OUTPUT);
  pinMode(rightFanPin, OUTPUT);

  // Start with all fans off
  analogWrite(backFanPin, 0);
  analogWrite(leftFanPin, 0);
  analogWrite(rightFanPin, 0);

  // Initialize the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    long code = results.value;

    if (code == allOnCode) {
      // Turn all fans on at full speed
      analogWrite(backFanPin, fullSpeed);
      analogWrite(leftFanPin, fullSpeed);
      analogWrite(rightFanPin, fullSpeed);
    } 
    else if (code == allMediumCode) {
      // Set all fans to medium speed
      analogWrite(backFanPin, mediumSpeed);
      analogWrite(leftFanPin, mediumSpeed);
      analogWrite(rightFanPin, mediumSpeed);
    } 
    else if (code == backFanCode) {
      // Only back fan on
      analogWrite(backFanPin, fullSpeed);
      analogWrite(leftFanPin, 0);
      analogWrite(rightFanPin, 0);
    } 
    else if (code == leftFanCode) {
      // Only left fan on
      analogWrite(backFanPin, 0);
      analogWrite(leftFanPin, fullSpeed);
      analogWrite(rightFanPin, 0);
    } 
    else if (code == rightFanCode) {
      // Only right fan on
      analogWrite(backFanPin, 0);
      analogWrite(leftFanPin, 0);
      analogWrite(rightFanPin, fullSpeed);
    } 
    else if (code == allOffCode) {
      // Turn all fans off
      analogWrite(backFanPin, 0);
      analogWrite(leftFanPin, 0);
      analogWrite(rightFanPin, 0);
    }

    irrecv.resume(); // Receive the next IR code
  }
}
