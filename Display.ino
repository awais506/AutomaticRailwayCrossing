
int Sensor = 12;
int Red=A0;
int Green=A1;
int A=12;
int B=11;
int C=10;
int D=9;
int E=8;
int F=7;
int G=6;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
//Initilize pins for sensor, traffic lights and seven Segment
  pinMode(Sensor, INPUT);
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G, OUTPUT);
  
  
}
// Main program
void loop() {
  // read the Sensor
  int Train = digitalRead(Sensor);
  delay(1);        // delay in between reads for stability
  
  //When train is approaching 
  if(Train==1)
  {
   trafFcLight(Train);
   Communication(Train);
   SevenSegment();
 
  }
  
  //When No train
  else if(Train==0)
  {
   trafFcLight(Train);
    SevenSeg0();
   Communication(Train);
   }
}



/*
Descrption: This function have two things to do.On red  with off green or, off red with on Gree.
If input is 1,RED will be on and Green will be off
If input is 0,Green will be on and Red will be off
Input: State, 1 or ) only
Output: Makes Light on and off accordingly
*/
void trafFcLight(int state)
{
  if (state==1)
{
digitalWrite(Red,1);
digitalWrite(Green,0);
}

else if (state==0)
{
digitalWrite(Red,0);
digitalWrite(Green,1);
}

}


/*
Descrption: It serially communicates with any device attached and tell the train situation.
Input: Train state
Output: Serially communicates state of train.
*/
void Communication(int state)
{
 if (state==1)
{
Serial.println("Train is approaching at Railway Crossing Number: 25");
}

else if (state==0)
{
Serial.println("NO Train at Railway Crossing Nubmer: 25");
}


}



/*
Descrption: It is for Seven segment display.Starts form 9, it deceremtns counter each second.
As soon as it is called, it will start counting down.
Input: No input
Output: 
*/
void SevenSegment()
{
  
 // write '9'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 0);
 digitalWrite(E, 0);
 digitalWrite(F, 1);
 digitalWrite(G, 1);
 delay(1000);
 // write '8'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 1);
 digitalWrite(F, 1);
 digitalWrite(G, 1);
 delay(1000);
 // write '7'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 0);
 digitalWrite(E, 0);
 digitalWrite(F, 0);
 digitalWrite(G, 0);
 delay(1000);
 // write '6'
 digitalWrite(A, 1);
 digitalWrite(B, 0);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 1);
 digitalWrite(F, 1);
 digitalWrite(G, 1);
 delay(1000);
 // write '5'
 digitalWrite(A, 1);
 digitalWrite(B, 0);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 0);
 digitalWrite(F, 1);
 digitalWrite(G, 1);
 delay(1000);
 // write '4'
 digitalWrite(A, 0);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 0);
 digitalWrite(E, 0);
 digitalWrite(F, 1);
 digitalWrite(G, 1);
 delay(1000);
 // write '3'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 0);
 digitalWrite(F, 0);
 digitalWrite(G, 1);
 delay(1000);
 // write '2'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 0);
 digitalWrite(D, 1);
 digitalWrite(E, 1);
 digitalWrite(F, 0);
 digitalWrite(G, 1);
 delay(1000);
 // write '1'
 digitalWrite(A, 0);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 0);
 digitalWrite(E, 0);
 digitalWrite(F, 0);
 digitalWrite(G, 0);
 delay(1000);
 // write '0'
 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 1);
 digitalWrite(F, 1);
 digitalWrite(G, 0);
  
}

/*
Descrption: Prints 0 at seven segment
Output: Serially communicates state of train.
*/
void SevenSeg0()
{

 digitalWrite(A, 1);
 digitalWrite(B, 1);
 digitalWrite(C, 1);
 digitalWrite(D, 1);
 digitalWrite(E, 1);
 digitalWrite(F, 1);
 digitalWrite(G, 0);

}
