#include <iostream>
#include <iostream>
#include "headerfiles/system.h"

using namespace std;

int main(int argc,char* args[]) {
    if(args[1] == NULL || args[2] == NULL || args[3] == NULL) { // Checking parameters
        cout << "Please check your parameters.";
        return 0;
    } 
    System sys1(args[1],args[2],args[3]); // Created system
    sys1.showMenu(); // Showing menu
    cout << "Please select an option" << endl;
    int option = 0;
    cin >> option;
    switch(option) {
        case 2: sys1.getNewStudentInfo();
    }
    return 0;
}