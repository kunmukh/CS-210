//Kunal Mukherjee
//Assignment 3 Rock_Paper_Scissor_Lizard_Spock
//Sept 6, 2016
//Dr. Blandford

#include<stdio.h>
#include<math.h>

instruction();
menu();
double player1();
double player2();

int main()
{
    int r; //The resultant 
    double p1, p2;

    instruction();
    menu();

    p1 = player1();
    p2 = player2();

    r =  abs(p2- p1);
     

    if (r == 0)
    {
        if (p2 == 5, p1 == 5)
        {
            printf("\nSpock and Spock shook hands. This is a tie. \n");
        }

        else if (p2 == 4, p1 == 4)
        {
            printf("\nLizard and lizard became friends. This is a tie.\n");
        }

        else if (p2 == 3, p1 == 3)
        {
            printf("\nRock and Rock build a fort. This is a tie.\n ");
        }
        
        else if (p2 == 2, p1 == 2)
        {
            printf("\nPaper and Paper flew away. This is a tie.\n");
        }

        else if (p2 == 1, p1 == 1)
        {
            printf("\nScissor and Scissor got jamed. This is a tie. \n");
        }
    }

    else if (r == 1)
    {
        if (p2 == 5, p1 == 4) 
        {
            printf(" \nPlayer 1 wins. Lizard poisons Spock. \n");
        }

        else if (p1 == 5, p2 == 4) 
        {
            printf(" \nPlayer 1 wins. \n");
        }
        
        else if (p2 == 4, p1 == 3)
        {
            printf(" \nPlayer 1 wins. Rock crushes Lizard. \n");
        }

        else if (p1 == 4, p2 == 3)
        {
            printf(" \nPlayer 1 wins. \n");
        }

        else if (p2 == 3, p1 == 2)
        {
            printf("\nPlayer 1 wins. Paper captures Rock.\n");
        }

        else if (p1 == 3, p2 == 2)
        {
            printf("\nPlayer 1 wins. \n");
        }
        
        else if (p2 == 2, p1 == 1)
        {
            printf("\nPlayer 1 wins. Scissor cuts Paper.");
        }

        else if (p1 == 2, p2 == 1)
        {
            printf("\nPlayer 1 wins. ");
        }
    }

    else if (r == 2)
    {
        if (p2 == 5, p1 == 3)
        {
            printf("\nPlayer 1 wins. Spock smashes rock.\n ");
        }

        else if (p1 == 5, p2 == 3)
        {
            printf("\nPlayer 1 wins. \n ");
        }

        else if (p2 == 4, p1 == 2)
        {
            printf("\nPlayer 1 wins. Lizard eats paper.\n");
        }

        else if (p1 == 4, p2 == 2)
        {
            printf("\nPlayer 1 wins. \n");
        }

       else if (p2 == 3, p1 == 1)
        {
            printf("\nPlayer 1 wins.Rock breaks scissors.\n");
        }

        else if (p1 == 3, p2 == 1)
        {
            printf("\nPlayer 1 wins.\n");
        }
    }

    else if (r == 3)
    {
        if (p2 == 5, p1 == 2)
        {
            printf("\n Player 2 wins. Paper decapicates Spock.\n");
        }

       else if (p1 == 5, p2 == 2)
        {
            printf("\n Player 2 wins. \n");
        }

        else if (p2 == 4, p1 == 1)
        {
            printf("\n Player 2 wins. Scissor decapicates Lizard.\n");
        }

        else if (p1 == 4, p2 == 1)
        {
            printf("\n Player 2 wins.\n");
        }
    }

    else if (r == 4)
    {
        if (p2 == 1, p1 == 5)
        {
            printf("\n Spock smashes scissors.\n");
        }

        else if (p1 == 1, p2 == 5)
        {
            printf("\n Spock smashes scissors.\n");
        }
    }

    return 0;
}

instruction()
{
    printf("Welcome to this GRAND GAME OF ROCK, PAPER, SCISSORS, LIZARD, SPOCK\n");
}

menu()
{
    printf("\nChoose 1 for scissors, \nChoose 2 for paper, \nChoose 3 for rock, \nChoose 4 for lizard, \nand Choose 5 for Spock\n ");
}


double player1()
{
    double p1;
    printf("\nPlayer 1:\t");
    scanf_s("%lf", &p1);
    return p1;
}

double player2()
{
    double p2;
    printf("\nPlayer 2:\t");
    scanf_s("%lf", &p2);   
    return p2;
}




