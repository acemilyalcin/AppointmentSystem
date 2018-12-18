#ifndef STUDENT
#define STUDENT
#include <string>
#include "../person.cpp"
using namespace std;
class Students : private Person{
  public:
    Students(); // Class contructor
    Students(int sID, int RegYear, string Name, string SurN, string Dept, string Email, string Phone);
    int getsID(); // Get method for student id
    int getRegYear(); // Get method for student register year
    string getName(); // Get method for student name
    string getSurN(); // Get method for student surname
    string getDept(); // Get method for student department
    string getEmail(); // Get method for student email
    string getPhone(); // Get method for student phone
    void setsID(int sID);
    void setRegYear(int RegYear);
    void setName(string Name);
    void setSurN(string SurN);
    void setDept(string Dept);
    void setEmail(string Email);
    void setPhone(string Phone);
  private:
    int sID;
    int RegYear;
};
#endif