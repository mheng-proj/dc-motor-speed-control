const int sensor = 2;
volatile unsigned int pulseCount = 0;
unsigned long int amount,now,prev = 0;
const int Holes_per_rev = 20;
const int PWMA = 5;
const int AIN1 = 7;
const int AIN2 = 8;
const int STBY = 4;
unsigned int rate,pwm;
float rpm = 0;


void countPulse(){
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  Serial.print("Enter the rate per minute (multiples of 3): ");
  while (Serial.available() == 0){}
  rate = Serial.parseInt();
  while (rate%3 != 0) {
    Serial.print("Enter the rate per minute (multiples of 3): ");
    while (Serial.available() == 0){}
    rate = Serial.parseInt();
  }
  pwm = 150;
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH); // Enable driver
  pinMode(sensor,INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor),countPulse,FALLING);
  prev = millis();


}

void loop() {

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, pwm);

  now = millis();
  if (now-prev >= 1000){
    noInterrupts();
    amount = pulseCount;
    pulseCount = 0;
    interrupts();
    prev = now;

    rpm = (amount * 60000.0)/(Holes_per_rev * 1000.0);
    Serial.println("Rpm: ");
    Serial.println(rpm);
  if (rpm > rate && pwm > 0){
      pwm -= 1;
    }
  if (rpm < rate && pwm < 255){
      pwm += 1;
    }
  pwm = constrain(pwm,0,255);
  }
}