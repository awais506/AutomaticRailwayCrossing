

#define MotorInput1 2
#define MotorInput2 3
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as an output.
  pinMode(MotorInput1, OUTPUT);
  pinMode(MotorInput2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  MotorDriver(1);
  delay(1000);              // wait for a second
  MotorDriver(0);
  delay(1000); 
 
}

/*
Descrption: This function is used to drive motor clock or anticlok wise as needed. It will be used with
L293D IC. 
Input: bool, 1 for clockwise and 0 for anticlock wise
Output: It makes pins relative IC pins 1 and zero accordingly
*/
void MotorDriver(bool Direction)
{
  if (Direction==1)
  { 
digitalWrite(MotorInput1, 1);   // turn the LED on (HIGH is the voltage level)
digitalWrite(MotorInput2, 0);    // turn the LED off by making the voltage LOW
  }
  else if(Direction==0)
{
digitalWrite(MotorInput1, 0);   // turn the LED on (HIGH is the voltage level)
digitalWrite(MotorInput2, 1);    // turn the LED off by making the voltage LOW
  }
}

