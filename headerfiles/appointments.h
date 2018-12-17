#ifndef APPOINTMENTS
#define APPOINTMENTS
#include <string>
class Appointments {
  public:
    Appointments();
  private:
    int sID; // Student id
    int aID; // Academician id
    int Date;
    int sOfClck; // Start of clock
    int eOfClck; // End of clock
};
#endif