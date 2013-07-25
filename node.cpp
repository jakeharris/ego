namespace ego {
  class Node {
    String commandName;
    int startTime;
    int cpuTime;
    int ioCount;

    int runTime;

    node *next;

    Node(String commandName, long int startTime, long int cpuTime, long int ioCount) {
      
    }

    void tick() {
      runTime++;
    }
  };
}
