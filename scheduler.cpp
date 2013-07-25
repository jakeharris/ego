namespace ego {
  class Scheduler {

    SchedulingAlgorithm alg;

    public: 
    Scheduler(SchedulerType type) {
      switch(type) {
        case SchedulerType.EXPONENTIAL:
          alg = new ExponentialAlgorithm();
          break;
        case SchedulerType.STCFP:
          alg = new STCFPAlgorithm();
          break;
        default:
          cout << "ERROR: Scheduler algorithm failed to initialize.\nInput value: " << type << "\nLegal values: " << SchedulerType.EXPONENTIAL << ", " << SchedulerType.STCFP << "\n";
          break;
      }
    }

  };
}
