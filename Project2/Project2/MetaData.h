/**
* File: metaData.h
*
* Details: a class to read in the meta data file and use the data
*
* Author: Kevin Carlos
*         1.00 Initial Development
*         2/7/18
*
* Notes: none
*/


#include "ConfigData.h"

#ifndef _METADATACLASS__
#define _METADATACLASS__


class metaData : public ConfigData
{
public:

   void metaFileReadIn ( std::string );
};
#endif