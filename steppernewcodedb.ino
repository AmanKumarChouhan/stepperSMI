int stepPin = 6;
int dirPin = 5;
int step_mode = 3200; // Steps per revolution
String inputData = "";

void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  
  // Check if data is available in Serial
  if (Serial.available()>0) {
    // Format: 10up100 (rev, dir, delay)
    inputData = Serial.readString();
    float rev = inputData.substring(0, 3).toFloat();
    String dir = inputData.substring(3, 5);
    int del = inputData.substring(5).toInt();
    Serial.println(rev);
    Serial.println(dir);
    Serial.println(del);
    // Set Direction
    if (dir == "up") {
      digitalWrite(dirPin, HIGH);
    } else if (dir == "dn") {
      digitalWrite(dirPin, LOW);
    }
    
    // Run motor for the specified number of steps
    int totalSteps = step_mode * rev;
    for (int i = 0; i < totalSteps; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(del);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(del);
    }   
  }
}

