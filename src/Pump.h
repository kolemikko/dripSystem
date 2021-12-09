void runPump(int pumpNumber, int timeSec)
{
  digitalWrite(pumpNumber, HIGH);
  delay(timeSec * 1000);
  digitalWrite(pumpNumber, LOW);
}
