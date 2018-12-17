#include "students.h"
#include <iostream>
#include <string>
using namespace std;
class System {
  public:
    System(char* listOfStudents, char* listOfAcademicians, char* listofAppointments); // Class Constructor
    void showMenu();
    void createNewStudent(int sID, int RegYear, string Name, string SurN, string Dept, string Email, char* Phone);
    void getNewStudentInfo();
    void addStudenttoFile(Students &s);
  private:
    string studentsFile; // List of students file name
    string academiciansFile; // List of academicians file name
    string appointmentsFile; // List of appointments file name
};