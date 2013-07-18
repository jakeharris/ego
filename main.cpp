

using namespace ego; //pretty egotistical, right?!

Queue q;
Scheduler sa;
Scheduler sb;
Launcher l;
Scrivener scriv;

const string FILENAME = "trace.txt";

void simulate(Scheduler s);

int main() {
  q = new Queue(FILENAME);
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
  s.activate();
  while(s.isActive()){
    /* See page 2 of the project handout to determine what to do in this loop. */
  }
}
