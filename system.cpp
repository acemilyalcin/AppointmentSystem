#include "headerfiles/system.h"
#include "headerfiles/students.h"
#include "headerfiles/academicians.h"
#include "headerfiles/appointments.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#define limitOfAppointment 10
using namespace std;

Appointments appointmentList[100];

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
    Students student(sID, RegYear, Name, SurN, Dept, Email, Phone); // Creating new object.
    addStudenttoFile(student); // The object sent to addStudenttoFile method for write to file.
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
    Academicians academician(aID, Appellation, Name, SurN, Dept, Email, Phone); // Creating new object.
    addAcademiciantoFile(academician); // The object sent to addStudenttoFile method for write to file.
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
    // Calculating line number of txt file.
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

void System::getAllAppointments() {
    fstream file;
    file.open(appointmentsFile);
    string d;
    int i=0,k=0;
    while(file >> d) {
        switch(i%5) {
            case 0:{appointmentList[k].setsID(stoi(d));break;}
            case 1:{appointmentList[k].setaID(stoi(d));break;}
            case 2:{appointmentList[k].setDate(d);break;}
            case 3:{appointmentList[k].setsOfClock(d);break;}
            case 4:{appointmentList[k].seteOfClock(d);k++;break;}
        }
        i++;
    }

    numberOfAppointments = i / 5;
}

bool System::setAppointment(string day, string sOfClock, int sID, int aID) {
    getAllAppointments();
    int j=0;
    string temps,tempe;
    bool f=true;
    Appointments tempAppointments[50];
    string hour = sOfClock.substr(0,2);
    string minute = sOfClock.substr(3,2);
    int minutes = stoi(minute);
    int hours = stoi(hour);
    for(int i=0;i<numberOfAppointments;i++) {
        if(appointmentList[i].getaID() == aID) {
            temps = appointmentList[i].getsOfClck();
            tempe = appointmentList[i].getDate();
            tempAppointments[j].setsOfClock(temps);
            tempAppointments[j].setDate(tempe);
            j++;
        }
    }
    for(int k=0;k<j;k++){
        string hour2 = tempAppointments[k].getsOfClck().substr(0,2);
        string minute2 = tempAppointments[k].getsOfClck().substr(3,2);
        int minutes2 = stoi(minute2);
        int hours2 = stoi(hour2);
        if(hours == hours2 && minutes == minutes2)
            return false;
    }
    return true;
}

void System::addNewAppointmenttoFile(string day, string sOfClock, int sID, int aID) {
    stringstream s1,s2;
    string hour = sOfClock.substr(0,2);
    string minute = sOfClock.substr(3,2);
    int minutes = (stoi(minute) + limitOfAppointment) % 60;
    int hours = stoi(hour) % 24;
    if (minutes == 0) hours++;
    s1 << hours;
    s2 << minutes;
    string eOfClock = s1.str() + ":" + s2.str();
    fstream file;
    file.open (this->appointmentsFile, fstream::in | fstream::out | fstream::app);
    file << endl << sID << " " << aID << " " << day << " " << sOfClock << " " << eOfClock;
    cout << "Appointment creation successfully." << endl;
}

void System::initializeAppoinment() {
    string day, sOfClock;
    int sID, aID;
    cout << "Enter student ID: ";
    cin >> sID;
    cout << "Enter academician ID: ";
    cin >> aID;
    cout << "Enter appointment day: ";
    cin >> day;
    cout << "Enter start of Appointment clock: ";
    cin >> sOfClock;
    getAllAppointments();
    bool res = setAppointment(day, sOfClock, sID, aID);
    if (res == 0) cout << "Appointment creation is failed.";
    else addNewAppointmenttoFile(day, sOfClock, sID, aID);
}