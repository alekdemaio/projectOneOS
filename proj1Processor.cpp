/*

Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           Mar 25, 2022
Description:    This is the processor class for proj1.
*/

class Processor {
private:
  int speed;
  int memory_capacity;
  bool being_used;
  int process_id;

  int service_time;
  int arrival_time;
  //int id_number;
  int wait_time;
  int memory_requirement;
  int total_time;



public:
  void setProcess_id(int x) {
    process_id = x;
  }

  int getProcess_id() {
    return process_id;
  }

  void setBeing_used(bool x) {
    being_used = x;
  }

  bool getBeing_used() {
    return being_used;
  }

  void setMemory_capacity(int x) {
    memory_capacity = x;
  }

  int getMemory_capacity() {
    return memory_capacity;
  }

  void setSpeed(int x) {
    speed = x;
  }

  int getSpeed() {
    return speed;
  }

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
