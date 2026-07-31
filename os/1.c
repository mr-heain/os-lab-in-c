#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int i, len, s=0, w=1, c=0, v=0;
    char s1[50], ch;
    clrscr();
    printf("\n\t\tINPUT:");
    printf("\n\t\t------");
    printf("\n\t\tEnter the Text: ");
    gets(s1);
    len = strlen(s1);
    
    for(i=0; i<=len-1; i++)
    {
        ch = s1[i];
        switch(ch)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                v++;
                break;
            case ' ':
                s++;
                break;
            default:
                c++;
        }
        if(s1[i] == ' ' && s1[i-1] != ' ')
        {
            w++;
        }
    }
    printf("\n\t\tOUTPUT:");
    printf("\n\t\t-------");
    printf("\n\t\tThe number of vowels is: %d", v);
    printf("\n\t\tThe number of consonants is: %d", c);
    printf("\n\t\tThe number of words is: %d", w);
    printf("\n\t\tThe number of white spaces is: %d", s);
    getch();
}
