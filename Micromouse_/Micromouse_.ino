
int MotorLogic1 = 3;
int MotorLogic2 = 4;
int MotorLogic3 = 5;
int MotorLogic4 = 6;
int motorSpeed1 = 255;
int motorSpeed2 = 255;

int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;

int sensorReading1;
int sensorReading2;
int sensorReading3;
int sensorReading4;

void forward(){
  analogWrite(MotorLogic1, motorSpeed1);
  digitalWrite(MotorLogic2, LOW);
  analogWrite(MotorLogic3, motorSpeed2);
  digitalWrite(MotorLogic4, LOW);
}
void halt(){
  analogWrite(MotorLogic1, 0);
  digitalWrite(MotorLogic2, LOW);
  analogWrite(MotorLogic3, 0);
  digitalWrite(MotorLogic4, LOW);
}

void turnRight(){
  analogWrite(MotorLogic1, motorSpeed1);
  analogWrite(MotorLogic2, 0);
  analogWrite(MotorLogic3, 0);
  analogWrite(MotorLogic4, motorSpeed1); 
}

void turnLeft(){
  analogWrite(MotorLogic1, 0);
  analogWrite(MotorLogic2, motorSpeed1);
  analogWrite(MotorLogic3, motorSpeed1);
  analogWrite(MotorLogic4, 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(MotorLogic1, OUTPUT);
  pinMode(MotorLogic2, OUTPUT);
  pinMode(MotorLogic3, OUTPUT);
  pinMode(MotorLogic4, OUTPUT);
  
}

void loop() {
  sensorReading1 = analogRead(sensor1);
  sensorReading2 = analogRead(sensor2);
  sensorReading3 = analogRead(sensor3);
  sensorReading4 = analogRead(sensor4);
  Serial.print("Sensor Reading: ");
  Serial.println(sensorReading1);
  Serial.println();
  Serial.println(sensorReading2);
  Serial.println();
  Serial.println(sensorReading3);
  Serial.println();
  Serial.println(sensorReading4);
  Serial.println();
  delay(500);

  if (sensorReading1 < 800 && sensorReading2 < 800 && sensorReading3 < 800 && sensorReading4 < 800)
  {
  forward();
  }

 
}

