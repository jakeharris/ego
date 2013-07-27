#ifndef NODE_H
#define NODE_H

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

    Node(std::string cn, long int st, long int ct, long int ic);
    void tick();
    void setFinishTime(long int ft);
    void block();
    void unblock();
    std::string getName();
    void setPriority(int p);
    int getPriority();
    bool isComplete();
    bool needsIO();
    bool isReady(long int currentTime);
    void toString();
    int getExpectedRunTime();
    int getFinishTime();
    int getProcessRunTime();
  };
}

#endif