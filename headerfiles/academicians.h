#ifndef ACADEMICIANS
#define ACADEMICIANS
#include <string>
#include "../person.cpp"
class Academicians : private Person{
  public:
    Academicians(); // Class contructor
    Academicians(int aID, string Appellation, string Name, string SurN, string Dept, string Email, char* Phone);
    int getaID(); // Get method for academian id
    string getAppellation(); // Get method for academian register year
    string getName(); // Get method for academian name
    string getSurN(); // Get method for academian surname
    string getDept(); // Get method for academian department
    string getEmail(); // Get method for academian email
    char* getPhone(); // Get method for academian phone
  private:
    int aID; // Academician id
    string Appellation;
};
#endif