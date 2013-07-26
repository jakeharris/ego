ego
===

A CPU scheduling simulator for Intro to OS. It is the ego, keeping balance between two extremes -- betwee superego and id.

Authors:
* Jake Harris (jake at auburn: jch0039, javakat: javakatdesign@gmail.com)
* Clay Miller (clay at auburn: cdm0025, smockle: clay@smockle.com)
* Patrick Fleming (patrick at auburn: jpf0005, splice09)
* Zachary White (zach at auburn: zdw0001, auzatch)


Table of Contents
-----------------
1. [To-do List] [1]
2. [Design] [2]
  1. [Simulacrum] [3]
  2. [Queue] [4]
  3. [Scheduler] [5]
  4. [Launcher] [6]
  5. [Scrivener] [7]

To-do List
----------
* Submit initial designs
* Develop main (the full simulator) skeleton -- should only create processes and call the scheduler at this stage
* Develop the trace reader
* Develop the queue data structure

CHECKPOINT -- you've earned a cookie! But this is only MAYBE a quarter of the work.

* Develop scheduler module
* Develop scheduling algorithm sub-modules
* Develop the clock and data collection sub-modules of main

Design
------

### Simulacrum

The simulacrum is an image of four parts:
  1. Queue
    * The queue is the resident data structure of our simulation. It stores the jobs we run and their relevant information (i.e. CommandName, StartTime, CPUTime, and IOCount) in a particular order.
  2. Scheduler
    * The scheduler organizes the queue so that the it abides by the given scheduling algorithm. It should reorganize the queue every time an event occurs in the simulator (a new job launches, is blocked, becomes unblocked, or completes).
  3. Launcher
    * The launcher is the bit of the simulacrum that launches processes and listens for updates in their states, and then handles the state updates by calling the scheduler and asking it to give the process a command (e.g. for beginning I/O, blocking the process).
  4. Scrivener
    * The scrivener keeps track of the clock, process logs, and "score." It is the piece of the simulacrum that will determine which scheduling algorithm performed the best, by taking its observations and calculating via the criteria provided in the project document.


### Queue

The queue, as mentioned, is our data structure. It should be a linked list, as jobs will be added to the queue over the course of the runtime of the simulacrum. Also, it should be a linked list because he mentioned it being a linked list in class. 

Each node in the queue is a job/process, and should contain:
  * A pointer to the node ahead of this one. A head of a list should have a NULL pointer here.
  * CommandName: the name of the command to run (presumably with execvp). Since we're going to use an exec-family function, this variable should be a 'char\*' to make this easier on us.
  * StartTime: the start time, relative to the scrivener's clock, in ms, of this process. This is read from the file, and is NOT updated when we launch this process in the simulacrum. It just tells us when to INITIALLY launch the process.
  * CPUTime: the amount of time, in s (**Note: not ms, like StartTime is**), that this process consumes in the processor.
  * IOCount: the total number of bytes of disk I/O. Disk I/O always occurs in full blocks, and blocks are 8KB (8192 bytes). Therefore, if I understand this right, all IOCount values should be multiples of 8KB. Maybe we can use that to our advantage to make it more human readable...Either way, **disk** I/O is the only kind of I/O we care about in this project.

The queue should have a pointer to the head of the list, and a way to traverse the list. Sorting details should be handled by the scheduler, but should use methods that the queue provides.

### Scheduler

The scheduler sounds to be most of the work of the project. It is comprised of two parts:
  1. A sorting (scheduling) algorithm. The scheduler should have functions like 'block(proc p)' and 'unblock(proc p)' that ask the algorithm what exactly to do to the queue based on a change to a particular process (a signal the launcher should be sending us).
  2. The IO monitor. Since we are explicitly calculating when we should perform IO, we can simply ask the queue and scrivener when a certain process should change IO states, make those changes, and update the queue order accordingly. The IO monitor should be identical in both versions of the program. The sorting algorithm should not.

### Launcher
  
Honestly I'm not certain if this needs to do anything but launch, now that I realize how comprehensive the scheduler is.

### Scrivener

Keeps track of the clock. Keeps track of each process's completion time, the whole simulacrum's completion time, and the utilization of the CPU for each scheduling algorithm.


[1]: #to-do-list "To-do List"
[2]: #design "Design"
[3]: #simulacrum "Simulacrum"
[4]: #queue "Queue"
[5]: #scheduler "Scheduler"
[6]: #launcher "Launcher"
[7]: #scrivener "Scrivener"
