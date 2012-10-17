void setup() {
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A
  pinMode(3, OUTPUT);  // channel B
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H

  pinMode(10, OUTPUT); //Escudo Status LED

  // Set all the lights to "on"
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}

int last_flicker = 0;

void loop() {
  //randomly flicker one of the lights
  flicker(random(10)-1);
  delay(random(3000));
}

void flicker(int light){
  for (int i=0; i<3; i++){
    digitalWrite(light, 0);
    delay(random(100));
    digitalWrite(light, 1);
    delay(random(200));
  }
}

