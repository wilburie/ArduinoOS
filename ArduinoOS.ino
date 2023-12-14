// ArduinoOS computer arduino Code
// turns your arduino into a computer!
// code by wilburie, (add my disc!)


// variables
String command;
#define blueLed 5
#define whiteLed 6
#define redLed 7


String password = "1066"; // SET THIS TO YOUR DESIRED PASSWORD


bool passwordpassed = false;

void setup() {
  Serial.begin(9600);
  // pinmodes
  pinMode(blueLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  delay(2000);
  Serial.println("ArduinoOS: enter password to continue");
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
      } else if (command.equals("spacer")) {
        Serial.println("--------------------------------------------");
      } else {
        Serial.println("cmd nil");
      }
    } else {
      if (command.equals(password)) {
        Serial.print("password: ");
        Serial.println(command);
        Serial.println("correct password, starting ArduinoOS...");
        Serial.println("loading boot sectors...");
        delay(1000);
        Serial.println("setting variables...");
        delay(2000);
        passwordpassed = true;
        Serial.println("--------------------------------------------");
        Serial.println("welcome to ArduinoOS");
        Serial.println("type 'cmds' for avaliable commands");
        Serial.println("--------------------------------------------");
      } else {
        Serial.print("password: ");
        Serial.println(command);
        Serial.println("wrong password");
      }
    }
  }
}
