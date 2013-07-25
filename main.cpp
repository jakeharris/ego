

using namespace ego; //pretty egotistical, right?!

Queue wq; /* waiting queue -- these processes haven't started yet -- HEAD is the next process to launch */
Queue rq; /* ready queue -- these processes have started -- HEAD is the active process */
IOQueue ioq; /* IO job queue -- these are operations requested by processes */
Scheduler sa;
Scheduler sb;
Launcher l;
Scrivener scriv;

const string FILENAME = "trace.txt";

void simulate(Scheduler s);

int main() {
  sa = new Scheduler(SchedulerType.EXPONENTIAL);
  sb = new Scheduler(SchedulerType.STCFP);
  l = new Launcher();
  scriv = new Scrivener();

  scriv.setup();

  simulate(sa);
  simulate(sb);
  
  scriv.report();

  return 0;
}

void simulate(Scheduler s) {
  wq = new Queue(FILENAME);
  rq = new Queue();
  ioq = new IOQueue();
  s.activate();
  while(s.isActive()){
    s.sort(rq);
    scriv.tick();
    rq.getHead().tick(); /* keeps track of time spent running (does not count waiting for IO) */
    if (rq.getHead().isComplete()) {
      rq.getHead().setFinishTime(scriv.clockTime());
      rq.getHead().pop();
    }
    if (!ioq.getHead().isComplete()) {
      ioq.getHead().tick();
    }
    else {
      rq.findByName(ioq.pop().name()).unblock();
      ioq.getHead().tick();
    }
    if (rq.getHead().needsIO()) {
      ioq.push(rq.getHead().name());
      rq.getHead().block();
    }
    if (wq.getHead().isReady()) {
      rq.push(wq.pop());
    }
  }
} 
