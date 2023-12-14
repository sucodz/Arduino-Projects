const int buzzerpin = 9;
const int fireSensorPin = 8;
void setup(){
  Serial.begin(9600);
  pinMode(buzzerpin, OUTPUT);
  pinMode(fireSensorPin, INPUT);
}
void loop(){
  int fireValue = digitalRead(fireSensorPin);
  Serial.println(fireValue);
  if(fireValue == 0){
    digitalWrite(buzzerpin, HIGH);
    delay(2000);
  }else{
    digitalWrite(buzzerpin, LOW);
  }
  delay(200);
}
