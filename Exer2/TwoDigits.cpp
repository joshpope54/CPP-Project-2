//
// Created by joshp on 14/01/2019.
//

#include "TwoDigits.h"

//Filter Method
//For this Version of the Filter method it will return true if there is more than 2 digits next to each other.
bool TwoDigits::filter(string word) {
    bool trueCount = false;

    for(int i=0; i<word.size(); ++i) {
        if (i == word.size()){
            break;
        }

        if(isdigit(word[i]) && isdigit(word[i+1])){
            trueCount= true;
        }
    }

    return trueCount;
}
