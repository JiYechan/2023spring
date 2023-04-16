const int speakerPin = 9;  

int melodyNotes[] = {
  330, 494, 494, 370, 330, 330, 247, 330, 330, 370, 330, 0,
  330, 494, 494, 370, 330, 330, 247, 330, 330, 370, 330, 0,
  330, 494, 440, 330, 370, 294, 294, 440, 392, 262,
  247, 262, 294, 330, 370, 392, 440, 494, 440, 311,
};

int melodyDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 12,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 12,
};

int melodyLength = sizeof(melodyNotes) / sizeof(melodyNotes[0]); 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  for (int i = 0; i < melodyLength; i++) {
    tone(speakerPin, melodyNotes[i]); 
    delay(200 * melodyDurations[i]); 
    noTone(speakerPin); 
    delay(100); 
  }
}

