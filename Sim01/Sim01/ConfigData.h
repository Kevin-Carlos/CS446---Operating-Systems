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
#include <queue>

class ConfigData 
{
public:
   std::string    metaFile;
   int            monitorTime ,
                  processorTime ,
                  scannerTime ,
                  HDDTime ,
                  keyboardTime ,
                  memoryTime ,
                  projectorTime;
   char           outputPath;
   std::string    logFile;
   
   std::queue<std::string> configQueue;

   void fileReadIn ( std::string );
   bool setVariables ( );
   bool setLogPath ( );

};