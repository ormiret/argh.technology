const int outPin = 12;
const int ledPin = 13;
int outState = LOW; 
int ledState = LOW;
int val = 0x0F;

void setup() {
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
}

void one() {
  digitalWrite(outPin, HIGH);
  delayMicroseconds(606);
  digitalWrite(outPin, LOW);
  delayMicroseconds(1634);
}

void zero() {
  digitalWrite(outPin, HIGH);
  delayMicroseconds(606);
  digitalWrite(outPin, LOW);
  delayMicroseconds(567);
}

void send16() {
  int mask;
  int i = 15;
  while(i >= 0) {
    mask = 1 << i;
    if(mask & val)
      one();
    else
      zero();
    i--;
  }
}  
void loop() {
  digitalWrite(ledPin, HIGH);
  // header
  digitalWrite(outPin, HIGH);
  delayMicroseconds(9181);
  digitalWrite(outPin, LOW);
  delayMicroseconds(4470);
  // predata
  val = 0x00F7;
  send16();
  // real data
  val = 0x40BF; //off
  send16();
  // trail
  digitalWrite(outPin, HIGH);
  delayMicroseconds(619);
  digitalWrite(outPin, LOW);
  delay(108); // this one is too long for delayMicroseconds
  digitalWrite(ledPin, LOW);
  Serial.println();
  delay(4000);
}
