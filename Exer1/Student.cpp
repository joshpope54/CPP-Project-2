// BasePlusCommissionEmployee.cpp


#include <iostream>
#include "Student.h"
using namespace std;


/**
* Constructor. Creates a student with name and regnum
* @param name - the students name to be stored.
* @param regNo - the students regNo to the be stored
 *
 * Stores the given regnumber into the attribute
*/
Student::Student(const string &name, int regNo): Person(name) {
    this->regNo = regNo;
}
/**
* Returns the Students reg number when called
* @return int - a regnumber as a integer
*/
int Student::getRegNo() const {
    return regNo;
}
/**
* Adds a mark to the Marks Map when called.
* @param module - the module for which the mark is to be stored (Key of the map)
* @param mark - the mark that is to be stored (Value of the Key)
 *
 * Checks if the module exists first inorder to overwrite that score.
 * If it doesnt exist then it is added to the map with the given mark
*/
void Student::addMark(const string &module, float mark) {
    if(marks.count(module) == 1){
        marks.at(module)=mark;
    }else{
        marks.insert(make_pair(module, mark));
    }
}

/**
* Can return the mark for the given module
* @param module - is the module for which the mark is to be found
* @return float - the mark is stored as a float and so must be returned as one.
 *
 * Looks through the map to find the module and outputs the mark for that module
 * With throw a NoMarkException if the mark is not found in the map
*/
float Student::getMark(const string &module) const throw (NoMarkException){
    if (marks.count(module) ==1) {
        return marks.find(module)->second;
    } else {
        throw NoMarkException();
    }
}

/**
* This method can be used to calculate the average mark
* @returns float - Returns the average mark of all the students modules
 *
 * Calculates average by adding up all the values in the map and dividing by the size of the map
*/
float Student::calcAverage() const{
    float average;
    int mapSize = marks.size();
    map<string, float>::const_iterator it;
    for ( it =  marks.begin(); it != marks.end(); it++ ) {
        average = average + it->second;
    }
    average = average/mapSize;
    return average;
}

/**
* This method can be used to find the minimum mark
* @returns float - Returns the minimum mark of all the students modules
 *
 * Calculates minimum by looking through the map for values lower than 150 (Heighest mark is 100.00 so 150 should never be returned)
 *
*/
float Student::minimumMark() const{
    float minimum = 150;
    int mapSize = marks.size();
    map<string, float>::const_iterator it;
    for ( it =  marks.begin(); it != marks.end(); it++ ) {
        if(it->second<minimum){
            minimum = it->second;
        }
    }
    return minimum;
}

/**
* This method can be used to find the maximum mark
* @returns float - Returns the maxmimum mark of all the students modules
 *
 * Calculates the maximum mark by looking through the maps for any value greater than -5 (Smallest mark is 0 so -5 should not be returned)
*/
float Student::maximumMark() const{
    float maximum = -5;
    int mapSize = marks.size();
    map<string, float>::const_iterator it;
    for ( it =  marks.begin(); it != marks.end(); it++ ) {
        if(it->second>maximum){
            maximum = it->second;
        }
    }
    return maximum;
}

/**
* This method is used to return the marks map. This is so that all values may be printed.
* @returns map<string, float> - a map in the correct format.
*/
map<string, float> Student::getMarksMap() {
    return marks;
}



ostream &operator<<(ostream &str, const Student &s) {
    // friend function to output details of student to stream
    // should output name, regno, and minimum, maximum and average marks on a single line
    // if the student has no marks "has no marks" should be output instead of the marks


    if(s.marks.empty()){

        str << s.name << " has reg number " << s.regNo << " has no marks." << endl;

    }else{

        str <<  s.name << " has reg number " << s.regNo << " Minimum Mark: " << s.minimumMark() << " Maximum Mark: " << s.maximumMark() << " Average Mark: "<< s.calcAverage() <<  endl;
    }

    return str;
}




