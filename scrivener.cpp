#include "enums.h"


namespace ego {
  class Scrivener {	
    SchedulerType alg;
    long int clock; //clock of alg 1
    long int clock2; //for lackof a better name, clock of alg 2
    long int runTime; //needs to reset before each queue uses it
    long int numJobs; //needs to reset before each queue uses it
    long int use; //time doing usefull stuff
    long double act; //
    long double throughput; //
    long double util; //
    
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
      clock = 0;
      clock2 = 0;
      if (alg == ego::EXPONENTIAL) {
        clock = runTime;
        return clock;
    }
        clock2 = runTime;
        return clock2;
    }

    void resetClock() {
      runTime = 0;
    }

    long double calAct() {
      act = runTime / numJobs;//get runtime from node
      return act;
    }

    long double calThroughput() {//get info from node
      throughput = (numJobs / (runTime/1000));//per second so divide time by 1k?
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

    void setusageTime(long int x) {
      use = x;
    }

    void setNumJobs(long int x) {
      numJobs = x;
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
