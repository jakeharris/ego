#include "enums.cpp"
#include "queue.cpp"

namespace ego {
  class Scheduler {

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
  };
}
