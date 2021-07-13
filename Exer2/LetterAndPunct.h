//
// Created by joshp on 14/01/2019.
//

#ifndef _LETTERANDPUNCT_H
#define _LETTERANDPUNCT_H


#include "ReadFilteredWords.h"

class LetterAndPunct : public ReadFilteredWords{
public:

    /**
     * Constructor. Opens the file with the given filename.
     * Uses the ReadFilteredWords Constructor
     * @param filename- A String with containing the file name.
     */
    LetterAndPunct(const char *fname): ReadFilteredWords(fname)
    {
    }

    //For this Version of the Filter method it will Find words that contain both a letter and punctuation.
    bool filter(string word);
};


#endif //_LETTERANDPUNCT_H
