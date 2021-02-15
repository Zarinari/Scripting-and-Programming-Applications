#include "student.h"

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::OTHER;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {};

//accessors
string Student::getID() { return this->studentID; }
string Student::getFirst() { return this->firstName; }
string Student::getLast() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->studentAge; }
int* Student::getDays() { return this->daysInCourse; }
DegreeProgram Student::getDegree() { return this->degreeProgram; }

//mutators
void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirst(string first) { this->firstName = first; }
void Student::setLast(string last) { this->lastName = last; }
void Student::setEmail(string email) { this->emailAddress = email; }
void Student::setAge(int age) { this->studentAge = age; }
void Student::setDays(int days[]) { for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = days[i]; }
void Student::setDegree(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::print() {
    std::cout << this->getID() << '\t';
    std::cout << "First Name: " << this->getFirst() << '\t';
    std::cout << "Last Name: " << this->getLast() << '\t';
    std::cout << "Age: " << this->getAge() << '\t';
    std::cout << "daysInCourse: {" << this->getDays()[0] <<", ";
    std::cout << this->getDays()[1] << ", ";
    std::cout << this->getDays()[2] << "}" << '\t';
    std::cout << "Degree Program: " << degreeProgramStrings[this->getDegree()] << "\n";
}
