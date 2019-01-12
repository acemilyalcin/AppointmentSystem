#include "students.h"
#include "academicians.h"
#include <iostream>
#include <string>
using namespace std;
class System {
  public:
    System(string listOfStudents, string listOfAcademicians, string listofAppointments); // Class Constructor
    void showMenu(); // Showing menu.
    void getNewStudentInfo(); // Getting new student informations.
    void getNewAcademianInfo(); // Getting new academician informations.
    void addStudenttoFile(Students &s); // New student informations writing to file.
    void addAcademiciantoFile(Academicians &a); // New academicians informations writing to file.
    void getAllStudents(); // Getting all students.
    void initializeAppoinment(); // Getting new appointment informations.
    void getAllAppointments(); // Getting all appointments.
    bool setAppointment(string day, string sOfClock, int sID, int aID); // Setting new appointment.
    void addNewAppointmenttoFile(string day, string sOfClock, int sID, int aID); // New appointment informations writing to file.
  private:
    string studentsFile; // List of students file name
    string academiciansFile; // List of academicians file name
    string appointmentsFile; // List of appointments file name
    int numberOfAppointments;
};