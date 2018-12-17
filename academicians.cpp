#include "headerfiles/academicians.h"
#include <iostream>
#include "headerfiles/system.h"
#include <string>

using namespace std;
Academicians::Academicians(int aID, string Appellation, string Name, string SurN, string Dept, string Email, char* Phone) {
    this->aID = aID;
    this->Name = Name;
    this->Appellation = Appellation;
    this->SurN = SurN;
    this->Dept = Dept;
    this->Email = Email;
    for(int i=0;i<20;i++) {
        this->Phone[i] = Phone[i];
    }
};

int Academicians::getaID() {return this->aID;}
string Academicians::getAppellation() {return this->Appellation;}
string Academicians::getName() {return this->Name;}
string Academicians::getSurN() {return this->SurN;}
string Academicians::getDept() {return this->Dept;}
string Academicians::getEmail() { return this->Email;}
char* Academicians::getPhone() {return this->Phone;}