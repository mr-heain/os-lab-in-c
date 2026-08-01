#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int i, j, n, need[10][10];
    int m, k;
    int count=0, c=0, progress;
    char finish[10];
    clrscr();

    printf("Enter the no. of processes and resources:");
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++)          /* fixed: was i<=n, wrote one byte past the array */
        finish[i] = 'n';

    printf("Enter the claim matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocation matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Resource vector:");
    for(i=0; i<m; i++)
        scanf("%d", &total[i]);

    for(i=0; i<m; i++)
        avail[i] = 0;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            avail[j] += alloc[i][j];

    for(i=0; i<m; i++)
        work[i] = avail[i];

    for(j=0; j<m; j++)
        work[j] = total[j] - work[j];

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

A:
    progress = 0;               /* new: tracks whether any process ran this pass */
    for(i=0; i<n; i++)
    {
        c = 0;
        for(j=0; j<m; j++)
            if((need[i][j] <= work[j]) && (finish[i] == 'n'))
                c++;

        if(c == m && finish[i] == 'n')
        {
            printf("All the resources can be allocated to process %d", i+1);
            printf("\n\nAvailable resources are:");
            for(k=0; k<m; k++)
            {
                work[k] += alloc[i][k];
                printf("%d ", work[k]);
            }
            printf("\n");
            finish[i] = 'y';
            printf("\nProcess %d executed?:%c\n", i+1, finish[i]);
            count++;
            progress = 1;        /* new: at least one process finished this pass */
        }
    }

    if(count != n)
    {
        if(progress == 1)
            goto A;               /* still making progress, do another pass */
        else
        {
            /* new: no process could run this pass -> state is genuinely unsafe */
            printf("\nSystem is NOT in safe mode");
            printf("\nThe given state is an UNSAFE state (deadlock possible)");
            getch();
            return;
        }
    }

    printf("\nSystem is in safe mode");
    printf("\nThe given state is safe state");
    getch();
}
