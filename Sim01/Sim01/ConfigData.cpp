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
#include <algorithm>

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
      //Set to lowercase
      std::transform ( 
         keyVal.begin ( ) , 
         keyVal.end ( ) , 
         keyVal.begin ( ) , 
         ::tolower );

      //Special case for log file path
      it = configMap.find ( "log" );
      if ( it == configMap.end() ) 
      {
         //Not found
      }
      else
      {
         keyVal = "path";
      }

      
      //Insert into map
      configMap.insert ( std::pair<std::string, std::string> ( keyVal, data ) );

      //Debugging
      //std::cout << "Key: " << keyVal << "\n";
      //std::cout << "Data: " << data << "\n";
   }

   temp = ( "End" );
   configMap.erase ( temp );

   //Set the meta file
   it = configMap.find ( "file" ); //Meta file path
   temp = it->second;
   //Get rid of the \r
   metaFile = temp.substr ( 0 , temp.find ( '\r' ) );

   //Close the file
   fin.close ( );
}

void ConfigData::log ( )
{
   //Variable declarations
   std::ofstream  fout;
   std::string    logOutput;
   std::string    logPath;

   //Access map to find where to log
   it = configMap.find ( "log" );
   logOutput = it->second;
   logOutput = logOutput.substr ( 0 , logOutput.find ( '\r' ) );

   std::cout << "logOutput: " << logOutput << "\n";

   if ( logOutput == "Log to Both" )
   {
      //Find where the file path is
      it = configMap.find ( "path" );
      logPath = it->second;
      logPath = logPath.substr ( 0 , logPath.find ( '\r' ) );

      //Open the file
      fout.open ( logPath );

      std::cout << "Configuration File Data\n";
      fout << "Configuration File Data\n";

      //Run through the data
      for ( it = configMap.begin ( ); it != configMap.end ( ); ++it )
      {
         std::cout << it->first << ": " << it->second << '\n';
      }
      for ( it = configMap.begin ( ); it != configMap.end ( ); ++it )
      {
         fout << it->first << ": " << it->second << '\n';
      }
      fout.close ( );
   }
   
   if ( logOutput == "Monitor" )
   {
      std::cout << "Configuration File Data\n";

      //Run through the data
      for ( it = configMap.begin ( ); it != configMap.end ( ); ++it )
      {
         std::cout << it->first << ": " << it->second << '\n';
      }
   }

   if ( logOutput == "File" )
   {
      //Find where the file path is
      it = configMap.find ( "path" );
      logPath = it->second;
      logPath = logPath.substr ( 0 , logPath.find ( '\r' ) );

      //Open the file
      fout.open ( logPath );

      fout << "Configuration File Data\n";

      //Run through the data
      for ( it = configMap.begin ( ); it != configMap.end ( ); ++it )
      {
         fout << it->first << ": " << it->second << '\n';
      }
      fout.close ( );
   }

}