// ArduinoOS computer arduino Code
// turns your arduino into a computer!
// code by wilburie, (add my disc!)

// includes
#include <dht.h>

// variables
dht DHT;
String command;
#define blueLed 5
#define whiteLed 6
#define redLed 7
#define greenLed 8
#define DHT11_PIN 2


String password = "1066"; // SET THIS TO YOUR DESIRED PASSWORD


bool passwordpassed = false;

void setup() {
  Serial.begin(9600);
  // pinmodes
  pinMode(blueLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  delay(2000);
  Serial.println("ArduinoOS: enter password to continue");
  digitalWrite(greenLed, HIGH);
  delay(250);
  digitalWrite(greenLed, LOW);
  delay(250);
  digitalWrite(greenLed, HIGH);
  delay(250);
  digitalWrite(greenLed, LOW);
  delay(250);
}
void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (passwordpassed == true) {
      // commands
      Serial.print("cmd: ");
      Serial.println(command);
      if (command.equals("white")) {
        digitalWrite(whiteLed, HIGH);
        digitalWrite(blueLed, LOW);
        digitalWrite(redLed, LOW);
      }
      else if (command.equals("blue")) {
        digitalWrite(whiteLed, LOW);
        digitalWrite(blueLed, HIGH);
        digitalWrite(redLed, LOW);
      }
      else if (command.equals("red")) {
        digitalWrite(whiteLed, LOW);
        digitalWrite(blueLed, LOW);
        digitalWrite(redLed, HIGH);
      }
      else if (command.equals("all")) {
        digitalWrite(whiteLed, HIGH);
        digitalWrite(blueLed, HIGH);
        digitalWrite(redLed, HIGH);
      }
      else if (command.equals("off")) {
        digitalWrite(whiteLed, LOW);
        digitalWrite(blueLed, LOW);
        digitalWrite(redLed, LOW);
      } else if (command.equals("cmds")) {
        Serial.println("commands:");
        delay(1000);
        Serial.println("LED COMMANDS [turn leds on/off]: red, blue, white, all, off");
        Serial.println("TEXT COMMANDS [interact with the pc]: cmds, spacer");
        Serial.println("OTHER COMMANDS [dht, disance reader, etc.]: dhtread");
      } else if (command.equals("spacer")) {
        Serial.println("--------------------------------------------");
      } else if (command.equals("dhtread")) {
        int chk = DHT.read11(DHT11_PIN);
        // convert celsius to fahrenheit
        int ctof = (DHT.temperature * 9.0) / 5.0 + 32;
        Serial.print("temperature = ");
        Serial.print(ctof);
        Serial.println("°F");
        Serial.print("humidity = ");
        Serial.print(DHT.humidity);
        Serial.println("%");
      } else {
        Serial.println("cmd nil");
      }
    } else {
      if (command.equals(password)) {
        Serial.print("password: ");
        Serial.println(command);
        Serial.println("correct password, starting ArduinoOS...");
        digitalWrite(greenLed, HIGH);
        Serial.println("loading boot sectors...");
        delay(900);
        digitalWrite(greenLed, LOW);
        delay(250);
        digitalWrite(greenLed, HIGH);
        Serial.println("setting variables...");
        delay(1900);
        digitalWrite(greenLed, LOW);
        delay(250);
        digitalWrite(greenLed, HIGH);
        passwordpassed = true;
        Serial.println("--------------------------------------------");
        Serial.println("welcome to ArduinoOS");
        Serial.println("type 'cmds' for avaliable commands");
        Serial.println("--------------------------------------------");
        digitalWrite(greenLed, LOW);
      } else {
        Serial.print("password: ");
        Serial.println(command);
        Serial.println("wrong password");
        digitalWrite(redLed, HIGH);
        delay(800);
        digitalWrite(redLed, LOW);
      }
    }
  }
}
