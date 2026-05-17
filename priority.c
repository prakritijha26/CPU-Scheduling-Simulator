#include<stdio.h>
#include "scheduler.h"

void priority(int process[][8], int n) {
    int currentTime = 0;
    int isCompleted[MAX] = {0};
    int gantt[1000];
    int time[1000];

    int ganttSize = 0;
    int completed = 0;

    while(completed < n) {
        int highest = -1;
        int minPriority = 9999;

        //Find process with highest priority
        for(int i=0; i<n; i++) {
            if(process[i][AT] <= currentTime && isCompleted[i] == 0 &&
            process[i][RT] > 0 && process[i][PRIORITY] < minPriority) {
                highest = i;
                minPriority = process[i][PRIORITY];
            }
        }

        //CPU Idle Condition
        if(highest == -1) {
            currentTime++;
            continue;
        }

        //Store Gantt Chart Information
        gantt[ganttSize] = process[highest][PID];
        time[ganttSize] = currentTime;
        ganttSize++;

        //Execute for 1 unit
        process[highest][RT]--;
        currentTime++;

        if(process[highest][RT] == 0) {
            isCompleted[highest] = 1;
            completed++;

            //Completion Time
            process[highest][CT] = currentTime;

            //Turn Around Time
            process[highest][TAT] = process[highest][CT] - process[highest][AT];

            //Waiting Time
            process[highest][WT] = process[highest][TAT] - process[highest][BT];
        }
    }

    time[ganttSize] = currentTime;

    printf("\n========== PRIORITY SCHEDULING ==========\n");
    printGanttChart(gantt, time, ganttSize);
    printTable(process, n);
    printAverages(process, n);
}