//
// Created by joshp on 14/01/2019.
//

#ifndef _UPPER_H
#define _UPPER_H


#include "ReadFilteredWords.h"

class Upper : public ReadFilteredWords{
public:

    Upper(const char *fname): ReadFilteredWords(fname)
    {
    }


    //For this Version of the Filter method it will return true if there both a upper case letter and a lower case letter.
    bool filter(string word);
};


#endif //_UPPER_H
