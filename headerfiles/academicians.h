#ifndef ACADEMICIANS
#define ACADEMICIANS
#include <string>
#include "../person.cpp"
class Academicians : public Person{
  public:
    Academicians(); // Class Constructor
  private:
    int aID; // Academician
    string Appellation;
};
#endif