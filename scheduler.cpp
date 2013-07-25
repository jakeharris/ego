#include "queue.cpp"
#include "enums.cpp"

namespace ego {
  class Scheduler {
    bool active = false;
    SchedulerType st;
    public: 
    Scheduler(SchedulerType type) {
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
