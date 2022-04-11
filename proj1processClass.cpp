/*

Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           Mar 25, 2022
Description:    This is the process class for proj1.
*/

class Process {
private:
  int service_time;
  int arrival_time;
  int id_number;
  int wait_time;
  int memory_requirement;
  int total_time;

public:
  void setService_time (int x) {
    service_time = x;
  }
  int getService_time() {
    return service_time;
  }

  void setArrival_time (int x) {
    arrival_time = x;
  }
  int getArrival_time() {
    return arrival_time;
  }

  void setId_number (int x) {
    id_number = x;
  }
  int getId_number() {
    return id_number;
  }

  void setWait_time (int x) {
    wait_time = x;
  }
  int getWait_time() {
    return wait_time;
  }

  void setMemory_requirement (int x) {
    memory_requirement = x;
  }
  int getMemory_requirement() {
    return memory_requirement;
  }

  void setTotal_time (int x) {
    total_time = x;
  }
  int getTotal_time() {
    return total_time;
  }
};
