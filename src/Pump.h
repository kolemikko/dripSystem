void runPump(int pumpNumber, int time, int speed)
{
  analogWrite(pumpNumber, speed);
  delay(time);
  analogWrite(pumpNumber, 0);
}
