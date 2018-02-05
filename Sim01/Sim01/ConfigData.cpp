/**
  * File: ConfigData.cpp
  *
  * Details: Implementation of the ConfigData.h class. This will concern
  *            file read in of a configuration file
  *
  * Version: 1.00 Initial Development
  *          2/2/18 Kevin Carlos
  *
  * Notes: None
  *
  */

//
// Include Directives
//
#include <queue>
#include <fstream>
#include <iostream>

#include "ConfigData.h"

/**
  * Function: fileReadIn
  *
  * Details: Read in the file contents into a queue to use afterwards
  *
  * Notes: If file doesn't open correctly, exit program since this is 
               operated through the command line
*/
void ConfigData::fileReadIn ( std::string configFileName )
{
   //Declare variables
   std::ifstream  fin;
   std::string    temp ,
                  data ,
                  temp2; 

   //Check that the file opened
   fin.open ( configFileName );

   if ( !fin )
      exit ( 1 ); 

   //std::cout << "File opened...\n";
 
   //Otherwise read in the values and store in string queue
   while ( !fin.eof ( ) )
   {
      std::getline ( fin , temp , ':' );
      std::getline ( fin , temp2 , ' ' );

      //All necessary info in data
      std::getline ( fin , data , '\n' ); 
      
      //Debugging
      //std::cout << "Temp: " << temp << "\n";
      //std::cout << "Data: " << data << "\n";

      //Store into queue
      configQueue.push ( data );

      //std::cout << "Size: " << configQueue.size ( ) << "\n";
   }

   //Close the file
   fin.close ( );
}