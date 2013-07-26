#include <string>
#include <iostream>

namespace ego {
  class Node {
    std::string commandName;
    long int startTime;
    long int cpuTime;
    long int ioCount;

    long int runTime;
    long int finishTime;

    int priority;

    bool isBlocked;

    public:
    Node *next;

    Node(std::string cn, long int st, long int ct, long int ic) {
      commandName = cn;
      startTime = st;
      cpuTime = ct;
      ioCount = ic;
 
      runTime = 0;
      finishTime = 0;

      priority = 1;

      isBlocked = false;
      next = 0;
    }

    void tick() {
      runTime++;
    }

    void setFinishTime(long int ft) {
      finishTime = ft;
    }

    void block() {
      isBlocked = true;
    }


    void unblock() {
      isBlocked = false;
    }

    std::string getName() {
      return commandName;
    }

    void setPriority(int p) {
      priority = p;
    }

    int getPriority() {
      return priority;
    } 

    bool isComplete() {
      return runTime >= cpuTime;
    }

    bool needsIO() {
      return false;
    }

    bool isReady(long int currentTime) {
      return startTime >= currentTime;
    }

    void toString() {
      std::cout << "NODE CONTENTS:" << std::endl;
      std::cout << "Command: " << commandName << std::endl;
      std::cout << "Start time: " << startTime << std::endl;
      std::cout << "CPU time: " << cpuTime << std::endl;
      std::cout << "IO count: " << ioCount << std::endl;
    }
    
    int getExpectedRunTime() {
      // FIXME
      return 0;
    }
    
    int getProcessRunTime() {
      // FIXME
      return 0;
    }
  };
}
