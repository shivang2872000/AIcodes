#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int pick = 0;

int prune(bool chance, int score, int sticks, int n)
{
    if((chance && score == 1) || (!chance && score == -1))
    {
        pick = sticks;
        return score;
    }
    else if(n == sticks)
    {
        pick = 1;
        return score;
    }
    else
        return 0;
}

int minimax(int n, bool chance)
{
    if(n == 0)
    {
        if(chance)
            return 1;
        return -1;
    }

    int score1 = minimax(n-1, !chance);
    int x = prune(chance, score1, 1, n);
    if(x != 0)
        return x;
    int score2 = minimax(n-2, !chance);
    x = prune(chance, score2, 2, n);
    if(x != 0)
        return x;
    int score3 = minimax(n-3, !chance);
    if(chance)
    {
        if(score3 == 1)
        {
            pick = 3;
            return 1;
        }
        else{
            pick = 1;
            return score3;
        }
    }
    else{
        if(score3 == 1)
        {
            pick = 1;
            return score3;
        }
        else{
            pick = 3;
            return score3;
        }
    }
}

bool toss()
{
    double x =((double) rand()/ (RAND_MAX));
    if(x >= 0.5)
        return true;
    return false;
}

int main()
{
    int n, person;
    bool t = true;
    char choice;
    while(t)
    {
        printf("enter no. of sticks = ");
        scanf("%d",&n);

        printf("toss is being conducted");
        bool chance = toss();
        if(chance)
            printf("AI won the toss\n\n");
        else
            printf("You won the toss\n\n");

        printf("total number of sticks on the table are %d\n\n",n);
        if(!chance)
        {
            printf("pick up sticks in range of 1 to 3: ");
            scanf("%d",&person);
            while(person < 1 || person > 3)
            {
                printf("please pick up sticks striclty between 1 to 3: ");
                scanf("%d",&person);
            }
            printf("\n yiu have picked %d sticks\n",person);
            n = n - person;
            printf("\nremaining sticks are %d",n);
            chance = !chance;
        }

        while(n)
        {
            int x = minimax(n, chance);
            printf("\nAI picked %d number of sticks\n\n",pick);
            n = n - pick;
            printf("\n\nremaining number of sticks on the table is %d",n);

            if(n == 0)
            {
                printf("\n\nAI lost,human won\n\n");
                break;
            }

            printf("pick up sticks in range of 1 to 3: \n");
            scanf("%d",&person);
            while(person < 1 || person > 3)
            {
                printf("sticks out of range\n ");
                scanf("%d",&person);
            }
            while(person > n)
            {
                printf("you tried to pick more than remaining sticks\n");
                scanf("%d",&person);
            }
            printf("\n\nremaining sticks on the table are %d\n",n);

            n = n - person;
            if(n == 0)
            {
                printf("\n\nHuman lost, AI won\n\n\n\n");
                break;
            }
        }

        printf("Do you want to play again? Type 'y' for yes and 'n' for no: ");
	getchar();
        scanf("%c",&choice);
        if(choice == 'n')
            t = false;
    }

    return 0;
}
