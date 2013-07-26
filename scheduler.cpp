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
        q->push(&head);
    }
    
    void stfcpsort(Queue *q) {
      Node current = q->getHead();
      Node temp;
      bool sorted = false;
      bool switchMade;
      /*check if process has been finished before if so
        then place it at the end of the linked list */
      if((current.getExpectedRunTime() - current.getProcessRunTime()) == 0){
        temp = q->pop();
        q->push(temp);
      }
      else{
        //sort the linked list with this loop
        while(sorted == false){
          switchMade = false;
          //parse through the list with this loop
          while(current){
            //return if at the end of the list
            if(current.next() == NULL) {
              return;
            }
            temp = current.next();
            //return if at the items in the list that have already been run
            if((temp.getExpectedRunTime() - temp.getProcessRunTime()) == 0){
              return;
            }
            /*compare current with next to check which has a larger cpu burst time
              if current is larger then move temp to the front of the linked list. */
            if((current.getExpectedRunTime() - current.getProcessRunTime()) > (temp.getExpectedRunTime() - temp.getProcessRunTime())){
              current.setNextNode(temp.next());
              q->addToFront(temp); 
              switchMade = true;
            }
            current = current.next();
          }
          //loop exit condition
          if(switchMade == false){
            sorted = true;
          }
        }
      }
    }
  }
      
    }
    void activate() {
      active = true;
    }
    bool isActive() {
      return active;
    }
  };
}
