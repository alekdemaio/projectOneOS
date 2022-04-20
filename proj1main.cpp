/*

Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           Mar 25, 2022
Description:    This is the main file for proj1. It currently contains a menu
                as well as the options for executing different scenarios, as
                well as algorithms within each scenario.

*/

#include "proj1.h"
#include "proj1processClass.cpp"
#include "proj1Processor.cpp"

int main() {

  int scenario = 0;
  int algorithm = 0;

  // mersenne twister engine & uniform_int_distribution
  mt19937_64 gen;
  //uniform_int_distribution<> distrib(10e6,10e12);
  uniform_int_distribution<> distrib(0,1e7);


  // processes & processors
  Process process[50];
  int process_iterator = 0;
  Processor processor[4];

  // seed value
  cout << "Enter a 'Seed Value'" << endl;
  int seed = -1;
  cin >> seed;

  //seeding rand
  srand(time(NULL));


  // seeding mersenne twister
  gen.seed(seed);
  // need to resolve why some of these random numbers are negative
  //    cout << distrib(gen) << endl;

  // create processes
  for(int i=0; i<50; ++i) {
    process[i].setService_time(distrib(gen)+1e7);
    process[i].setArrival_time(rand()%(10*10*10)+1);
    process[i].setMemory_requirement(rand()%8+1);
    process[i].setId_number(i);
  }

  for(int i=0; i<50; ++i) {
    cout << "Process " << i+1 << endl;
    cout << process[i].getService_time() << " ";
    cout << process[i].getArrival_time() << " ";
    cout << process[i].getMemory_requirement() << " ";
    cout << process[i].getId_number() << endl;
  }



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
            if (algorithm == 1) { //FIFO - Scenario 1
              cout << "Success, continue here." << endl;

              // put processes into a queue
              queue<Process> process_queue;
              for(int i=0; i<50; ++i) {
                process_queue.push(process[i]);
              }
              Process popped_process;

              //queue of processors for printout
              queue<Processor> processor_print_queue;

              // create processors
              for(int i=0; i<4; ++i) {
                processor[i].setSpeed(3);
                processor[i].setMemory_capacity(8);
                processor[i].setProcess_id(-1);
                processor[i].setBeing_used(false);
              }

              for(int i=0; i<4; ++i) {
                cout << "Processor " << i+1 << endl;
                cout << processor[i].getSpeed() << " ";
                cout << processor[i].getMemory_capacity() << " ";
                cout << processor[i].getProcess_id() << " ";
                cout << processor[i].getBeing_used() << endl;
              }

              while(!(process_queue.empty())) {
                if(processor[0].getBeing_used()==0) {
                  popped_process = process_queue.front();
                  process_queue.pop();
                  processor[0].setProcess_id(popped_process.getId_number());
                  processor[0].setService_time(popped_process.getService_time());
                  processor[0].setWait_time(0);
                  processor[0].setArrival_time(0);
                  processor[0].setTotal_time(0);
                  processor[0].setBeing_used(1);
                }
                if(processor[1].getBeing_used()==0) {
                  popped_process = process_queue.front();
                  process_queue.pop();
                  processor[1].setProcess_id(popped_process.getId_number());
                  processor[1].setService_time(popped_process.getService_time());
                  processor[1].setWait_time(0);
                  processor[1].setArrival_time(0);
                  processor[1].setTotal_time(0);
                  processor[1].setBeing_used(1);
                }
                if(processor[2].getBeing_used()==0) {
                  popped_process = process_queue.front();
                  process_queue.pop();
                  processor[2].setProcess_id(popped_process.getId_number());
                  processor[2].setService_time(popped_process.getService_time());
                  processor[2].setWait_time(0);
                  processor[2].setArrival_time(0);
                  processor[2].setTotal_time(0);
                  processor[2].setBeing_used(1);
                }
                if(processor[3].getBeing_used()==0) {
                  popped_process = process_queue.front();
                  process_queue.pop();
                  processor[3].setProcess_id(popped_process.getId_number());
                  processor[3].setService_time(popped_process.getService_time());
                  processor[3].setWait_time(0);
                  processor[3].setArrival_time(0);
                  processor[3].setTotal_time(0);
                  processor[3].setBeing_used(1);
                }

                for(int i=0; i<4; ++i) {
                  cout << "Processor " << i+1 << endl;
                  cout << processor[i].getSpeed() << " ";
                  cout << processor[i].getMemory_capacity() << " ";
                  cout << processor[i].getProcess_id() << " ";
                  cout << processor[i].getService_time() << " ";
                  cout << processor[i].getWait_time() << " ";
                  cout << processor[i].getArrival_time() << " ";
                  cout << processor[i].getTotal_time() << " ";
                  cout << processor[i].getBeing_used() << endl;
                }

                if (processor[0].getService_time()>9999999 &&
                    processor[1].getService_time()>9999999 &&
                    processor[2].getService_time()>9999999 &&
                    processor[3].getService_time()>9999999) {
                      processor[0].setService_time(processor[0].getService_time()-10000000);
                      processor[1].setService_time(processor[0].getService_time()-10000000);
                      processor[2].setService_time(processor[0].getService_time()-10000000);
                      processor[3].setService_time(processor[0].getService_time()-10000000);

                      processor[0].setTotal_time(processor[0].getTotal_time()+10000000);
                      processor[1].setTotal_time(processor[0].getTotal_time()+10000000);
                      processor[2].setTotal_time(processor[0].getTotal_time()+10000000);
                      processor[3].setTotal_time(processor[0].getTotal_time()+10000000);
                }
                else if (processor[0].getService_time()>999999 &&
                        processor[1].getService_time()>999999 &&
                        processor[2].getService_time()>999999 &&
                        processor[3].getService_time()>999999) {
                          processor[0].setService_time(processor[0].getService_time()-1000000);
                          processor[1].setService_time(processor[0].getService_time()-1000000);
                          processor[2].setService_time(processor[0].getService_time()-1000000);
                          processor[3].setService_time(processor[0].getService_time()-1000000);

                          processor[0].setTotal_time(processor[0].getTotal_time()+1000000);
                          processor[1].setTotal_time(processor[0].getTotal_time()+1000000);
                          processor[2].setTotal_time(processor[0].getTotal_time()+1000000);
                          processor[3].setTotal_time(processor[0].getTotal_time()+1000000);
                }
                else if (processor[0].getService_time()>99999 &&
                        processor[1].getService_time()>99999 &&
                        processor[2].getService_time()>99999 &&
                        processor[3].getService_time()>99999) {
                          processor[0].setService_time(processor[0].getService_time()-100000);
                          processor[1].setService_time(processor[0].getService_time()-100000);
                          processor[2].setService_time(processor[0].getService_time()-100000);
                          processor[3].setService_time(processor[0].getService_time()-100000);

                          processor[0].setTotal_time(processor[0].getTotal_time()+100000);
                          processor[1].setTotal_time(processor[0].getTotal_time()+100000);
                          processor[2].setTotal_time(processor[0].getTotal_time()+100000);
                          processor[3].setTotal_time(processor[0].getTotal_time()+100000);
                }
                else if (processor[0].getService_time()>9999 &&
                        processor[1].getService_time()>9999 &&
                        processor[2].getService_time()>9999 &&
                        processor[3].getService_time()>9999) {
                          processor[0].setService_time(processor[0].getService_time()-10000);
                          processor[1].setService_time(processor[0].getService_time()-10000);
                          processor[2].setService_time(processor[0].getService_time()-10000);
                          processor[3].setService_time(processor[0].getService_time()-10000);

                          processor[0].setTotal_time(processor[0].getTotal_time()+10000);
                          processor[1].setTotal_time(processor[0].getTotal_time()+10000);
                          processor[2].setTotal_time(processor[0].getTotal_time()+10000);
                          processor[3].setTotal_time(processor[0].getTotal_time()+10000);
                }
                else if (processor[0].getService_time()>999 &&
                        processor[1].getService_time()>999 &&
                        processor[2].getService_time()>999 &&
                        processor[3].getService_time()>999) {
                          processor[0].setService_time(processor[0].getService_time()-1000);
                          processor[1].setService_time(processor[0].getService_time()-1000);
                          processor[2].setService_time(processor[0].getService_time()-1000);
                          processor[3].setService_time(processor[0].getService_time()-1000);

                          processor[0].setTotal_time(processor[0].getTotal_time()+1000);
                          processor[1].setTotal_time(processor[0].getTotal_time()+1000);
                          processor[2].setTotal_time(processor[0].getTotal_time()+1000);
                          processor[3].setTotal_time(processor[0].getTotal_time()+1000);
                }
                else if (processor[0].getService_time()>99 &&
                        processor[1].getService_time()>99 &&
                        processor[2].getService_time()>99 &&
                        processor[3].getService_time()>99) {
                          processor[0].setService_time(processor[0].getService_time()-100);
                          processor[1].setService_time(processor[0].getService_time()-100);
                          processor[2].setService_time(processor[0].getService_time()-100);
                          processor[3].setService_time(processor[0].getService_time()-100);

                          processor[0].setTotal_time(processor[0].getTotal_time()+100);
                          processor[1].setTotal_time(processor[0].getTotal_time()+100);
                          processor[2].setTotal_time(processor[0].getTotal_time()+100);
                          processor[3].setTotal_time(processor[0].getTotal_time()+100);
                }
                else if (processor[0].getService_time()>9 &&
                        processor[1].getService_time()>9 &&
                        processor[2].getService_time()>9 &&
                        processor[3].getService_time()>9) {
                          processor[0].setService_time(processor[0].getService_time()-10);
                          processor[1].setService_time(processor[0].getService_time()-10);
                          processor[2].setService_time(processor[0].getService_time()-10);
                          processor[3].setService_time(processor[0].getService_time()-10);

                          processor[0].setTotal_time(processor[0].getTotal_time()+10);
                          processor[1].setTotal_time(processor[0].getTotal_time()+10);
                          processor[2].setTotal_time(processor[0].getTotal_time()+10);
                          processor[3].setTotal_time(processor[0].getTotal_time()+10);
                }
                else {
                  processor[0].setService_time(processor[0].getService_time()-1);
                  processor[1].setService_time(processor[0].getService_time()-1);
                  processor[2].setService_time(processor[0].getService_time()-1);
                  processor[3].setService_time(processor[0].getService_time()-1);

                  processor[0].setTotal_time(processor[0].getTotal_time()+1);
                  processor[1].setTotal_time(processor[0].getTotal_time()+1);
                  processor[2].setTotal_time(processor[0].getTotal_time()+1);
                  processor[3].setTotal_time(processor[0].getTotal_time()+1);
                }

                if(processor[0].getService_time()<=0) {
                  processor_print_queue.push(processor[0]);
                  processor[0].setBeing_used(0);
                }
                if(processor[1].getService_time()<=0) {
                  processor_print_queue.push(processor[1]);
                  processor[1].setBeing_used(0);
                }
                if(processor[2].getService_time()<=0) {
                  processor_print_queue.push(processor[2]);
                  processor[2].setBeing_used(0);
                }
                if(processor[3].getService_time()<=0) {
                  processor_print_queue.push(processor[3]);
                  processor[3].setBeing_used(0);
                }
              }

              //cout << "All arrival times are zero and memory requirements are constant" << endl;
              Processor processor_print;
              while(!(processor_print_queue.empty())) {
                processor_print = processor_print_queue.front();
                processor_print_queue.pop();
                cout << "ID:            " << processor_print.getProcess_id() << endl;
                cout << "Wait:          " << processor_print.getWait_time() << endl;
                cout << "Service Time:  " << processor_print.getTotal_time() << endl;
              }
            }
            if (algorithm == 2) {cout << "Not a valid algorithm, try again." << endl;}
            if (algorithm == 3) { // SRT - Scenario 1
              cout << "Success, continue here." << endl;
            }
            if (algorithm == 4) {cout << "Not a valid algorithm, try again." << endl;}
            if (algorithm == 5) {cout << "Not a valid algorithm, try again." << endl;}
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
