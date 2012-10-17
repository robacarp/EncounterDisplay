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
  PORTD = 0xFFFF;
  PORTB = 0xFFFF;
}

void loop() {
  //randomly flicker one of the lights
  flicker(random(10)-1);
  delay(random(3000));

  //kill it after 2 hours
  if (millis() > 7200000){
    PORTD = 0x0000;
    PORTB = 0x0000;
    while(true);
  }
}

void flicker(int light){
  for (int i=0; i<3; i++){
    digitalWrite(light, 0);
    delay(random(100));
    digitalWrite(light, 1);
    delay(random(200));
  }
}

