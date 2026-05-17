#include<stdio.h>
#include "scheduler.h"

void rr(int process[][8], int n, int quantum) {
    int currentTime = 0;
    int completed = 0;

    int gantt[1000];
    int time[1000];
    int ganttSize = 0;

    while(completed < n) {
        int executed = 0;

        for(int i=0; i<n; i++) {
            if(process[i][AT] <= currentTime && process[i][RT] > 0) {
                executed = 1;

                //Store Gantt Chart Information
                gantt[ganttSize] = process[i][PID];
                time[ganttSize] = currentTime;
                ganttSize++;

                //Check for Time Quantum
                if(process[i][RT] > quantum) {
                    currentTime += quantum;
                    process[i][RT] -= quantum;
                } else {
                    currentTime += process[i][RT];
                    process[i][RT] = 0;

                    completed++;

                    //Completion Time
                    process[i][CT] = currentTime;
                    //Turn Around Time
                    process[i][TAT] = process[i][CT] - process[i][AT];
                    //Waiting Time
                    process[i][WT] = process[i][TAT] - process[i][BT];
                }
            }
        }

        //CPU Idle Condition
        if(executed == 0) {
            currentTime++;
        }
    }

    time[ganttSize] = currentTime;

    printf("\n========== ROUND ROBIN ==========\n");
    printGanttChart(gantt, time, ganttSize);
    printTable(process, n);
    printAverages(process, n);
}