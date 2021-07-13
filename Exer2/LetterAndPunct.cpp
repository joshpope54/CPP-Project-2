//
// Created by joshp on 14/01/2019.
//

#include "LetterAndPunct.h"
#include <cctype>


//Filter Method
//For this Version of the Filter method it will Find words that contain both a letter and punctuation.
bool LetterAndPunct::filter(string word) {
    int punctCount = false;
    int letterCount = false;
    for(char& c: word){
        if(ispunct(c)){
            punctCount = true;
        }else if(isalpha(c)){
            letterCount = true;
        }
    }

    return (punctCount && letterCount);
}
