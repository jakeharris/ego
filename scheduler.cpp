#include "queue.cpp"
#include "enums.h"

namespace ego {
  class Scheduler {
    bool active;
    SchedulerType st;
    public: 
    Scheduler(SchedulerType type) {
      active = false;
      st = type;
    }
    
    void sort(Queue *q) {
      switch(st){
        case ego::EXPONENTIAL:
          expsort(q);
          break;
        case ego::STFCP:
          stfcpsort(q);
          break;
      }
    }

    void expsort(Queue *q) {
        long int timesliceusage = 1;//get this somehow
        //check for new job if (q.newJob){
        //  q.moveToFront(head)
        //}
        //else {
        Node head = q -> pop();
        long int priority = head.getPriority();        
        long int timeSlice = (2^(priority - 1)) * 10;
        if ((timesliceusage < (timeSlice / 2) && priority != 1)) {
          priority--;
        }
        else if ((timesliceusage == timeSlice) && priority != 8) {
          priority++;
        }
        q->push(*head);
    }
    
    void stfcpsort(Queue *q) {
    
    }
    void activate() {
      active = true;
    }
    bool isActive() {
      return active;
    }
  };
}
