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

        printf("Toss\n\n\n");
        bool chance = toss();
        if(chance)
            printf("AI1 won the toss\n\n");
        else
            printf("AI2 won the toss\n\n");

        printf("total sticks on the table are %d\n\n",n);
        printf("\ngame start\n\n\n");

        if(!chance)
        {
            int x = minimax(n, chance);
            printf("\nAI2 picked up %d sticks\n",pick);
            n = n - pick;
            printf("remaining sticks are %d\n\n",n);
            if(n == 0)
            {
                printf("\n\nAI2 won\n\n\n\n");
                break;
            }
        }

        while(n)
        {
            chance = !chance;
            int x = minimax(n, chance);
            printf("\nAI1 picked up %d sticks\n",pick);
            n = n - pick;
            printf("remaining sticks are %d\n\n",n);

            if(n == 0)
            {
                printf("\n\nAI1 won\n\n\n\n");
                break;
            }
            chance = !chance;
            x = minimax(n, chance);
            printf("\nAI2 picked up %d  sticks\n",pick);
            n = n - pick;
            printf("remaining sticks are %d\n\n",n);

            if(n == 0)
            {
                printf("\n\nAI2 won\n\n\n\n");
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
