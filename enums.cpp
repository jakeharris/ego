namespace ego {
  enum ProcessState {
    RUNNING, START_IO, COMPLETE_IO, NEW_PROCESS
  };
  enum SchedulerType {
    EXPONENTIAL, STFCP
  };
}
