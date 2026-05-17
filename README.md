# CPU Scheduling Simulator in C

A CPU Scheduling Simulator implemented in C for Operating Systems concepts.

## Algorithms Implemented
- FCFS (First Come First Serve)
- SJF Non-Preemptive
- SJF Preemptive (SRTF)
- Round Robin
- Priority Scheduling

## Features
- Gantt Chart Visualization
- Waiting Time Calculation
- Turnaround Time Calculation
- Average WT & TAT
- Modular File Structure

## Technologies Used
- C Programming
- GCC Compiler

## How to Compile

gcc main.c utils.c fcfs.c sjf.c rr.c priority.c -o scheduler

## How to Run

./scheduler

## Future Improvements
- Non-Preemptive Priority Scheduling
- Better Gantt Chart Visualization
- Queue-based Round Robin
- GUI Version
