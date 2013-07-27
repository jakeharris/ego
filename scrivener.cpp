#include "enums.h"
#include "node.cpp"

#include <iostream>

namespace ego {
  class Scrivener {	
    SchedulerType alg;
    long int clock; //clock of alg 1
    long int clock2; //for lackof a better name, clock of alg 2
    long int runTime; //needs to reset before each queue uses it
    long int numJobs; //needs to reset before each queue uses it
    long int use; //time doing usefull stuff
    long int finishTime;
    long int max;
    long int min;
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
    if (alg == ego::EXPONENTIAL) {
        clock = runTime;
        return clock;
      }
      clock2 = runTime;
      return clock2;
    }

    long double calAct() {
      act = finishTime / numJobs;
      return act;
    }

    long double calThroughput() {
      throughput = (numJobs / (runTime/1000));
      return throughput;
    }

    long int calUtil() {
      long double scale = 100.01;
      util = (use / runTime) * scale;
      return util;
    }

    void iterJobs() { 
      numJobs++;
    }
		
    void tick() { 
      runTime++;
    }
	
    void usageTime() { 
      use++;
    }

    void nodeInfo(Node *n) {
      finishTime = finishTime + n -> getFinishTime();
      temp = n -> getProcessRunTime();

      if(temp > max) max = temp;
      if(temp < min) min = temp;       
    }

    void setusageTime(long int x) {
      use = use + x;
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
      std::cout << "Average completion time: " << calAct() << std::endl;
      std::cout << "Maximum completion time: " << max << std::endl;
      std::cout << "Minumun completion time: " << min << std::endl;
      std::cout << "Number of jobs per second: " << calThroughput() << std::endl;
      std::cout << "Number of useful jobs per second: " << use << std::endl;
      std::cout << "Percentage of useful actions compared to total run time: " << calUtil() << std::endl;
    }
  };
}
