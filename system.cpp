#include "headerfiles/system.h"
#include "headerfiles/students.h"
#include "headerfiles/academicians.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

System::System(string listOfStudents, string listOfAcademicians, string listofAppointments) { // Setting system start values.
    this->studentsFile = listOfStudents;
    this->academiciansFile = listOfAcademicians;
    this->appointmentsFile = listofAppointments;
    getAllStudents();
};

void System::showMenu() {
    cout << "New Person \t New Appointment - 1" << endl;
    cout << "Student - 2" << endl;
    cout << "Academicians - 3" << endl;

    cout << "Delete Person \t New Appointment - 1" << endl;
    cout << "Student - 4" << endl;
    cout << "Academicians - 5" << endl;

}

void System::getNewStudentInfo() {
    int sID, RegYear;
    string Name, SurN, Dept, Email, Phone;
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

void System::getNewAcademianInfo() {
    int aID;
    string Name, SurN, Dept, Email, Phone;
    string Appellation;
    cout << "New Academian ID: ";
    cin >> aID;
    cout << endl;
    cout << "New Academian Appellation: ";
    cin >> Appellation;
    cout << endl;
    cout << "New Academian Phone: ";
    cin >> Phone;
    cout << endl;
    cout << "New Academian Name: ";
    cin >> Name;
    cout << endl;
    cout << "New Academian Surname: ";
    cin >> SurN;
    cout << endl;
    cout << "New Academian Department: ";
    cin >> Dept;
    cout << endl;
    cout << "New Academian Email: ";
    cin >> Email;
    cout << endl;
    Academicians academician(aID, Appellation, Name, SurN, Dept, Email, Phone);
    addAcademiciantoFile(academician);
};

void System::addStudenttoFile(Students &s) {
    fstream file;
    file.open (this->studentsFile, fstream::in | fstream::out | fstream::app);
    file << s.getsID() << " " << s.getName() << " " << s.getSurN() << " " << s.getDept() << " " <<s.getRegYear() << " " << s.getEmail() << " " << s.getPhone() << endl; 
    file.close();
    cout << "Student successfully added." << endl;
};

void System::addAcademiciantoFile(Academicians &a) {
    fstream file;
    file.open (this->academiciansFile, fstream::in | fstream::out | fstream::app);
    file << a.getaID() << " " << a.getName() << " " << a.getSurN() << " " << a.getDept() << " " << a.getAppellation() << " " << a.getEmail() << " "  << a.getPhone() << endl; 
    file.close();
    cout << "Academician successfully added." << endl;
};

void System::getAllStudents() {
    ifstream file;
    file.open(this->studentsFile);
    string s;
    int tempInteger;
    int i=0;
    char c; 
    int line_no = 1;
    while (file.get(c)) 
    {
        if (c == '\n') 
        line_no++;  
    } 
    Students* students = new Students[line_no];
    while(!file.eof()) {
        file >> tempInteger;
        students[i].setsID(tempInteger);
        file >> s;
        students[i].setName(s);
        file >> s;
        students[i].setSurN(s);
        file >> s;
        students[i].setDept(s);
        file >> tempInteger;
        students[i].setRegYear(tempInteger);
        file >> s;
        students[i].setEmail(s);
        file >> s;
        students[i].setPhone(s);
        i++;
    }
}