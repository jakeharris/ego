

using namespace ego; //pretty egotistical, right?!

Queue wq; /* waiting queue -- these processes haven't started yet -- HEAD is the next process to launch */
Queue rq; /* ready queue -- these processes have started -- HEAD is the active process */
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

void simulate(Scheduler s){
  wq = new Queue(FILENAME);
  rq = new Queue;
  s.activate();
  while(s.isActive()){
    /* See page 2 of the project handout to determine what to do in this loop. */
  }
}
