#include "roster.h"

int main() {
    cout << "Scripting and Programming - Applications - C867 | C++ | #001220083 | Hannah Sullivant" << std::endl << std::endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Hannah,Sullivant,hsull24@wgu.edu,23,45,30,60,SOFTWARE"
    };
    
    const int numStudents = 5;
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying student roster: " << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    cout << "Displaying invalid email addresses: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
   
    cout << "Displaying average days in courses: " << std::endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    };
    cout << std::endl;
    
    cout << "Displaying by degree program: " << degreeProgramStrings[2];
    classRoster.printByDegreeProgram((DegreeProgram)2);
    
    cout << "Removing student A3: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    cout << "Removing student A3: " << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    system("pause");
    
    return 0;
}
