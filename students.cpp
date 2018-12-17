#include "headerfiles/students.h"
#include <iostream>
#include "headerfiles/system.h"
#include <string>
using namespace std;
Students::Students(int sID, int RegYear, string Name, string SurN, string Dept, string Email, char* Phone) {
    this->sID = sID;
    this->Name = Name;
    this->RegYear = RegYear;
    this->SurN = SurN;
    this->Dept = Dept;
    this->Email = Email;
    for(int i=0;i<20;i++) {
        this->Phone[i] = Phone[i];
    }
};

int Students::getsID() {return this->sID;}
int Students::getRegYear() {return this->RegYear;}
string Students::getName() {return this->Name;}
string Students::getSurN() {return this->SurN;}
string Students::getDept() {return this->Dept;}
string Students::getEmail() { return this->Email;}
char* Students::getPhone() {return this->Phone;}