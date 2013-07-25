#include <string>
#include <iostream>

namespace ego {
  class Node {
    std::string commandName;
    int startTime;
    int cpuTime;
    int ioCount;

    int runTime;
    public:
    Node *next;

    Node(std::string cn, long int st, long int ct, long int ic) {
      commandName = cn;
      startTime = st;
      cpuTime = ct;
      ioCount = ic;
    }

    void tick() {
      runTime++;
    }

    void toString() {
      std::cout << "NODE CONTENTS:" << std::endl;
      std::cout << "Command: " << commandName << std::endl;
      std::cout << "Start time: " << startTime << std::endl;
      std::cout << "CPU time: " << cpuTime << std::endl;
      std::cout << "IO count: " << ioCount << std::endl;
    }
  };
}
