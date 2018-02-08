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
   int            count = 0;
   std::string    temp ,
                  data ,
                  keyString ,
                  keyVal;

   //Check that the file opened
   fin.open ( configFileName );

   //If it doesn't open, exit program; wrong file
   if ( !fin )
   {
      std::cout << "Error opening file...\n";
      std::cout << "Exiting program...\n";
      exit ( 1 );
   }

   //Otherwise read in the values and store in string queued
   while ( !fin.eof ( ) )
   {
      //Ignore
      //Jankiness
      if ( count == 0 )
      {
         std::getline ( fin , temp , '\n' );
         std::getline ( fin , temp , '\n' );
         count++;
      }
      
      //Collect data into map
      std::getline ( fin , keyString , ':' );
      std::getline ( fin , temp , ' ' );
      std::getline ( fin , data , '\n' );

      //Take the first word to be the actual key
      keyVal = keyString.substr ( 0 , keyString.find ( ' ' ));

      
      //Insert into map
     // configMap.insert ( keyVal , data );

      //Debugging
      std::cout << "Key: " << keyVal << "\n";
      std::cout << "Data: " << data << "\n";
   }

   //Close the file
   fin.close ( );
}


bool ConfigData::setLogPath ( )
{
   //Variable declarations
   std::string temp;
   const std::string LOGBOTH = "Both";

   //temp = configQueue.front ( );
   if ( temp.find ( LOGBOTH ) )
      outputPath = 'B';

   return 1;
}