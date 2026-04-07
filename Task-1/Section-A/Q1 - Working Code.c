	int led1 = 8;
	int led2 = 9;
	int led3 = 10;

	int s1 = LOW;
	int s2 = LOW;
	int s3 = LOW;

	unsigned long a = 0;
	unsigned long b = 0;
	unsigned long c = 0;

	unsigned long interval1 = 500;
	unsigned long interval2 = 1000;
	unsigned long interval3 = 1500;

void setup() 
{

	  pinMode(led1, OUTPUT);
	  pinMode(led2, OUTPUT);
	  pinMode(led3, OUTPUT);
}

void loop()
{
  unsigned long now = millis(); //now is a variable that holds the value given by millis() function//

  if (now - a >= interval1) //Checking if more than 500ms have been passed and if it has then the LED has to light up//
  {
    a = now;
    s1 = !s1;
    digitalWrite(led1, s1);
  }

  if (now - b >= interval2) //Similarly checking if more than 1000ms have passed//
  {
    b = now;
    s2 = !s2;
    digitalWrite(led2, s2);
  }

  if (now - c >= interval3) //Similarly checking if more than 1500ms havae passed//
  {
    c = now;
    s3 = !s3;
    digitalWrite(led3, s3);
  }
}