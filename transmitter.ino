//transmitter
void setup() {
 pinMode(11,OUTPUT);  //LASER connected to pin 11
Serial.begin(9600);
}

int a[8] = {0},i,var,k;

void emit(int j){                  //function to convert alphabet into binary byte
  if(j == 1){
    digitalWrite(11,HIGH);
    delay(30);
    }
  else{
    digitalWrite(11,LOW);
    delay(30);
    }
    
  }

void loop() {
  digitalWrite(11,HIGH);
delay(90);
char c[]={"abcdefghijklmnopq"};       //string to be transmitted
for(int j = 0; j < 18; j++){
int y = c[j];
for(i = 0; i < 8; i++){
  var = y % 2;
  a[i] = var;
  y /= 2;
  emit(a[i]);
  delayMicroseconds(3);
   }
  }
  char b[]={"rstuvwxyz"};
for(int j = 0; j < 18; j++){
int y = b[j];
for(i = 0; i < 8; i++){
  var = y % 2;
  a[i] = var;
  y /= 2;
  emit(a[i]);
  delayMicroseconds(3);
  }}
digitalWrite(11,LOW);
while(1);
  Serial.println();
}
