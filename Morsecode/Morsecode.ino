
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// THIS IS IN BUILT LED CODE NOW LETS MAKE THE MORSE CODE OF OUR NAME
//MY NAME IS MOULIK-
//SO MORSE CODE FOR TIT IS 
//M-> --
//O->---
//U->..-
//L->.-..
//I->..
///K->-.-


void loop() {
  
  //for M- --
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);
  //this below delay is for those if -- apper together 
  digitalWrite(LED_BUILTIN,LOW);
  delay(50);
  //second dash
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  //for O
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);
  //this below delay is for those if -- apper together 
  digitalWrite(LED_BUILTIN,LOW);
  delay(50);
  //second dash
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

 //this below delay is for those if -- apper together 
  digitalWrite(LED_BUILTIN,LOW);
  delay(50);
  //second dash
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

// U

  digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(50);


  digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

//L
 digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

 digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

 digitalWrite(LED_BUILTIN,LOW);
 delay(2000);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(50);

   digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(50);

//I
 digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(50);

 digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(50);

//K

 digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

 digitalWrite(LED_BUILTIN,LOW);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);

  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(50);


}

