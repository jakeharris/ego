#include "enums.h"


namespace ego {
  class Scrivener {	
    SchedulerType alg;
    long int clock; //clock of alg 1
    long int clock2; //for lackof a better name, clock of alg 2
    long int runTime; //needs to reset before each queue uses it
    long int numJobs; //needs to reset before each queue uses it
    long double act; //Average Completion Time
    long double throughput; //Jobs per second
    long double util; //utilization
    long int use; //time doing usefull stuff
    
    public:
    Scrivener() {
      clock = 0;
      clock2 = 0;
      runTime = 0;
      numJobs = 0;
      act = 0;
      throughput = 0;
      util = 0;
    }

    long int clockTime() {
      if (alg == ego::EXPONENTIAL) {
        return clock;
    }
        return clock2;
    }

    long double calAct() {
      act = runTime / numJobs;//get runtime from node
      return act;
    }

    long double calThroughput() {//get info from node
      throughput = (numJobs / (runTime/1000);//per second so divide time by 1k?
      return throughput;
    }

    long int calUtil() {
      long double scale = 100.01;
      util = (use / runTime) * scale; //display as percentage and round to nearest hundredth, figure out how to get use time. possibly count everytime it's pushed?
      return util;
    }

    void iterJobs() { //iterates the job counter, call whenever a new job is added to the queue.
      numJobs++;
    }
		
    void tick() { //iterates the runtime counter
      runTime++;
    }
	
    void usageTime() { //iterates the time the process is actually used.
      use++;
    }

    void initialize() {
      clock = 0;
      clock2 = 0;
      runTime = 0;
      numJobs = 0;
      act = 0;
      throughput = 0;
      util = 0;
    }

    void report(){
      calAct();
      calThroughput();
      calUtil();
    }
  };
}
