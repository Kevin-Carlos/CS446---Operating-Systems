/**
  * File: metaData.cpp
  *
  * Details: Implementation of the metaData class
  *
  * Author: Kevin Carlos
  *         1.00 Initial development
  *         2/7/18
  *
  * Notes: none
  *
  *
*/

// 
// Include Directives
//
#include "metaData.h"

void metaData::metaFileReadIn ( std::string fileName )
{
   //Variable declarations
   std::ifstream  fin;
   std::string    temp, 
                  data,
                  key;
   char           code;
   int            index1 ,
                  index2;
                  //time;
   const std::string END = "finish";
   
   //Open the file
   fin.open ( fileName );

   //If file doesn't exist exit program
   if ( !fin )
   {
      std::cout << "Error opening meta data file...\n";
      std::cout << "Check file path...\n";
      std::cout << "Exiting program...\n";
      exit ( 1 );
   }

   //Otherwise...
   //Read in the first line since that will always be the start of the fiel
   std::getline ( fin , temp , '\n' );

   for (;;)
   {
      //Grab the entire process
      std::getline ( fin , data , ';' );

      //Take the process code
      code = data [ 0 ];

      //Grab the insides of the { }
      index1 = data.find ( '{' );
      index2 = data.find ( '}' );
      key = data.substr ( index1 + 1 , index2 - 2 );

      
      //index = data.find ( '{' );
      //key = data.substr ( ( index + 1 ) , ( data.find ( '}' ) - 2 ) );
      
      //Grab the time taken

      //Get rid of the extra space
      std::getline ( fin , temp , ' ' );

     
      if ( key == END )
      {
         break;
      }

      
      /*std::cout << "Data: " << data << "\n";
      std::cout << "Char: " << code << "\n";
      std::cout << "Key: " << key << "\n";
      std::cout << "Time: " << time << "\n";
      std::cout << "Temp: " << temp << "\n";*/

      break;
      
   } 

}