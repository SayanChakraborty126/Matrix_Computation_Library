int i=0;
float f=0.3366456;
void setup() {
Serial.begin(9600);
Serial.println(f,4);
}

void loop() {
  
    String s="enter ";
     String s1= "st value";
     String s2 = s+i+s1;
     Serial.println(s+i+s1);
     while(Serial.available()==0){}
    String str1=Serial.readString() ;
    double x =str1.toFloat();
    /*while(Serial.available()==0){}
    String str2=Serial.readString() ;
     String str3=str1+str2;*/
   
  
    
}
