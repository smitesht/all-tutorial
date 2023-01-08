# Thread in C++11

## Process

A process is an instance of the running program that is being executed or running.
Each process is an independent entity to which system resources such as CPU time, memory, etc. are allocated and each process is executed in a separate address space.

## Thread

A thread is an execution path through a program or process. All program have at least one thread, the main thread.
The thread shares the resources with the process like the memory, code and global variable. Thread has its own stack.

## Difference between Process and Thread

Process:

1. A process is an instance of a program that is being executed or processed
   A thread is an execution path throguh a program or process

2. Processes are independent of each other and hence do not share a memory or other resources.
   Threads are interdependent and share memory.

3. Context switching between two process takes time while context switching between the thread is fast because they are very lightweight

4. The data segment and code segment of each process are independent of the other.
   Threads share data segment and code segment with their peer threads
