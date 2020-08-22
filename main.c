/*
Project: TIC TAC TOE
Language: C
@author: Nawaz2000
@version: 2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char a[9]= {'1','2','3','4','5','6','7','8','9'};
int flag[9] = {0,0,0,0,0,0,0,0,0};
int c=0,e=0,i,x=0,playAgain1=0;

void p1()
{
    //behind player 1
    int m;
    printf("Player 1 enter your move:");
    scanf("%d",&m);
    a[m-1]='O';
    flag[m-1] = 1;
}

void p2()
{
    //behind player 2
    int n;
    printf("Player 2 enter your move:");
    scanf("%d",&n);
    a[n-1]='X';
    flag[n-1] = 1;
}

void pcheck()
{
    //checker method for if the game is a win, draw, or loss
    for (int i = 0; i<7; i+=3)
    {
        if (a[i] == a[i+1] && a[i] == a[i+2])
        {
            printf("Player%d wins.",x=(i%2==0)?1:2);
            c++;
        }
    }

    for (int i = 0; i<3; i++)
    {
        if (a[i] == a[i+3] && a[i] == a[i+6])
        {
            printf("Player%d wins.",x=(i%2==0)?1:2);
            c++;
        }
    }

    if (a[0]==a[4] && a[0]==a[8])
    {
        printf("Player%d wins.",x=(i%2==0)?1:2);
        c++;
    }
    else if (a[2]==a[4] && a[2]==a[6])
    {
        printf("Player%d wins.",x=(i%2==0)?1:2);
        c++;
    }
    if (a[0]!='1'&&a[1]!='2'&&a[2]!='3'&&a[3]!='4'&&a[4]!='5'&&a[5]!='6'&&a[6]!='7'&&a[7]!='8'&&a[8]!='9')
        e++;
}

void draw()
{
    //draws the tick tack toe board every time the screen clears out
    int i;
    printf("Player1--<O>\n");
    printf("Player2--<X>\n\n");
    printf("     TIC TAC TOE\n");
    for (i=0; i<9; i++)
    {
        if (i == 3 || i == 6)
        {
            printf("\n");
            for (int j=0; j<3; j++)
                printf("  ___  ");
            printf("\n");
        }
        if (flag[i] == 0)
            printf("|     |");
        else if (flag[i] == 1)
            printf("|  %c  |",a[i]);
    }
     printf("\n");
            for (int j=0; j<3; j++)
                printf("  ___  ");
            printf("\n");

}

int main()
{
    for (i=0;; i++)
    {
        draw();
        if (i%2==0)
        {
            p1();
            draw();
            pcheck();
            if (c==1)
                break;
        }
        else if (i%2!=0)
        {
            p2();
            draw();
            pcheck();
            if (c==1)
                break;
        }
        if (e==1)
        {
            printf("This is a draw.");
            break;
        }
        if (c==1)
            break;
        system("cls");
    }
    return 0;
}
