//IN THIS FIRSTLY WE HAVE INTIALISED THE PIN NUMBER OF THE LED
int ledpin = 13;

//IN THIS THE INDEX IS INTITALIZED AT 0
//volatile is mentioned as it can change with teh external factors such as interrupt or hardware interaction
volatile int CURRENT_INDEX = 0;

//PIN NUMBER IS INTIALIZED FOR THE BUTTON
int buttonPin = 2;

//USER NAME
String name = "moulik";

//CREATED THE BOOLEAN STATEMENT
bool is_button_on = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  //DECLARING THE PIN MODE
  pinMode(buttonPin, INPUT_PULLUP);
  //THIS IS THE INBUILT COMMAND USED TO START THE LIGHT FROM THE BEGINING
  //ARDUINO HAS ONLY TWO INTERRRUPT IN 2 AND 3
  //in the interrupt the pin mode is intialiszed the from start to low
  // in this cas if my index is at any number it set to 0 and the is_button_on is set as high then loop fall
  attachInterrupt(digitalPinToInterrupt(buttonPin), start, FALLING);
  //serialbegin is serial monitor help the communication between the arduino and the laptop
  Serial.begin(9600);  // Initialize serial for debugging
}
//this is the start which is called at the event of the interrupt
void start() {
  is_buutton_on = true;
  CURRENT_INDEX = 0;
}

//time after the execution of dash or dot single one
int TIME_OF_DOT = 200;
int TIME_OF_DASH = 600;

void loop() {

  // if user pressed the button then the led is set hih and the loops continue based on the string value
  if (is_buutton_on) {
    Serial.println(name);
    BLINKING_USER_NAME();
    is_buutton_on = false;
  }
}

//this is used to print the name using the string index from 0 to till the n-1
// in the blinkchracter we have to pass the character
// in this  code the name and the index is put which print the chracter afterwards it search the chracter baed on the if loop as if the char matches then it is blink

void BLINKING_USER_NAME() {
  for (CURRENT_INDEX; CURRENT_INDEX < name.length(); CURRENT_INDEX++) {
    BlinkCharacters(name[CURRENT_INDEX]);
    delay(1000);
  }
}

void DOT_BLINKING() {
  digitalWrite(ledpin, HIGH);
  delay(TIME_OF_DOT);
  digitalWrite(ledpin, LOW);
  delay(TIME_OF_DOT);
}

void DASH_BLINKING() {
  digitalWrite(ledpin, HIGH);
  delay(TIME_OF_DASH);
  digitalWrite(ledpin, LOW);
  delay(TIME_OF_DASH);
}

void BlinkCharacters(char current) {
  if (current == 'a') {
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'b') {
    DASH_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'c') {
    DASH_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'd') {
    DASH_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'e') {
    DOT_BLINKING();
  }
  if (current == 'f') {
    DOT_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'g') {
    DASH_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'h') {
    DOT_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'i') {
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'j') {
    DOT_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'k') {
    DASH_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'l') {
    DOT_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'm') {
    DASH_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'n') {
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'o') {
    DASH_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'p') {
    DOT_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 'q') {
    DASH_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'r') {
    DOT_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
  }
  if (current == 's') {
    DOT_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
  if (current == 't') {
    DASH_BLINKING();
  }
  if (current == 'u') {
    DOT_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'v') {
    DOT_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'w') {
    DOT_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'x') {
    DASH_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'y') {
    DASH_BLINKING();
    DOT_BLINKING();
    DASH_BLINKING();
    DASH_BLINKING();
  }
  if (current == 'z') {
    DASH_BLINKING();
    DASH_BLINKING();
    DOT_BLINKING();
    DOT_BLINKING();
  }
}