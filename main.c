#include<stdio.h>
#include<stdlib.h>
#include "scheduler.h"
int main() {
    int process[MAX][8];
    /*
    0 - PID
    1 - AT
    2 - BT
    3 - RT
    4 - Priority
    5 - CT
    6 - TAT
    7 - WT
    */

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    //Input Arrival Time & Burst Time
    for(int i=0; i<n; i++) {
        printf("\nProcess %d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &process[i][AT]);
        printf("Burst Time: ");
        scanf("%d", &process[i][BT]);

        process[i][PID] = i+1;
        process[i][RT] = process[i][BT];
        process[i][CT] = 0;
        process[i][TAT] = 0;
        process[i][WT] = 0;
        process[i][PRIORITY] = 0;
    }

    int choice;
    int quantum;

    while(1) {
        printf("\n---------- CPU SCHEDULING MENU ----------\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. Shortest job First : Non - Preemptive (SJF)\n");
        printf("3. Shortest Job First : Preemptive (SJF)\n");
        printf("4. Round Robin (RR)\n");
        printf("5. Priority Scheduling\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Create a fresh copy for every algorithm
        int temp[MAX][8];

        for(int i=0; i<n; i++) {
            for(int j=0; j<8; j++) {
                temp[i][j] = process[i][j];
            }
        }

        switch(choice) {
            case 1 :
            fcfs(temp, n);
            break;

            case 2 :
            sjfnonpre(temp, n);
            break;

            case 3 :
            sjfpre(temp, n);
            break;

            case 4 :
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            rr(temp, n, quantum);
            break;

            case 5 :
            printf("Enter Priority for:\n");
            for(int i=0; i<n; i++) {
                printf("Process %d: ", i+1);
                scanf("%d", &temp[i][PRIORITY]);
            }

            priority(temp, n);
            break;

            case 6 :
            exit(0);

            default :
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}