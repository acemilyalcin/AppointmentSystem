#include "headerfiles/appointments.h"
#include <iostream>
#include <string>
using namespace std;
Appointments::Appointments() {};
void Appointments::setsID(int sID) {this->sID = sID;}
void Appointments::setaID(int aID) {this->aID = aID;}
void Appointments::setDate(string date) {this->Date = date;}
void Appointments::setsOfClock(string sOfClck) {this->sOfClck = sOfClck;}
void Appointments::seteOfClock(string eOfClck) {this->eOfClck = eOfClck;}
int Appointments::getsID() {return this->sID;}
int Appointments::getaID() {return this->aID;}
string Appointments::getsOfClck() {return this->sOfClck;}
string Appointments::getDate() {return this->Date;}
string Appointments::geteOfClck() {return this->eOfClck;}