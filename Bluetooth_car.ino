#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX for HC-05

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define ENA 9
#define ENB 10

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    analogWrite(ENA, 150); // Set initial speed (0-255)
    analogWrite(ENB, 150); 

    BT.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (BT.available()) {
        char command = BT.read();
        Serial.println(command);

        switch (command) {
            case 'F': // Forward
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                digitalWrite(IN3, HIGH);
                digitalWrite(IN4, LOW);
                break;
            case 'B': // Backward
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, HIGH);
                break;
            case 'L': // Left
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                digitalWrite(IN3, HIGH);
                digitalWrite(IN4, LOW);
                break;
            case 'R': // Right
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, HIGH);
                break;
            case 'S': // Stop
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, LOW);
                break;
        }
    }
}
