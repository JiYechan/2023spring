
const int lowestPin = 2;
const int highestPin = 10; 
const int numLEDs = 9; 
const int numIterations = 3; 

void setup() {
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  randomSeed(analogRead(0)); 
}

void loop() {
  for (int j = 0; j < numIterations; j++) {
    for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
      digitalWrite(thisPin, HIGH);
      delay(50); 
      digitalWrite(thisPin, LOW); 
    }

    for (int thisPin = highestPin; thisPin >= lowestPin; thisPin--) {
      digitalWrite(thisPin, HIGH); 
      delay(50); 
      digitalWrite(thisPin, LOW); 
    }
  }

  for (int i = 0; i < numLEDs; i++) {
    int randomPin = random(lowestPin, highestPin + 1); 
    digitalWrite(randomPin, HIGH); 
    delay(500); 
    digitalWrite(randomPin, LOW); 
    delay(500); 
  }
}
