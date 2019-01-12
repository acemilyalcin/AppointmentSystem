#ifndef APPOINTMENTS
#define APPOINTMENTS
#include <string>
using namespace std;
class Appointments {
  public:
    Appointments();
    void setsID(int sID);
    void setaID(int aID);
    void setDate(string date);
    void setsOfClock(string sOfClock);
    void seteOfClock(string eOfClck);
    int getsID();
    int getaID();
    string getDate();
    string getsOfClck();
    string geteOfClck();
  private:
    int sID; // Student id
    int aID; // Academician id
    string Date;
    string sOfClck; // Start of clock
    string eOfClck; // End of clock
};
#endif