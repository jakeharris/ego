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
        long int timesliceusage;//get this somehow
        //check for new job
        Node * head = q -> getHead();
        long int priority = head.getPriority();
        q.pop();
        long int timeSlice = (2^(priority - 1)) * 10;
        if ((timesliceusage < (timeSlice / 2) && priority != 1)) {
          priority--;
        }
        else if ((timesliceusage == timeSlice) && priority != 8) {
          priority++;
        }
        q.push(head);
    }
    
    void stfcpsort(Queue *q) {
    
    }
  };
}
