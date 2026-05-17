#include<stdio.h>
#include "scheduler.h"

void fcfs(int process[][8], int n) {
    int currentTime = 0;
    
    int gantt[MAX];
    int time[MAX+1];

    for(int i=0; i<n; i++) {

        //Idle Condition Handling
        if(currentTime < process[i][AT]) {
            currentTime = process[i][AT];
        }

        gantt[i] = process[i][PID];
        time[i] = currentTime;

        currentTime += process[i][BT];

        time[i+1] = currentTime;

        process[i][CT] = currentTime;

        process[i][TAT] = process[i][CT] - process[i][AT];
        process[i][WT] = process[i][TAT] - process[i][BT];

    }

    printf("\n========== FCFS SCHEDULING ==========\n");
    printGanttChart(gantt, time, n);
    printTable(process, n);
    printAverages(process, n);
}