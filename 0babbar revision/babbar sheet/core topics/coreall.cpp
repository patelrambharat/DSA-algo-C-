Most Important topics for Interviews | CS Core topics

I will cover the most important topics asked in interviews cs core. Most important topics related to OS/DBMS/OOPS/CN (Updated).

CONTENT OF THIS POST :
Most important topics related to OS/DBMS/OOPS/CN.

Important Topic for OS

Process (Attributes, state, life cycle, PCB) vs Thread.

Process: Processes are basically the programs that are dispatched from the ready state and are scheduled in the CPU for execution. PCB(Process Control Block) holds the concept of process. A process can create other processes which are known as Child Processes. The process takes more time to terminate and it is isolated means it does not share the memory with any other process. The process can have the following states new, ready, running, waiting, terminated, and suspended.
Thread: Thread is the segment of a process which means a process can have multiple threads and these multiple threads are contained within a process. A thread has three states: Running, Ready, and Blocked. The thread takes less time to terminate as compared to the process but unlike the process, threads do not isolate.
Process	Thread
Process means any program is in execution.	Thread means a segment of a process.
It takes more time for creation.	It takes less time for creation.
It also takes more time for context switching.	It takes less time for context switching.
The process is less efficient in terms of communication.	Thread is more efficient in terms of communication.
Multiprogramming holds the concepts of multi-process.	We don’t need multi programs in action for multiple threads because a single process consists of multiple threads.
The process is isolated.	Thread shares memory.
The process is called the heavyweight process.	A Thread is lightweight as each thread in a process shares code, data, and resources.
Process switching uses an interface in an operating system.	Thread switching does not require calling an operating system and causes an interrupt to the kernel.
If one process is blocked then it will not affect the execution of other processes.	If a user-level thread is blocked, then all other user-level threads are blocked.
The process has its own Process Control Block, Stack, and Address Space.	Thread has Parents’ PCB, its own Thread Control Block, and Stack and common Address space.
Changes to the parent process do not affect child processes.	Since all threads of the same process share address space and other resources so any changes to the main thread may affect the behavior of the other threads of the process.
A system call is involved in it.	No system call is involved, it is created using APIs.
The process does not share data with each other.	Threads share data with each other.
Scheduling Algorithms

Preemptive Scheduling: Preemptive scheduling is used when a process switches from running state to ready state or from the waiting state to the ready state.
Non-Preemptive Scheduling: Non-Preemptive scheduling is used when a process terminates , or when a process switches from running state to waiting state.
image
Multiprogramming vs Multiprocessing vs Multitasking vs Multithreading.

Memory Allocation

Fixed Partioning
Dynamic Partioning
Paging
Segmentation
Internal and External Fragmentation.

Memory Allocation Technique.

Page replacement Algos

Deadlock

Critical section problem

Benefits of a multiprocessor system

RAID structure in OS and different levels of RAID Configration.

Bootstrap program in OS

Demand paging

RTOS

IPC

Main Memory Vs Secondary Memory

Mutex vs Semaphore

Important Topic for DBMS

Advantage of DBMS
All type of Keys
Normalization
SQL queries
Relational Algebra
Joins
Database and it's Utility
Languages in DBMS
Null vs Blank spaces, or Zero
Data Warehousing
Levels of data abstraction in DBMS
Entity - Relationship (E-R) Model
Trigger, cursor, view
Dirty read problem
Conflict serializable vs View serializable.
ACID properties.
Indexing | Indexing methods
Important Topic for COMPUTER NETWORK

Network Topology
Switch hub router bridge
Transmission modes
ipv4 vs ipv6
subnetting in IP
Ethernet
Media Access Control and Address Resolution Protocols
witches, wireless access points, routers, modems
Firewalls, TCP ports, UDP ports
OSI layer
TCP/IP model
ARQ (Automatic Repeat Request Technique)
Transmission Modes
TCP vs UDP
DNS DHCP FTP HTTP vs HTTPS SMTP SNMP
Flow vs Error control
Important Topic for OOPS

Class and Objects.
Feature/characteristics of OOPs.
Advantages of OOPs.
OOPs so Popular ?
Compile time and Runtime polymorphism.
Variable scopes.
static (variables, Functions, Objects).
Inheritence (Type and Mode)
Virtual (Functions and Class)
Abstract class and Interface.
Friend function and Friend class.
Call by value, refrence.
This pointer
Abstraction
Exception Handling
Constructor and Destructor.
Copy constructor
copy assignemnt operator
Refrences variable
Const (variable, Function, Arguement)
Overloading (Function, Constructor, Operator)
Function overriding and Inline function.