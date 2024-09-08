void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);

  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);

  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(1000);
}
