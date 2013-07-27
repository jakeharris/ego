#include "node.h"

#include <string>
#include <iostream>

using namespace ego;

Node::Node(std::string cn, long int st, long int ct, long int ic) {
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

void Node::tick() {
  runTime++;
}

void Node::setFinishTime(long int ft) {
  finishTime = ft;
}

void Node::block() {
  isBlocked = true;
}


void Node::unblock() {
  isBlocked = false;
}

std::string Node::getName() {
  return commandName;
}

void Node::setPriority(int p) {
  priority = p;
}

int Node::getPriority() {
  return priority;
} 

bool Node::isComplete() {
  return runTime >= cpuTime;
}

bool Node::needsIO() {
  return false;
}

bool Node::isReady(long int currentTime) {
  return startTime >= currentTime;
}

void Node::toString() {
  std::cout << "NODE CONTENTS:" << std::endl;
  std::cout << "Command: " << commandName << std::endl;
  std::cout << "Start time: " << startTime << std::endl;
  std::cout << "CPU time: " << cpuTime << std::endl;
  std::cout << "IO count: " << ioCount << std::endl;
}

int Node::getExpectedRunTime() {
  // FIXME
  return 0;
}

int Node::getFinishTime() {
  return finishTime;
}

int Node::getProcessRunTime() {
  // FIXME
  return runTime;
}
