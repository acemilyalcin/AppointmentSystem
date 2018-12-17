#include "headerfiles/system.h"
#include "headerfiles/students.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

System::System(char* listOfStudents, char* listOfAcademicians, char* listofAppointments) { // Setting system start values.
    this->studentsFile = listOfStudents;
    this->academiciansFile = academiciansFile;
    this->appointmentsFile = appointmentsFile;
};

void System::showMenu() {
    cout << "New Person \t New Appointment - 1" << endl;
    cout << "Student - 2" << endl;
    cout << "Academicians - 3" << endl;
}

void System::getNewStudentInfo() {
    int sID, RegYear;
    char Phone[12];
    string Name, SurN, Dept, Email;
    cout << "New Student ID: ";
    cin >> sID;
    cout << endl;
    cout << "New Student Register Year: ";
    cin >> RegYear;
    cout << endl;
    cout << "New Student Phone: ";
    cin >> Phone;
    cout << endl;
    cout << "New Student Name: ";
    cin >> Name;
    cout << endl;
    cout << "New Student Surname: ";
    cin >> SurN;
    cout << endl;
    cout << "New Student Department: ";
    cin >> Dept;
    cout << endl;
    cout << "New Student Email: ";
    cin >> Email;
    cout << endl;
    Students student(sID, RegYear, Name, SurN, Dept, Email, Phone);
    addStudenttoFile(student);
};

void System::addStudenttoFile(Students &s) {
    fstream file;
    file.open (this->studentsFile, fstream::in | fstream::out | fstream::app);
    file << s.getsID() << " " << s.getName() << " " << s.getSurN() << " " << s.getDept() << " " <<s.getRegYear() << " " << s.getEmail() << " " << s.getPhone() << endl; 
    file.close();
    cout << "Student successfully added." << endl;
};