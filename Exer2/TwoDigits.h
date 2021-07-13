//
// Created by joshp on 14/01/2019.
//

#ifndef _TWODIGITS_H
#define _TWODIGITS_H


#include "ReadFilteredWords.h"

class TwoDigits : public ReadFilteredWords{
public:
    //Constructor - Uses the ReadFilteredWords Constructor to open the file
    TwoDigits(const char *fname): ReadFilteredWords(fname)
    {
    }

    //For this Version of the Filter method it will return true if there is more than 2 digits next to each other.
    bool filter(string word);
};


#endif //_TWODIGITS_H
