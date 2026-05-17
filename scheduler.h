#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX 100

#define PID 0
#define AT 1
#define BT 2
#define RT 3
#define PRIORITY 4
#define CT 5
#define TAT 6
#define WT 7

void fcfs(int process[][8], int n);
void sjfnonpre(int process[][8], int n);
void sjfpre(int process[][8], int n);
void rr(int process[][8], int n, int quantum);
void priority(int process[][8], int n);

void printTable(int process[][8], int n);
void printGanttChart(int gantt[], int time[], int size);
void printAverages(int process[][8], int n);
#endif