#include<stdio.h>
#include<conio.h>
void main(){
int bt[20],wt[20],tat[20],i,n;
float wtavg,tatavg;
clrscr();
printf("\nEnter the number of process:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter burst time of process %d --",i);
scanf("%d",&bt[i]);}
wt[0] = wtavg =0;
tat[0] = tatavg = bt[0];
for(i =1;i<n;i++){
wt[i] = wt[i-1]+bt[i-1];
tat[i] = tat[i-1]+bt[i];
wtavg = wtavg +wt[i];
tatavg = tatavg + tat[i];}
printf("\tProcess\tBrust Time\tWating time\tTurn Around Time \n");
for(i=0;i<n;i++)
printf("\n\tp%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
printf("\nAverage waiting time --%f",wtavg /n);
printf("\nAverage turn around time --%f",tatavg /n);
getch();
}