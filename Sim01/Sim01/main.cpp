/**
* File: main.cpp
*
* Details: Driver file for the Sim01 project
*
* Version: 1.00 Initial development
*               2/3/18 Kevin Carlos
*
* Collaborators: Nate T., Brian M., Brodie B.
*
*
* Notes: argv [ 1 ] should be the name of the config file, which will
*            be passed to the class to read in the data
*
*/

#include <iostream>

#include "ConfigData.h"
#include "metaData.h"

int main ( int argc , char *argv [ ] )
{
   //Class Object declarations
   ConfigData configObj;
   metaData metaObj;

   //Variables

   //Read in Config file and set data
   configObj.fileReadIn ( argv [ 1 ] );

   //Need to open metaData file now
   metaObj.metaFileReadIn ( configObj.metaFile );

   //Log
   configObj.log ( );

   return 0;
}