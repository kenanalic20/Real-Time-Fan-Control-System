#define fanPin 14    
#define MQ135 34  // Assuming MQ135 is connected to Analog pin A0

const int gasThreshold = 1500;
const int fanSpinDuration = 10000;
int sensorVal=0;
volatile bool fanSpinActive = false;
volatile unsigned long fanStartTime = 0;  
hw_timer_t *timer = NULL;

void IRAM_ATTR onTimer() {
  sensorVal = analogRead(MQ135);
  if (sensorVal > gasThreshold) {
    digitalWrite(fanPin, HIGH);
    fanSpinActive = true;
    fanStartTime = millis(); 
  }
}

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(MQ135, INPUT);
  Serial.begin(115200);

  
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true); 
  timerAlarmEnable(timer);
}

void loop() {
 
  if (fanSpinActive) {
    unsigned long currentMillis = millis();
    if (currentMillis - fanStartTime >= fanSpinDuration) {
      digitalWrite(fanPin, LOW);
      fanSpinActive = false;
    }
  }
}
