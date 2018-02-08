/**
* File: ConfigData.h
*
* Details: A header file containing a class for the datatypes of
*            configuration file
*
* Version: 1.00 Initial development
*          2/2/18 Kevin Carlos
*
* Notes: None
*
*/

#include <string>
#include <map>

#ifndef _CONFIGDATACLASS__
#define _CONFIGDATACLASS__

class ConfigData
{
public:
   //Variables
   std::string    metaFile , logFile;
   char           outputPath;

   //Data structures
   std::map<std::string , std::string> configMap;

   //Member methods
   void fileReadIn ( std::string );
   bool setLogPath ( );

};
#endif