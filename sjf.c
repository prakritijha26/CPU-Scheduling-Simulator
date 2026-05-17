#include<stdio.h>
#include "scheduler.h"

void sjfnonpre(int process[][8], int n) {
    int currentTime = 0;
    int gantt[MAX];
    int time[MAX + 1];
    int count = 0;
    int completed[MAX] = {0};

    while(count < n) {
        int minBurstTime = 9999;
        int index = -1;

        //Find process with minimum Burst Time
        for(int i=0; i<n; i++) {
            if(process[i][AT] <= currentTime && completed[i] == 0 && process[i][BT] < minBurstTime) {
                minBurstTime = process[i][BT];
                index = i;
            }
        }

        //CPU Idle Condition
        if(index == -1) {
            currentTime++;
            continue;
        }

        //Store Gantt Chart Information
        gantt[count] = process[index][PID];
        
        time[count] = currentTime;

        //Completion Time
        currentTime += process[index][BT];

        time[count + 1] = currentTime;

        process[index][CT] = currentTime;

        //Turnaround Time
        process[index][TAT] = process[index][CT] - process[index][AT];

        //Waiting Time
        process[index][WT] = process[index][TAT] - process[index][BT];

        //Mark process as completed
        completed[index] = 1;

        count++;
    }

    printf("\n========== SHORTEST JOB FIRST - NON PREEMPTIVE ==========\n");
    printGanttChart(gantt, time, n);
    printTable(process, n);
    printAverages(process, n);
}

void sjfpre(int process[][8], int n) {
    int currentTime = 0;
    int completed = 0;
    int isCompleted[MAX] = {0};

    int gantt[1000];
    int time[1000];

    int ganttSize = 0;

    while(completed < n) {
        int shortest = -1;
        int minRT = 9999;

        //Find Process with minimum Remaining Time
        for(int i=0; i<n; i++) {
            if(process[i][AT] <= currentTime && isCompleted[i] == 0 && process[i][RT] > 0 && 
                process[i][RT] < minRT) {
                    shortest = i;
                    minRT = process[i][RT];
            }
        }

        //CPU Idle Condition
        if(shortest == -1) {
            currentTime++;
            continue;
        }

        gantt[ganttSize] = process[shortest][PID];
        time[ganttSize] = currentTime;

        ganttSize++;

        //Execute for 1 unit
        process[shortest][RT]--;
        currentTime++;

        if(process[shortest][RT] == 0) {
            isCompleted[shortest] = 1;
            completed++;

            //Completion Time
            process[shortest][CT] = currentTime;

            //TurnAround Time
            process[shortest][TAT] = process[shortest][CT] - process[shortest][AT];

            //Waiting Time
            process[shortest][WT] = process[shortest][TAT] - process[shortest][BT];
        }
    }

    time[ganttSize] = currentTime;

    printf("\n========== SHORTEST JOB FIRST - PREEMPTIVE ==========\n");
    printGanttChart(gantt, time, ganttSize);
    printTable(process, n);
    printAverages(process, n);
}