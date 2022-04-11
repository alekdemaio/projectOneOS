/*

Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           Mar 25, 2022
Description:    This is the main file for proj1. It currently contains a menu
                as well as the options for executing different scenarios, as
                well as algorithms within each scenario.

*/

#include "proj1.h"
#include "proj1processClass.cpp"

int main() {

  int scenario = 0;
  int algorithm = 0;

  while (scenario != 99) {
    cout << "Which scenario?" << endl;
    cout << "  Scenario 1 (1)" << endl;
    cout << "  Scenario 2 (2)" << endl;
    cout << "  Scenario 3 (3)" << endl;
    cout << "  Scenario 4 (4)" << endl;
    cout << "  Exit       (99)" << endl;
    cin >> scenario;

    if (scenario == 1 || scenario == 2 || scenario == 3 || scenario == 4) {
      if (scenario == 1) {
        scenario = 99;

        cout << "Which algorithm?" << endl;
        cout << "  FIFO (1)" << endl;
        cout << "  SJF  (2)" << endl;
        cout << "  SRT  (3)" << endl;
        cout << "  RR   (4)" << endl;
        cout << "  ML   (5)" << endl;
        cout << "  Exit (99)" << endl;
        cin >> algorithm;

        while (algorithm != 99) {
          if  (algorithm == 1 || algorithm == 2 || algorithm == 3 || algorithm == 4 || algorithm == 5) {
            cout << "Success, continue here.";
            return 0;
          }
          else {
            cout << "Not a valid algorithm, try again." << endl;
            break;
          }
        }
      }
      else if (scenario == 2) {
        scenario = 99;

        cout << "Not completed yet, exiting." << endl;
        return 0;
      }
      else if (scenario == 3) {
        scenario = 99;

        cout << "Not completed yet, exiting." << endl;
        return 0;
      }
      else if (scenario == 4) {
        scenario = 99;

        cout << "Not completed yet, exiting." << endl;
        return 0;
      }
    }
    else {
      cout << "Not a valid scenario, try again." << endl;
      return 0;
    }
  }
  return 0;
}
