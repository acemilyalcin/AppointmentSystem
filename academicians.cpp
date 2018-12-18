#include "headerfiles/academicians.h"
#include <iostream>
#include "headerfiles/system.h"
#include <string>

using namespace std;
Academicians::Academicians(int aID, string Appellation, string Name, string SurN, string Dept, string Email, string Phone) {
    this->aID = aID;
    this->Name = Name;
    this->Appellation = Appellation;
    this->SurN = SurN;
    this->Dept = Dept;
    this->Email = Email;
    this->Phone = Phone;
};

int Academicians::getaID() {return this->aID;}
string Academicians::getAppellation() {return this->Appellation;}
string Academicians::getName() {return this->Name;}
string Academicians::getSurN() {return this->SurN;}
string Academicians::getDept() {return this->Dept;}
string Academicians::getEmail() { return this->Email;}
string Academicians::getPhone() {return this->Phone;}