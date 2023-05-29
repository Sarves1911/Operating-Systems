// SJF Non Preemptive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process
{
    int pid;   // process id
    int burst; // burst time
    int rem;   // remaining time
};

// Function to sort the processes based on their burst time
void sort(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].burst > p[j + 1].burst)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()
{
    printf("AUTHOR : SARVESH KOLI\n");
    int n, i, j;
    struct process p[MAX_PROCESS];
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the burst time for each process
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].pid = i + 1;
        p[i].rem = p[i].burst;
    }

    // Sort the processes based on their burst time
    sort(p, n);

    // Implementing the SJF algorithm
    printf("\nProcess\tBurst time\tRemaining time\n");
    i = 0;
    while (i < n)
    {
        printf("P%d\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].rem);
        p[i].rem--;
        if (p[i].rem == 0)
            i++;
        sort(p, n); // sort the processes again after each iteration
    }
    return 0;
}
