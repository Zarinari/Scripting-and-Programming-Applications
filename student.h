#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::cout;
using std::string;

class Student {
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int daysInCourse[daysArraySize];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    //accessors
    string getID();
    string getFirst();
    string getLast();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegree();
    
    //mutators
    void setID(string ID);
    void setFirst(string first);
    void setLast(string last);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegree(DegreeProgram dp);
    
    void print();
    
};
