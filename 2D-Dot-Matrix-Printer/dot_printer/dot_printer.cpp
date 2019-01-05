#include "Arduino.h"
#include "dot_printer.h"
#define stp 2

const int stepsPerRevolution = 200;
int dot_pos=10;
int ir_pin_y = 3,ir_pin_x=2; 
int counter = 0;
unsigned long previous=0,current;
Stepper x_(stepsPerRevolution, 4, 5, 6, 7);
Stepper y_(stepsPerRevolution, 11, 10, 9, 8);
Servo myservo;

int A[5][9]={{1,1,1,1,1,1,1,1,1},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int B[5][9]={{0,1,1,1,0,1,1,1,0},{1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int C[5][9]={{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int D[5][9]={{0,0,1,1,1,1,1,0,0},{0,1,0,0,0,0,0,1,0},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int E[5][9]={{1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1},{1,0,0,0,1,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int F[5][9]={{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int G[5][9]={{1,0,0,0,1,1,1,1,1},{1,0,0,0,1,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int I[5][9]={{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1}};
int N[5][9]={{1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int T[5][9]={{1,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0 },{1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0}};
int R[5][9]={{0,1,1,1,0,0,1,1,1},{1,0,0,0,1,1,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int K[5][9]={{1,1,0,0,0,0,1,1,1},{0,0,1,0,0,1,0,0,0},{0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int L[5][9]={{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int P[5][9]={{0,1,1,1,0,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int X[5][9]={{1,1,0,0,0,0,0,1,1},{0,0,1,1,0,1,1,0,0},{0,0,0,0,1,1,0,0,0},{0,0,1,1,0,1,1,0,0},{1,1,0,0,0,0,0,1,1}};
int O[5][9]={{1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int M[5][9]={{1,1,1,1,1,1,1,1,1},{1,1,0,0,0,0,0,0,0},{0,0,1,1,1,0,0,0,0},{1,1,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int H[5][9]={{1,1,1,1,1,1,1,1,1},{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},{1,1,1,1,1,1,1,1,1}};
int U[5][9]={{1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
int hpn[5][9]={{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0}};

void IRcounter()
{
  current=millis();
  if(current-previous>30)
    {
      counter++;
    }
  previous=current;
}

void dot_printer::initialize()
{
  Serial.begin(9600);
  myservo.attach(12);
  myservo.write(20);
  y_.setSpeed(15);
  x_.setSpeed(15);

  pinMode(ir_pin_y, INPUT);
  pinMode(ir_pin_x, INPUT);
  attachInterrupt(digitalPinToInterrupt(ir_pin_y),IRcounter, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ir_pin_x),IRcounter, CHANGE);
  delay(1000);
  Serial.println("initialized printer");
}

void dot_printer::dot()
{
  myservo.write(0);delay(300);myservo.write(20);delay(300);
}

void dot_printer::move_xy(int task,String s)
{
  counter=0;
  while(counter<abs(task))
  {
    Serial.println(counter);
      if(s=="y")
      {
        if(task>0 && counter<task)
        {
            y_.step(1);
        }
        else if(task<0 && counter<abs(task))
        {
            y_.step(-1);
        }
      }
      else if(s=="x")
      {
        if(task>0 && counter<task)
        {
            x_.step(1);
        }
        else if(task<0 && counter<abs(task))
        {
            x_.step(-1);
        }
      }
  }
}

void dot_printer::draw(int let[5][9])
{
	for(int i=4;i>=0;i--)
		{
			for(int j=0;j<9;j++)
			{
				if(let[i][j]==1)
					dot();
				move_xy(stp,"y");
				delay(100);
			}
			move_xy(stp,"x");
			for(int j=0;j<9;j++)
			{
				move_xy(-stp,"y");
				delay(100);
			}
		}
}

void dot_printer::printchar(char ch)
{
	/*
	if(ch=='A')
	{draw(A);}
	else if(ch=='B')
	{draw(B);}
	else if(ch=='C')
	{draw(C);}
	else if(ch=='D')
	{draw(D);}
	else if(ch=='E')
	{draw(E);}
	else if(ch=='F')
	{draw(F);}
	*/
	if(ch=='N')
	{draw(N);}
	else if(ch=='I')
	{draw(I);}
	else if(ch=='T')
	{draw(T);}
	/*
	else if(ch=='R')
	{draw(R);}
	else if(ch=='K')
	{draw(K);}
	else if(ch=='P')
	{draw(P);}
	else if(ch=='G')
	{draw(G);}
	else if(ch=='O')
	{draw(O);}
	else if(ch=='U')
	{draw(U);}
	else if(ch=='H')
	{draw(H);}
	else if(ch=='L')
	{draw(L);}
	//else if(ch=='-')
	//{draw(hpn);}
	*/
	move_xy(2*stp,"x");
	//move_xy(stp,"y");
}

void dot_printer::printdata(String dat)
{
	int len=dat.length();
	if(len>12)
	{
		move_xy(stp*4,"y");move_xy(-stp*4,"y");
	}
	else
	{
		int i=0;
		while(i<len)
		{
			printchar(dat[i]);
			Serial.println(dat[i]);
			i++;
		}
	}
}
