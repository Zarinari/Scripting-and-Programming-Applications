#pragma once
#include "student.h"

class Roster {
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    void parse(string row);
    void add(string sID,
        string sFirst,
        string sLast, 
        string sEmail,
        int sAge,
        int sDays1,
        int sDays2,
        int sDays3,
        DegreeProgram dp);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};
