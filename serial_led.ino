const int ledPin =  LED_BUILTIN;
int ledState = LOW;
String a;
String c = "off\n";
String b = "on\n";
String d = "blink\n";
void setup() {

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
pinMode(ledPin, OUTPUT);
}

void loop() {

while(Serial.available()) {

a= Serial.readString();
Serial.println("you sent:");
Serial.println(a);


if (a == b) {

Serial.println("switching Led on...");

ledState = HIGH;
digitalWrite(ledPin, ledState);

 
}else if (a == c) {
  
Serial.println("switching Led off...");

ledState = LOW;
digitalWrite(ledPin, ledState);

}else if (a == d){
  
for (int i = 0; i <= 9; i++) {
    Serial.println("Blinking..N");
    Serial.println(i);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    
    }  
Serial.println("Finished blinking.");
}




}

}
