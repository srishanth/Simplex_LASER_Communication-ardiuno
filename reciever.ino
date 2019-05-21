 //receiver
 // Display -> Nokia display
 #include <Adafruit_GFX.h>
 #include <Adafruit_PCD8544.h>

 Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
 
 void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);
  display.begin();
  display.setContrast(50);
  display.clearDisplay();
 }
 
 void testdrawchar(char x,int y,int z) {
  display.setTextSize(1);
  int r=x;
  
  display.setTextColor(BLACK);
  display.setCursor(y,z);
  display.write(x);
  display.write(0);
 }
  
 void loop() {
  lab:int var = 0,c,a[8]= {0},i = 0,low = 300,high = 500,q= 0,x,siz = 18  ;
  char b[60]={};
   c = 8,i = 0;
  while(var < low)
   var = analogRead(A1); 
 delay(30);
 for(int k = 0; k < 60; k++){
  while(c--){
   delay(10);  
   var = analogRead(A1);
   delay(10);
   a[i++] = var;
  }
  x = 1;
  for(int j = 0; j < 8; j++){
   if(a[j] > high)
    b[q] += x;
   x*=2;
  }
  q++; 
  c = 8;
  i = 0; 
 }
 
 
 
 int k =0;
 display.clearDisplay();
 for(int m = 0; m < 5; m++)
  for(int l = 0; l < 12;l++){ 
   testdrawchar(b[k],7*l,10*m);
   display.display();
   Serial.print(b[k++]);
   if(k>60)
    goto lab;
  }
 }

