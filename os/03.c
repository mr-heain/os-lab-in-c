#include<stdio.h>
#include<conio.h>

void main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    clrscr();
    printf("\nEnter the number of processes--");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        p[i] = i;
        printf("\nEnter Burst time for process%d--", i);
        scanf("%d", &bt[i]);
    }
    for(i=0; i<n; i++)
    {
        for(k=i+1; k<n; k++)
        {
            if(bt[i] > bt[k])
            {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\n\tprocess\tBurst time\tWaiting time\t Turnaround time\n");
    for(i=0; i<n; i++)
        printf("\n\tp%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting time--%f", wtavg/n);
    printf("\nAverage Turnaround time--%f", tatavg/n);
    getch();
}
