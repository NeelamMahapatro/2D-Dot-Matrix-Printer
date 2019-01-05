#ifndef DOT_PRINTER_H
#define DOT_PRINTER_H

#include "Arduino.h"
#include <Servo.h>
#include <Stepper.h>

class dot_printer
{
private:
  void draw(int let[5][9]); //to draw a letter
public:
  void initialize(); //to initialize printer parameters
  void dot(); //function to put a single dot on paper axis-z control servo
  void printdata(String); //to recieve a string to be printed
  void printchar(char); //to print a character on paper by selecting specific 2D binary array
  void move_xy(int,String);
};
#endif
