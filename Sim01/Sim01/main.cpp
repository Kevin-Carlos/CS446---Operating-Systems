/**
  * File: main.cpp
  *
  * Details: Driver file for the Sim01 project
  *
  * Version: 1.00 Initial development
  *               2/3/18 Kevin Carlos
  *
  * Notes: none
  *
  */

#include <iostream>

int main ( int argc , char *argv [ ] )
{
   std::cout << "You have entered " << argc << " arguments:" << "\n";

   for ( int i = 0; i < argc; ++i )
      std::cout << argv [ i ] << "\n";

   return 0;
}