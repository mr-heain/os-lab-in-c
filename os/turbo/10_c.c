#include<stdio.h>
#include<conio.h>
#define max 25

void main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest;
    static int bf[max], ff[max];
    clrscr();
    printf("\nMemory Management Scheme: Worst Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for(i=1; i<=nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files:-\n");
    for(i=1; i<=nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }
    for(i=1; i<=nf; i++)
    {
        highest = 0;
        for(j=1; j<=nb; j++)
        {
            if(bf[j] != 1)
            {
                temp = b[j] - f[i];
                if(temp >= 0)
                {
                    if(highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        if(ff[i] == 0)
        {
            printf("\nFile %d: No suitable block found!", i);
            frag[i] = -1;
            continue;
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
    }
    printf("\nFile_no:\tFile_Size:\tBlock_no:\tBlock_size:\tFragment");
    for(i=1; i<=nf; i++)
    {
        if(ff[i] == 0)
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
        else
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    getch();
}
