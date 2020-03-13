const int buzzerPin = 13;
const int pirSensorInput = 12;
const int laserSensor = 11;
const int buttonInput = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(laserSensor, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonInput, INPUT);
  pinMode(pirSensorInput, INPUT);

  Serial.begin(9600);
}


int pirVal = 0; 
int pirState = LOW;
int buttonState = LOW;
boolean laserState = false;

void loop() {
  pirVal = digitalRead(pirSensorInput);
  buttonState = digitalRead(buttonInput);
  if (pirVal == HIGH) {            // check if the input is HIGH
    digitalWrite(buzzerPin, HIGH);
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzerPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }

  if(buttonState == HIGH){
    Serial.println("Button pressed");
   laserState = !laserState;
   Serial.println(laserState);
   delay(400);
  }

  if(laserState){
    digitalWrite(laserSensor, HIGH);
    Serial.println("Laser is on!");
  }else{
    digitalWrite(laserSensor, LOW);
  }

}
