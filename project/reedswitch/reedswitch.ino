int reedswitch=7;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(reedswitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState = digitalRead(reedswitch);
  if(switchState==0){
  Serial.println("doorOpen");
  }
  else{
    Serial.println("Door Closed");
  }
  delay(1);
}
