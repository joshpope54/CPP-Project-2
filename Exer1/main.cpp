using namespace std;
#include <iostream>
#include <stdexcept>
#include "Student.h"
#include  <fstream>
#include <vector>
#include <set>

/*
 * import students, This method is used in the main method to return the collection of students
 * Opens the file that the user provides.
 *
 * Creates a student object and inserts it into the studentVector that will be returned.
 *
 * */

vector<Student> importStudents(){
    ifstream file;
    string name;
    string firstName;
    string lastName;
    int regNum;
    string fileName;
    vector<Student> studentVector;
    cout << "Enter a file name:" << endl;
    cin >> fileName;
    file.open(fileName);
    while (!file) {
        cout << "Failed to open " << fileName << endl;
        exit(1);
    }
    file >> regNum >> firstName >> lastName;

    // create student object and push to vector
    while(!file.eof()){
        name = firstName + " " + lastName;
        Student s = Student(name,regNum);
        studentVector.push_back(s);
        file >> regNum >> firstName >> lastName;
    }
    file.close();
    return studentVector;
}


/*Opens the file that contains the students marks.
 *
 * Adds marks and modules for the students to their own marks map.
 *
 * */
void importStudentMarks(vector<Student> &studentVector1){
    ifstream file;
    string moduleName;
    float mark;
    int regNum;
    string fileName;

    cout << "Enter a file name:" << endl;
    cin >> fileName;
    file.open(fileName);
    while (!file) {
        cout << "Failed to open " << fileName << endl;
        exit(1);
    }


    file >> regNum >> moduleName >> mark;

    typedef pair <string, float> dataPair;
    multimap <int, dataPair> dataMap;
    //Import data from file to multi map
    while(!file.eof()){
        dataMap.insert(make_pair(regNum, make_pair(moduleName,mark)));
        file >> regNum >> moduleName >> mark;
    }
    file.close();

    multimap<int,dataPair>::iterator it;

    //adding the marks to the individual students
    for (auto student = studentVector1.begin(); student != studentVector1.end(); ++student) {
        for(auto it = dataMap.cbegin(); it!=dataMap.cend();) {
            if (student->getRegNo() == it->first) {
                student->addMark(it->second.first, it->second.second);
                it = dataMap.erase(it);
            }else{
                ++it;
            }

        }
    }

    //If a mark isnt able to given to a student then the user will be told
    multimap<int,dataPair>::iterator it2;
    cout << endl;
    for(it2 = dataMap.begin(); it2!=dataMap.end();++it2) {
        cout << "Student with reg number " << it2->first << " is not in the collection their marks cannot be used." << endl;
    }
}


//First of the 3 functions
//This function takes the student vector and a average as parameters
//It will find any students within the vector that have a average mark less than the given average
//Does not return anything
void studentsLessAverage(vector<Student> studentVector2, float average) {
    cout << endl;
    bool studentsFound = false;
    for (auto student = studentVector2.begin(); student != studentVector2.end(); ++student) {
        if (student->calcAverage() <= average) {
            studentsFound=true;
            cout << *student;
        }
    }
    if (!studentsFound){
        cout << "No such students have been found!";
    }
}


//Takes a Vector a String and float
//The vector is the students collection
//The String is the Module Name
//The float is a mark
//This method will output any students that have a mark higher than the given mark for a certain module
void studentsModuleGreaterAverage(vector<Student> studentVector3, const string &moduleNo, float mark){
    cout << endl;
    bool studentsFound = false;
    for (auto student = studentVector3.begin(); student != studentVector3.end(); ++student) {
        try{
            if (student->getMark(moduleNo) >= mark) {
                studentsFound=true;
                cout << "Student " << student->getName() <<" (" << student->getRegNo() << ")" <<" has mark " << student->getMark(moduleNo) << " for module " << moduleNo << endl;
            }
        }catch (NoMarkException){
        }
    }
    if (!studentsFound){
        cout << "No such students have been found!";
    }
}


//This is the main function
int main() {
    //Creates the student vector using the import students method
    vector<Student> studentVector = importStudents();
    //Imports the student marks using the method
    importStudentMarks(studentVector);

    //Output all the students in the Vector along with all of their marks.
    for (auto student = studentVector.begin(); student != studentVector.end(); ++student) {
        cout << endl;
        if(student->getMarksMap().empty()){
            cout << student->getName() << " has registration number " << student->getRegNo() << " and has no available marks" << endl;
        }else{
            cout << student->getName() << " has registration number " << student->getRegNo() << " and has marks for these modules:" << endl;
            for (const auto &p : student->getMarksMap()) {
                cout << "" << p.first << ": " << p.second << endl;
            }
        }
    }

    //Menu system
    bool running = true;
    while(running) {
        int option;
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1 - Less than function" << endl;
        cout << "2 - Greater Than with Module Function" << endl;
        cout << "3 - Quit" << endl;
        cin >> option;

        //option 1 runs the first function studentLessAverage
        if (option == 1){
            float inputMark;
            cout << "Input a Mark to check: ";
            cin >> inputMark;
            studentsLessAverage(studentVector, inputMark);

        }else if(option == 2){
            float inputMark;
            string inputModule;
            cout << "Input a Module to check: ";
            cin >> inputModule;
            cout << "Input a Mark to check: ";
            cin >> inputMark;
            studentsModuleGreaterAverage(studentVector, inputModule, inputMark);
        }else if (option == 3){
            running = false;
        }else{
            cout << "Input invalid try again" << endl;
        }

    }



}
