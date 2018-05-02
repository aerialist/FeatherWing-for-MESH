
// Pin connections
// MESH <-> Feather
#define AIN A0
#define PWMOUT A5
#define DOUT1 13
#define DOUT2 12
#define DOUT3 11
#define DIN1 10
#define DIN2 6
#define DIN3 5

int dins[] = {DIN1, DIN2, DIN3};
int douts[] = {DOUT1, DOUT2, DOUT3};

void setup() {
  Serial.begin(115200);
  Serial.println("Feather Wing for Sony MESH");
  
  // set pin mode of Feather
  // Note that pin naming is from MESH's point of view
  // i.e. DIN is Digital Input for MESH which is OUTPUT for Feather
  pinMode(AIN, OUTPUT);
  pinMode(PWMOUT, INPUT);
  pinMode(DOUT1, INPUT);
  pinMode(DOUT2, INPUT);
  pinMode(DOUT3, INPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
  pinMode(DIN3, OUTPUT);
  
  digitalWrite(DIN1, HIGH);
  digitalWrite(DIN2, HIGH);
  digitalWrite(DIN3, HIGH);

  //test_din();
}

void loop() {
  // uncomment each lines to test
  // test_din();
  // test_dout();  
  // test_pwmout();
  // test_ain();
}

void test_ain(void){
  for(int i=0; i<255; i++){
    analogWrite(AIN, i);
    Serial.println(i);
    delay(30);
  }
  for(int i=255; i<0; i--){
    analogWrite(AIN, i);
    Serial.println(i);
    delay(30);
  }
}

void test_pwmout(void){
  digitalWrite(DIN1, LOW);
  for (int i=0; i<10; i++){
    unsigned long duration = pulseIn(PWMOUT, HIGH);
    Serial.println(duration);
    delay(1000);  
  }
  digitalWrite(DIN1, HIGH);
  delay(5000);
}

void test_dout(void){
  for(int i=0; i<3; i++){
    digitalWrite(dins[i], LOW);
    delay(3000);
    print_dout();
    delay(1000);
    digitalWrite(dins[i], HIGH);
    delay(3000);
    print_dout();
  }
}

void print_dout(void){
  Serial.println("DOUT status");
  for (int i=0; i<3; i++){
    int btn = digitalRead(douts[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(btn);    
  }
}

void test_din(void){
  int delaytime = 3000;

  Serial.println("Going to test DIN");
  for (int i=0; i<3; i++){
    digitalWrite(dins[i], LOW);
    Serial.print(i);
    Serial.println(": LOW");
    delay(delaytime);
    digitalWrite(dins[i], HIGH);
    Serial.print(i);
    Serial.println(": HIGH");
    delay(delaytime);
  }
}

