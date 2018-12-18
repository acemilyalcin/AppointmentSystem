#include "students.h"
#include "academicians.h"
#include <iostream>
#include <string>
using namespace std;
class System {
  public:
    System(string listOfStudents, string listOfAcademicians, string listofAppointments); // Class Constructor
    void showMenu();
    void getNewStudentInfo();
    void getNewAcademianInfo();
    void addStudenttoFile(Students &s);
    void addAcademiciantoFile(Academicians &a);
    void getAllStudents();
  private:
    string studentsFile; // List of students file name
    string academiciansFile; // List of academicians file name
    string appointmentsFile; // List of appointments file name
};