#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#include "Upper.h"
#include "TwoDigits.h"
#include "LetterAndPunct.h"



//Method to output values
//@params map1 - The map of filtered words;
//@params value - The value of the largest word;
//@params version - The type of output;

void outputLargests(map<string, int> &map1, int value, int version){
    map<string, int> word = map1;
    map<string, int>::iterator it3;
    int count2=0;
    for(it3 = word.begin(); it3!=word.end();++it3) {
        if(count2==0){
            if(it3->second == value){

                if(version==0){
                    cout << "Largest Word:" << endl;
                }else  if(version==1){
                    cout << "Second Largest Word:" << endl;
                }else  if(version==2){
                    cout << "Third Largest Word:" << endl;
                }

                cout <<it3->first << "   " << it3->second << endl;
                count2+=1;
            }
        }else if(it3->second == value){
            cout << "" <<it3->first << "   " << it3->second << endl;
            count2+=1;
        }



    }

}


//Main Method
//Open a file that is provided by the user to look for words
int main() {
    char fileName[20];
    cout << "Enter a file name:" << endl;
    cin >> fileName;

    int filterMethod;
    cout << "Enter which filter method to use (1-3)" << endl;
    cin >> filterMethod;

    //Pointer to a ReadFilteredWords Object
    ReadFilteredWords* words;
    Upper upper = Upper(fileName);
    TwoDigits twoDigits = TwoDigits(fileName);
    LetterAndPunct letterAndPunct = LetterAndPunct(fileName);

    //Based on which input the user gives determine which filter method to use
    if(filterMethod==1){
        words = &upper;
    }else if (filterMethod==2){
        words = &twoDigits;
    }else if (filterMethod==3){
        words = &letterAndPunct;
    }else{
        cout << "nothing" << endl;
    }


    map<string, int> word;
    //Input the filtered words and their counts to a map
    while (true){
        string nextWord = words->getNextFilteredWord();
        if(nextWord!=""){
            if(word.count(nextWord) == 1){
                word.at(nextWord)+=1;
            }else{
                word.insert(make_pair(nextWord, 1));
            }
        }else{
            break;
        }
    }

    int totalInstances = 0;
    int totalDistinct = word.size();

    set<int, greater<int>> topSize;

    //Input all values to a set ordered by greatest to smallest
    map<string, int>::iterator it2;
    for(it2 = word.begin(); it2!=word.end();++it2) {
        totalInstances  += it2->second;
        topSize.insert(it2->second);
    }


    int largest;
    int largest1;
    int largest2;

    int count=0;
    //Find the top 3 largest items
    for (auto student = topSize.begin(); student != topSize.end(); ++student) {
        if(count==0){
            largest = *student;
        }else if(count==1){
            largest1 = *student;
        }else if(count==2){
            largest2 = *student;
        }
        count +=1;
    }

    //Output the 2 types of occurences.
    cout << "There are " <<totalDistinct << " total distinct occurrences of filtered words" << endl;
    cout << "There are " << totalInstances << " total instances of filtered words\n" << endl;

    outputLargests(word,largest,0);
    outputLargests(word,largest1,1);
    outputLargests(word,largest2,2);

}