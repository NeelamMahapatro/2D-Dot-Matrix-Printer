#include <dot_printer.h>
dot_printer prt;

void setup()
{
prt.initialize();
}
char ch='x';
void loop()
{
  if(Serial.available())
  {
    ch=Serial.read();
    if(ch=='y')
    {
      prt.printdata("NIT");
      ch='x';
    }
  }
}
