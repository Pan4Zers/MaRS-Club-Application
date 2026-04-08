int buzPin = 8;
int dt = 50;

void dot() 
{
  digitalWrite(buzPin, 1);
  Serial.print(".");
  delay(dt);           // dot duration
  digitalWrite(buzPin, 0);
  delay(dt);           // intra-character space
}

void dash() 
{
  digitalWrite(buzPin, 1);
  Serial.print("-"); 
  delay(3 * dt);       // dash duration
  digitalWrite(buzPin, 0);
  delay(dt);           // intra-character space
}

// Space between letters
void letterSpace() {
  delay(2 * dt);      
}

// Space between words
void wordSpace() {
  delay(7 * dt);
  Serial.print(" || ");       
}

// Function to send Morse for a character
void Morse(char c) 
{
  switch(c) 
  {
    case 'A': dot(); dash(); 
    Serial.print(" A ");
    break;
    case 'B': dash(); dot(); dot(); dot();  
    Serial.print(" B ");
    break;
    case 'C': dash(); dot(); dash(); dot();  
    Serial.print(" C ");
    break;
    case 'D': dash(); dot(); dot();  
    Serial.print(" D ");
    break;
    case 'E': dot();  
    Serial.print(" E ");
    break;
    case 'F': dot(); dot(); dash(); dot();  
    Serial.print(" F ");
    break;
    case 'G': dash(); dash(); dot();  
    Serial.print(" G ");
    break;
    case 'H': dot(); dot(); dot(); dot();  
    Serial.print(" H ");
    break;
    case 'I': dot(); dot();  
    Serial.print(" I ");
    break;
    case 'J': dot(); dash(); dash(); dash();  
    Serial.print(" J ");
    break;
    case 'K': dash(); dot(); dash();  
    Serial.print(" K ");
    break;
    case 'L': dot(); dash(); dot(); dot(); 
    Serial.print(" L ");
    break;
    case 'M': dash(); dash();  
    Serial.print(" M ");
    break;
    case 'N': dash(); dot();  
    Serial.print(" N ");
    break;
    case 'O': dash(); dash(); dash();  
    Serial.print(" O ");
    break;
    case 'P': dot(); dash(); dash(); dot();  
    Serial.print(" P ");
    break;
    case 'Q': dash(); dash(); dot(); dash();  
    Serial.print(" Q ");
    break;
    case 'R': dot(); dash(); dot();  
    Serial.print(" R ");
    break;
    case 'S': dot(); dot(); dot();  
    Serial.print(" S ");
    break;
    case 'T': dash();  
    Serial.print(" T ");
    break;
    case 'U': dot(); dot(); dash();  
    Serial.print(" U ");
    break;
    case 'V': dot(); dot(); dot(); dash();  
    Serial.print(" V ");
    break;
    case 'W': dot(); dash(); dash();  
    Serial.print(" W ");
    break;
    case 'X': dash(); dot(); dot(); dash();  
    Serial.print(" X ");
    break;
    case 'Y': dash(); dot(); dash(); dash();  
    Serial.print(" Y ");
    break;
    case 'Z': dash(); dash(); dot(); dot(); 
    Serial.print(" Z ");
    break;

    case '0': dash(); dash(); dash(); dash(); dash();  
    Serial.print(" 0 ");
    break;
    case '1': dot(); dash(); dash(); dash(); dash();  
    Serial.print(" 1 ");
    break;
    case '2': dot(); dot(); dash(); dash(); dash();  
    Serial.print(" 2 ");
    break;
    case '3': dot(); dot(); dot(); dash(); dash();  
    Serial.print(" 3 ");
    break;
    case '4': dot(); dot(); dot(); dot(); dash();  
    Serial.print(" 4 ");
    break;
    case '5': dot(); dot(); dot(); dot(); dot();  
    Serial.print(" 5 ");
    break;
    case '6': dash(); dot(); dot(); dot(); dot();  
    Serial.print(" 6 ");
    break;
    case '7': dash(); dash(); dot(); dot(); dot();  
    Serial.print(" 7 ");
    break;
    case '8': dash(); dash(); dash(); dot(); dot();  
    Serial.print(" 8 ");
    break;
    case '9': dash(); dash(); dash(); dash(); dot();  
    Serial.print(" 9 ");
    break;

    default:  Serial.print(" | ");break; // ignore unknown characters
  }
}

void setup() 
{
  pinMode(buzPin, OUTPUT);
   
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("Enter text:");
  while(Serial.available() == 0) {}
  String name = Serial.readStringUntil('\n');
  name.toUpperCase();

  for(int i = 0; i < name.length(); i++) 
  {
    char c = name[i];
    if(c == ' ') {
      wordSpace();        // space between words
    } else {
      Morse(c);
      letterSpace();      // space between the letters
    }
  }
  Serial.println("");
  Serial.println("Done!");
}