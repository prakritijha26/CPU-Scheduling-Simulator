# CPU Scheduling Simulator in C

A CPU Scheduling Simulator implemented in C for Operating Systems concepts.

## Algorithms Implemented
- FCFS (First Come First Serve)
- SJF Non-Preemptive
- SJF Preemptive (SRTF)
- Round Robin
- Priority Scheduling

##Taking Input
<img width="423" height="400" alt="input jpg" src="https://github.com/user-attachments/assets/452e7602-f7f3-4e95-b198-71e6d032246e" />

##FCFS Output
<img width="491" height="510" alt="fcfs jpg" src="https://github.com/user-attachments/assets/3143469a-beb7-4c47-8500-bff7ca19995c" />

##SJF Non Preemptive Output
<img width="537" height="520" alt="sjfnonpre jpg" src="https://github.com/user-attachments/assets/56e8e55a-186d-488f-9048-ebe6635bf5e0" />

##SJF Preemptive Output
<img width="1041" height="541" alt="sjfpre jpg" src="https://github.com/user-attachments/assets/fa17d9c3-ef6c-488b-93de-9b320ff9a180" />

##Round Robin Output
<img width="563" height="536" alt="rr jpg" src="https://github.com/user-attachments/assets/ba898f57-48e6-4c6a-be06-3456797a043e" />

##Priority Scheduling Output
<img width="1051" height="648" alt="piority jpg" src="https://github.com/user-attachments/assets/7249563d-0ed8-4f5b-b9fb-c35a9212751e" />

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
