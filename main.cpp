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
  std::cout << "wq made" << std::endl;
  rq = new Queue();
  std::cout << "rq made" << std::endl;
  ioq = new Queue();
  std::cout << "ioq made" << std::endl;
  s->activate();
  std::cout << "scheduler activated" << std::endl;
  std::cout << "BEGIN LOOP: " << std::endl;
  while(s->isActive()){
    s->sort(rq);
    std::cout << "rq is sorted" << std::endl;
    scriv->tick();
    std::cout << "scriv ticked" << std::endl;
    if(rq->hasHead()) {
      std::cout << "has head" << std::endl;
      rq->getHead().tick(); /* keeps track of time spent running (does not count waiting for IO) */
<<<<<<< HEAD
    } else { continue; }
=======
    }
>>>>>>> 0fe0e2a8208b73cdac6dec8cf7cf8e5b325e323d
    std::cout << "head ticked" << std::endl;
    if (rq->hasHead() && rq->getHead().isComplete()) {
      std::cout << "head is complete" << std::endl;
      rq->getHead().setFinishTime(scriv->clockTime());
      rq->pop();
    }
    if (ioq->hasHead() && !ioq->getHead().isComplete()) {
      std::cout << "io head is complete" << std::endl;
      ioq->getHead().tick();
    }
    else {
      std::cout << "io head is not complete" << std::endl;
      std::cout << ioq->getHead().getName() << " Uh huh." << std::endl;
      std::string name = ioq->pop()->getName();
      if (ioq->hasHead()) {
        rq->findByName(name).unblock();
        std::cout << "Slightly larger kitties.\n";
        ioq->getHead().tick();
        std::cout << "Lukewarm apple cider.\n";
      }
    }
    std::cout << "Speaking of which, \n";
    if (rq->hasHead() && rq->getHead().needsIO()) {
      std::cout << "head needs io" << std::endl;
      std::cout << "POW POW POW POW POW POW POW POW POW (LCD SOUNDSYSTEM)\n";
      ioq->push(rq->getHead().getName());
      std::cout << "Playing GameBoy Advanced with my bros." << std::endl;
      rq->getHead().block();
    }
    if (wq->hasHead() && wq->getHead().isReady(scriv->clockTime())) {
      std::cout << "waiting job needs starting" << std::endl;
      rq->addToFront(wq->pop());
    }
  }
} 
