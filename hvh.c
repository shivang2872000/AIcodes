#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int pick = 0;

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

        printf("Now its time for toss\n\n");
        bool chance = toss();
        if(chance)
            printf("Player1 won the toss\n\n");
        else
            printf("Player2 won the toss\n\n");

        printf("total sticks are on the table\nre %d\n",n);
        printf("\ngame starts\n\n\n");

        if(!chance)
        {
            printf("Player2 pick any number of sticks between 1 and 3: ");
            scanf("%d",&person);
            while(person < 1 || person > 3)
            {
                printf("please pick up any number of sticks between 1 and 3 ");
                scanf("%d",&person);
            }
            printf("\nPlayer2 picked up %d sticks\n",person);
            n = n - person;
            printf("remaining sticks are %d\n\n",n);
        }

        while(n)
        {
            printf("\n\nPlayer1, pick up sticks between 1 and 3 "\n\n);
            scanf("%d",&person);
            while(person < 1 || person > 3)
            {
                printf("please pick up sticks striclty between 1 to 3: ");
                scanf("%d",&person);
            }
            printf("\nPlayer1 picked up %d sticks\n",person);

            while(person > n)
            {
                printf("you tried to pick more than remaining sticks\n");
                scanf("%d",&person);
            }
            n = n - person;
            printf("\n\nthere are %d sticks left\n",n);


            if(n == 0)
            {
                printf("\n\nPlayer2 won\n\n\n\n");
                break;
            }

            printf("Player2, pick up sticks between 1 to 3: ");
            scanf("%d",&person);
            while(person < 1 || person > 3)
            {
                printf("please pick up sticks striclty between 1 to 3: ");
                scanf("%d",&person);
            }
            printf("player 2 picked up %d sticks",person);

            while(person > n)
            {
                printf("you tried to pick more than remaining sticks\n");
                scanf("%d",&person);
            }
            n = n - person;
            printf("%d sticks on the table",n);


            if(n == 0)
            {
                printf("\n\nPlayer1 won");
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
