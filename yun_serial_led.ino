#include <Console.h>

const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {

  // initialize serial communication:

  Bridge.begin();

  Console.begin();

  while (!Console){

    ; // wait for Console port to connect.

  }

  Console.println("You're connected to the Console!!!!");

  // initialize the LED pin as an output:

  pinMode(ledPin, OUTPUT);
}

void loop() {

  // see if there's incoming serial data:

  if (Console.available() > 0) {

    // read the oldest byte in the serial buffer:

    incomingByte = Console.read();

    // if it's a capital H (ASCII 72), turn on the LED:

    if (incomingByte == 'H') {

      digitalWrite(ledPin, HIGH);
    Console.println("Led is ON !!!!");


    }

    // if it's an L (ASCII 76) turn off the LED:

    if (incomingByte == 'L') {

      digitalWrite(ledPin, LOW);
      Console.println("Led is OFF !!!!");

    }


 if (incomingByte == 'B') {

      digitalWrite(ledPin, LOW);
      Console.println("Blinking....");


for (int i = 0; i <= 9; i++) {
    Console.println("Blinking..N");
    Console.println(i);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    Console.println("Finihsed Blinking..N");
    }  

      

    }





    

  }

  delay(100);
}
