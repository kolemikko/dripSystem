void runPump(int pumpNumber, int timeSec, int speed)
{
  analogWrite(pumpNumber, speed);
  delay(timeSec * 1000);
  analogWrite(pumpNumber, 0);
}
