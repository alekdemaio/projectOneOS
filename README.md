# Project One | Operating Systems

# The Problem
This project attempts to create multiple simulations of processing algortihms within certain scenarios. Each scenario changes the behavior of the processors in that scenario. The processing algorithms that this project deals with directly are the SRT and FIFO processing algorithms.

Header file     | https://github.com/alekdemaio/projectOneOS/blob/main/proj1.h

Processor Class | https://github.com/alekdemaio/projectOneOS/blob/main/proj1Processor.cpp

Process Class   | https://github.com/alekdemaio/projectOneOS/blob/main/proj1processClass.cpp

Main program    | https://github.com/alekdemaio/projectOneOS/blob/main/proj1main.cpp

# Methodologies Used
FIFO- First in First Out. Arrival time is what is important here. Processes are queued by their arrival times, shortest first. Non-preemptive.

SJF- Shortest Job First. Service Time is what is important here. Processes are queued by their service times, shortest first. Non-preemptive.

SRT- Shortest Remaining Time. Similar to SJF, but this version is preemptive.

RR- Round Robin. Quantums are the name of the game for this algorithm. Quantums dicatate the number of cycles each process gets on the processor before being preempted, if a job is finished before the quantum is up, a new process switches on to the processor.

ML- Multi-level Priority has external priority values. Within each priority level scheduling functions as preemptive RR or nonpreemptive FIFO. If a process with a higher priority enters the system, the lower priority process can be preempted off for the higher priority process.

# My Simulation
My simulation first creates 50 Process objects and puts them into an array.

An array of size for is created for the Processor objects as well.

The program then prompts the user for a seed value, to be used in mersenne twister randomization. Mersenne Twister is then seeded.

Our process array is then filled with random values to be used in the simulation.

Next we ask our user which scenario and alogrithm they would like to use, this navigation is done through a menu.

Once arrived at the proper alogrithm and scenario, a while loop iterates through the queue of processes "executing" them.

For every iteration of the while loop we need processors filled so that is addressed at the beginnnning of the loop.

After we have process's on processors, we knock out cycles in groups starting with 10000000, lowering this value until all process's on the processors can subtract the indicated amount (this is meant to save time).

After this we test to see if any of the processors are finished with their execution of a process, if so the process is pushed onto a new queue and a flag is raised so a new process can be added durinng the next loop iteration.

After this while loop and after all processes have been "executed", a for loop returns the contents of the result queue to the console.

# Statistics
FIFO - Scenario One

This is the scenario with the most concrete results. Even so, I think there were issues with random number generation or populating my queues as many serive time values are the same, which does not really make any sense.

( seed value of 97 )

ID:            1
Wait:          0
Service Time:  20000000
ID:            2
Wait:          0
Service Time:  20000000
ID:            3
Wait:          0
Service Time:  20000000
ID:            4
Wait:          0
Service Time:  19100000
ID:            5
Wait:          0
Service Time:  19100000
ID:            6
Wait:          0
Service Time:  19100000
ID:            7
Wait:          0
Service Time:  18910000
ID:            8
Wait:          0
Service Time:  18910000
ID:            9
Wait:          0
Service Time:  18910000
ID:            10
Wait:          0
Service Time:  18830000
ID:            11
Wait:          0
Service Time:  18830000
ID:            12
Wait:          0
Service Time:  18830000
ID:            13
Wait:          0
Service Time:  18823100
ID:            14
Wait:          0
Service Time:  18823100
ID:            15
Wait:          0
Service Time:  18823100
ID:            16
Wait:          0
Service Time:  18822510
ID:            17
Wait:          0
Service Time:  18822510
ID:            18
Wait:          0
Service Time:  18822510
ID:            19
Wait:          0
Service Time:  18822481
ID:            20
Wait:          0
Service Time:  18822481
ID:            21
Wait:          0
Service Time:  18822481
ID:            22
Wait:          0
Service Time:  18822478
ID:            23
Wait:          0
Service Time:  18822478
ID:            24
Wait:          0
Service Time:  18822478
ID:            0
Wait:          0
Service Time:  18822478
ID:            25
Wait:          0
Service Time:  18822479
ID:            26
Wait:          0
Service Time:  18822479
ID:            27
Wait:          0
Service Time:  18822479
ID:            29
Wait:          0
Service Time:  20000000
ID:            30
Wait:          0
Service Time:  20000000
ID:            31
Wait:          0
Service Time:  20000000
ID:            32
Wait:          0
Service Time:  10510000
ID:            33
Wait:          0
Service Time:  10510000
ID:            34
Wait:          0
Service Time:  10510000
ID:            35
Wait:          0
Service Time:  10500100
ID:            36
Wait:          0
Service Time:  10500100
ID:            37
Wait:          0
Service Time:  10500100
ID:            38
Wait:          0
Service Time:  10490410
ID:            39
Wait:          0
Service Time:  10490410
ID:            40
Wait:          0
Service Time:  10490410
ID:            41
Wait:          0
Service Time:  10490361
ID:            42
Wait:          0
Service Time:  10490361
ID:            43
Wait:          0
Service Time:  10490361
ID:            44
Wait:          0
Service Time:  10490356
ID:            45
Wait:          0
Service Time:  10490356
ID:            46
Wait:          0
Service Time:  10490356
ID:            28
Wait:          0
Service Time:  10490356
ID:            47
Wait:          0
Service Time:  10490357
ID:            48
Wait:          0
Service Time:  10490357
ID:            49
Wait:          0
Service Time:  10490357

# Run My Program
command one --> g++ proj1main.cpp proj1processClass.cpp proj1Processor.cpp
command two --> ./a.out
