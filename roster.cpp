#include "roster.h"
using std::string;
using std::stoi;
using std::cout;

void Roster::parse(string studentdata) {
    DegreeProgram dp = OTHER;
    if (studentdata.back() == 'Y') dp = SECURITY;
    else if (studentdata.back() == 'K') dp == NETWORK;
    else if (studentdata.back() == 'E') dp == SOFTWARE;
    
    int rhs = studentdata.find(",");
    string sID = studentdata.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string fst = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lst = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string eml = studentdata.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int ag = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d1 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d2 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d3 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    add(sID, fst, lst, eml, ag, d1, d2, d3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp) {
    int darr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, studentAge, darr, dp);
}

void Roster::remove(string studentID) {
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++ {
        if (classRosterArray[i]->getID() == studentID) {
            success = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success) {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

void Roster::printAll() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram dp) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegree() == dp) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string sID = (classRosterArray[i]->getID());
        string sEmail = (classRosterArray[i]->getEmail());
        if (sEmail.find(' ') == string::npos && (sEmail.find('@') == string::npos || sEmail.find('.') == string::npos)) {
            any = true;
            cout << sID << ": " << classRosterArray[i]->getEmail() << std::endl;
        }
    }
    if (!any) cout << "No invalid emails found." << std::endl;
}

void Roster::printAverageDaysInCourse(string sID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getID() == sID) {
            cout << sID << ": ";
            cout << (classRosterArray[i]->getDays()[0]
                + classRosterArray[i]->getDays()[1]
                + classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
        }
    }
}

Roster::~Roster() {
    cout << "Activating destructor: " << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Deleting student A" << i + 1 << " from roster." << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}   
