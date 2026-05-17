#include<stdio.h>
#include "scheduler.h"

void printTable(int process[][8], int n) {
    printf("\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i][PID], process[i][AT], process[i][BT],
        process[i][CT], process[i][TAT], process[i][WT]);
    }
}

void printGanttChart(int gantt[], int time[], int size) {
    printf("\nGantt Chart:\n");
    for(int i=0; i<size; i++) {
        printf("| P%d ", gantt[i]);
    }

    printf("|\n");

    for(int i=0; i<=size; i++) {
        printf("%d\t", time[i]);
    }

    printf("\n");
}

void printAverages(int process[][8], int n) {
    float totalTAT = 0;
    float totalWT = 0;

    for(int i=0; i<n; i++) {
        totalTAT += process[i][TAT];
        totalWT += process[i][WT];
    }

    printf("\n");
    printf("Average Turnaround Time = %.2f\n", totalTAT/n);
    printf("Average Waiting Time = %.2f\n", totalWT/n);
}