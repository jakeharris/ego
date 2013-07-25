#include "scheduler.cpp"
#include "scrivener.cpp"

using namespace ego; //pretty egotistical, right?!

Queue * wq; /* waiting queue -- these processes haven't started yet -- HEAD is the next process to launch */
Queue * rq; /* ready queue -- these processes have started -- HEAD is the active process */
Queue * ioq; /* IO job queue -- these are operations requested by processes */
Scrivener * scriv;

const std::string FILENAME = "Project 3 Tracefile";

void simulate(Scheduler *s);

int main() {
  Scheduler *sa = new Scheduler(ego::EXPONENTIAL);
  Scheduler *sb = new Scheduler(ego::STFCP);
  scriv = new Scrivener();

  simulate(sa);
  simulate(sb);
  
  scriv->report();

  return 0;
}

void simulate(Scheduler *s) {
  wq = new Queue(FILENAME);
  rq = new Queue();
  ioq = new Queue();
  s->activate();
  while(s->isActive()){
    s->sort(rq);
    scriv->tick();
    rq->getHead().tick(); /* keeps track of time spent running (does not count waiting for IO) */
    if (rq->getHead().isComplete()) {
      rq->getHead().setFinishTime(scriv->clockTime());
      rq->pop();
    }
    if (!ioq->getHead().isComplete()) {
      ioq->getHead().tick();
    }
    else {
      rq->findByName(ioq->pop().getName()).unblock();
      ioq->getHead().tick();
    }
    if (rq->getHead().needsIO()) {
      ioq->push(rq->getHead().getName());
      rq->getHead().block();
    }
    if (wq->getHead().isReady(scriv->clockTime())) {
      rq->addToFront(wq->pop());
    }
  }
} 
