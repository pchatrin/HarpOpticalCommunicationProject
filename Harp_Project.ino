int buttonstate_C = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;
int buttonstate_G = 0;
int buttonstate_A = 0;
int buttonstate_B = 0;
int buttonstate_Ca = 0;
int tones[] = { 1915/2, 1700/2, 1519/2, 1432/2, 1275/2, 1136/2, 1014/2, 956/2 }; //freq
int toner = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  buttonstate_C = digitalRead(2);
  buttonstate_D = digitalRead(3);
  buttonstate_E = digitalRead(4);
  buttonstate_F = digitalRead(5);
  buttonstate_G = digitalRead(6);
  buttonstate_A = digitalRead(7);
  buttonstate_B = digitalRead(8);
  buttonstate_Ca = digitalRead(9);
  Serial.print(buttonstate_C);
  Serial.print(buttonstate_D);
  Serial.print(buttonstate_E);
  Serial.print(buttonstate_F);
  Serial.print(buttonstate_G);
  Serial.print(buttonstate_A);
  Serial.print(buttonstate_B);
  Serial.print(buttonstate_Ca);
  Serial.println("");
  if((buttonstate_C == LOW) || (buttonstate_E == LOW) || 
    (buttonstate_G == LOW) || (buttonstate_D == LOW) || 
    (buttonstate_F == LOW) || (buttonstate_A == LOW) || 
    (buttonstate_B == LOW) || (buttonstate_Ca == LOW) )
  { 
    if (buttonstate_C == LOW)
    {
      toner = tones[0];
    } 
    if (buttonstate_D == LOW)
    {
      toner = tones[1];
    }
    if (buttonstate_E == LOW)
    {
      toner = tones[2];
    }
    if (buttonstate_F == LOW)
    {
      toner = tones[3];
    }
    if (buttonstate_G == LOW)
    {
      toner = tones[4];
    }
    if (buttonstate_A == LOW)
    {
      toner = tones[5];
    }
    if (buttonstate_B == LOW)
    {
      toner = tones[6];
    }
    if (buttonstate_Ca == LOW)
    {
      toner = tones[7];
    }
    /*digitalWrite(sound, LOW);
    delayMicroseconds(toner);
    digitalWrite(sound, HIGH);
    delayMicroseconds(toner);*/

    tone(10, toner);
    //delay(1000);        // ...for 1 sec
    //noTone(buzzer);     // Stop sound...
    //delay(1000); 
  }
  else //in case no button is pressed , close the piezo
  {
    //digitalWrite(sound, LOW);
    noTone(10);
  }
}
