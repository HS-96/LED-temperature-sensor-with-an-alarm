// C++ code
//
int temp_sens = 0;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(0, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  // temperature sensor
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  temp_sens = (-40 + 0.488155 * (analogRead(A0) - 20));
  if (temp_sens < 26) {
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(0, LOW);
  }
  if (temp_sens > 26) {
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    tone(12, 294, 1000); // play tone 50 (D4 = 294 Hz)
  }
  if (temp_sens > 35) {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    tone(12, 1.9152548672166444e+21, 1000); // play tone 800 (G#66 = 1.9152548672166444e+21 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}