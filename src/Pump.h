void runPump(int pumpNumber, int time)
{
  digitalWrite(pumpNumber, HIGH);
  delay(time);
  digitalWrite(pumpNumber, LOW);
}
