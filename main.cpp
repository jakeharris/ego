#include "scheduler.cpp"
#include "scrivener.cpp"

using namespace ego; //pretty egotistical, right?!

//Queue * wq; /* waiting queue -- these processes haven't started yet -- HEAD is the next process to launch */
//Queue * rq; /* ready queue -- these processes have started -- HEAD is the active process */
//Queue * ioq; /* IO job queue -- these are operations requested by processes */
Scrivener * scriv;

const std::string FILENAME = "Project 3 Tracefile";

void simulate(Scheduler *s);

int main() {
  Scheduler *sa = new Scheduler(ego::EXPONENTIAL);
  Scheduler *sb = new Scheduler(ego::STFCP);
  scriv = new Scrivener();

  simulate(sa);
  scriv->report();
  scriv->initialize();
  simulate(sb);
  
  scriv->report();

  return 0;
}
void tickHead(Queue * rq, Queue * wq) {
}
void completeHead(Queue * rq, Queue * wq) {
    if (rq->hasHead() && rq->getHead()->isComplete()) {
      std::cout << "head is complete" << std::endl;
      rq->getHead()->setFinishTime(scriv->clockTime());
      rq->pop();
    }
}
void ioComplete(Queue * ioq, Queue * rq, Queue * wq){ 
    if (ioq->hasHead() && ioq->getHead()->isComplete()) {
      std::cout << "io head is complete" << std::endl;
      ioq->getHead()->tick();
      wq->total_number_of_ticks = wq->total_number_of_ticks - 1;
    }
    else {
      std::cout << "io head is not complete" << std::endl;
      std::cout << ioq->getHead()->getName() << " Uh huh." << std::endl;
      std::string name = ioq->pop()->getName();
      wq->total_number_of_ticks = wq->total_number_of_ticks - 1;
      if (ioq->hasHead()) {
        rq->findByName(name).unblock();
        std::cout << "Slightly larger kitties.\n";
        ioq->getHead()->tick();
        wq->total_number_of_ticks = wq->total_number_of_ticks - 1;
        std::cout << "Lukewarm apple cider.\n";
      }
    }
}
void handleIO (Queue * ioq, Queue * rq) {
    std::cout << "Speaking of which, \n";
    if (rq->hasHead() && rq->getHead()->needsIO()) {
      std::cout << "head needs io" << std::endl;
      std::cout << "POW POW POW POW POW POW POW POW POW (LCD SOUNDSYSTEM)\n";
      ioq->push(rq->getHead());
      std::cout << "Playing GameBoy Advanced with my bros." << std::endl;
      rq->getHead()->block();
    }
}
void startJob (Queue * rq, Queue * wq) {
    if (wq->hasHead() && wq->getHead()->isReady(scriv->clockTime())) {
      std::cout << "waiting job needs starting" << std::endl;
      rq->addToFront(wq->pop());
    }
}
void simulate(Scheduler *s) {
  std::cout << "ABBA" << std::endl;
  Queue *wq = new Queue(FILENAME);
  std::cout << "BAAB" << std::endl;
  scriv->setNumJobs(wq->number_of_processes);
  std::cout << "wq made" << std::endl;
  Queue *rq = new Queue();
  std::cout << "rq made" << std::endl;
  Queue *ioq = new Queue();
  std::cout << "ioq made" << std::endl;
  s->activate();
  std::cout << "scheduler activated" << std::endl;
  std::cout << "BEGIN LOOP: " << std::endl;
  while(s->isActive() && wq->total_number_of_ticks > 0){

    std::cout << wq->total_number_of_ticks << " TICKS REMAINING\n";

    s->sort(rq);

    std::cout << "rq is sorted" << std::endl;

    scriv->tick();
    wq->total_number_of_ticks = wq->total_number_of_ticks - 1;

    std::cout << "scriv ticked" << std::endl;

    if(rq->hasHead()) {
      std::cout << "has head" << std::endl;
      rq->getHead()->tick(); /* keeps track of time spent running (does not count waiting for IO) */
      std::cout << "head ticked" << std::endl;
      wq->total_number_of_ticks = wq->total_number_of_ticks - 1;
    } 
    else { 
      startJob(rq, wq);
      continue; 
    }
    completeHead(rq, wq);
    ioComplete(ioq, rq, wq);
    handleIO(ioq, rq);
    startJob(rq, wq);

//Loop terminator

    if(rq->hasHead()){
      Node *temp = rq->getHead();
      if((temp->getProcessRunTime() - temp->getExpectedRunTime()) == 0){
        s->deactivate();
      }
    }

  }
} 
