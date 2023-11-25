#define fanPin 14    
#define MQ135 34

int sensorVal = 0;
const int gasThreshold = 1500;
const int samplingInterval = 1000;  
const int fanSpinDuration = 10000;  

unsigned long previousMillis = 0;
unsigned long fanStartTime = 0; 
bool fanSpinActive = false;

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(MQ135, INPUT);
  Serial.begin(115200);
}

void fanOff() {
  digitalWrite(fanPin, LOW);
  fanSpinActive = false;
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= samplingInterval) {
    previousMillis = currentMillis;

    sensorVal = analogRead(MQ135);

    if (sensorVal > gasThreshold) {
      digitalWrite(fanPin, HIGH);
      fanSpinActive = true;
      fanStartTime = currentMillis;  
    }
  }

  if (fanSpinActive && currentMillis - fanStartTime >= fanSpinDuration) {
    fanOff();  
  }

  delay(100); 
}
