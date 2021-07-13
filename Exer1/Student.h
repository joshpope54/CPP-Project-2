#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <map>
#include <stdexcept>
#include "Person.h"

using namespace std;

class NoMarkException: public exception
{
};

class Student: public Person
{   public:
    /**
     * Constructor. Creates a student with name and regnum
     * @param name - the students name to be stored.
     * @param regNo - the students regNo to the be stored
     */
    Student(const string &name, int regNo);

    /**
     * Returns the Students reg number when called
     * @return int - a regnumber as a integer
     */
    int getRegNo() const;

    /**
     * Adds a mark to the Marks Map when called.
     * @param module - the module for which the mark is to be stored (Key of the map)
     * @param mark - the mark that is to be stored (Value of the Key)
     */
    void addMark(const string& module, float mark);

    /**
     * Can return the mark for the given module
     * @param module - is the module for which the mark is to be found
     * @return float - the mark is stored as a float and so must be returned as one.
     */
    float getMark(const string &module) const throw (NoMarkException);

    /**
     * This method can be used to calculate the average mark
     * @returns float - Returns the average mark of all the students modules
     */
    float calcAverage() const;

    /**
     * This method can be used to find the minimum mark
     * @returns float - Returns the minimum mark of all the students modules
     */
    float minimumMark() const;

    /**
     * This method can be used to find the maximum mark
     * @returns float - Returns the maxmimum mark of all the students modules
     */
    float maximumMark() const;


    /**
     * This method is used to return the marks map. This is so that all values may be printed.
     * @returns map<string, float> - a map in the correct format.
     */
    map<string, float> getMarksMap();


private:
    int regNo;                  //The students Reg number
    map<string, float> marks;  // keys are modules, values are marks in range 0.0 to 100.0

    // friend function to output details of student to stream
    // should output name, regno, and minimum, maximum and average marks on a single line
    // if the student has no marks "has no marks" should be output instead of the marks
    friend ostream& operator<<(ostream &str, const Student &s);
};

#endif