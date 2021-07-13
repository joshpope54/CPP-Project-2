#include "ReadWords.h"
#include "ReadFilteredWords.h"
#include <iostream>

using namespace std;

string ReadFilteredWords::getNextFilteredWord() {

    //Returns the next word if it can be filtered.

    while(isNextWord()){

        string nextWord = getNextWord();

        if(filter(nextWord)){
            return nextWord;
        }
    }

    return "";

}
