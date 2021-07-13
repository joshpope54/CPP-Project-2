#include "Upper.h"


//Filter Method
//For this Version of the Filter method it will return true if there both a upper case letter and a lower case letter.
bool Upper::filter(string word) {
    bool upperCount = false;
    bool lowerCount = false;

    for(char& c : word){
        if(isupper(c)){
            upperCount = true;
        }else if (islower(c)){
            lowerCount = true;
        }
    }

    if(upperCount && lowerCount){
        return true;
    }else{
        return false;
    }


}
