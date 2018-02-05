/**
  * File: main.cpp
  *
  * Details: Driver file for the Sim01 project
  *
  * Version: 1.00 Initial development
  *               2/3/18 Kevin Carlos
  *
  * Notes: argv [ 1 ] should be the name of the config file, which will
  *            be passed to the class to read in the data
  *
  */

#include <iostream>

#include "ConfigData.h"

int main ( int argc , char *argv [ ] )
{
   std::cout << "You have entered " << argc << " arguments:" << "\n";

   for ( int i = 0; i < argc; ++i )
      std::cout << argv [ i ] << "\n";

   ConfigData Obj;
   Obj.fileReadIn ( argv [ 1 ] );

   return 0;
}