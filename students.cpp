#include "headerfiles/students.h"
#include <iostream>
#include <fstream>
#include "headerfiles/system.h"
#include <string>
using namespace std;
Students::Students() {};
Students::Students(int sID, int RegYear, string Name, string SurN, string Dept, string Email, string Phone) {
    this->sID = sID;
    this->Name = Name;
    this->RegYear = RegYear;
    this->SurN = SurN;
    this->Dept = Dept;
    this->Email = Email;
    this->Phone = Phone;
};

int Students::getsID() {return this->sID;}
int Students::getRegYear() {return this->RegYear;}
string Students::getName() {return this->Name;}
string Students::getSurN() {return this->SurN;}
string Students::getDept() {return this->Dept;}
string Students::getEmail() { return this->Email;}
string Students::getPhone() {return this->Phone;}
void Students::setsID(int sID) {this->sID = sID;}
void Students::setRegYear(int RegYear) {this->RegYear = RegYear;}
void Students::setName(string Name) {this->Name = Name;}
void Students::setSurN(string SurN) {this->SurN = SurN;}
void Students::setDept(string Dept) {this->Dept = Dept;}
void Students::setEmail(string Email) {this->Email = Email;}
void Students::setPhone(string Phone) {this->Phone = Phone;}