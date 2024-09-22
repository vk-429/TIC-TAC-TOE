#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include <unistd.h>
#include <stdbool.h>
#include "TIC_TAC_TOE.h"
#include"Computers_Turn.c"
#include"Evil.c"
#include"GameScreen_Computer.c"
#include"GameScreen_Normal.c"
#include"Input_Name.c"
#include"isGameOver.c"
#include"PrintMatrix.c"
#include"Smart.c"

// Main function to present the Game Menu and call appropriate function according to user's choice
int main()
{
    int choice;
    TEXT_COLOR_DECLARATION; //Text color declaration - refer MACRO defined above

    while(1)
    {
        BLUE_COLOR_TEXT;
        printf("################ TIC TAC TOE ################\n\n");
        DEFAULT_COLOR_TEXT;

        //Input for Player Choice
        printf("1. Want to Play with Friend\n");
        printf("2. Want to Play with Smart Somputer\n");
        printf("3. Want to Play with Evil Computer\n");
        printf("4. Exit\n\n");
        printf("Enter your choice : ");
        choice=_getch()-'0';

        if(choice==1)//Play with Friend
        {
            char player1[100];
            char player2[100];
            printf("1\nEnter the Name of Player 1 : ");
            strcpy(player1,inputName(player1));
            printf("Enter the Name of Player 2 : ");
            strcpy(player2,inputName(player2));
            strcpy(player1,strupr(player1));
            strcpy(player2,strupr(player2));
            Normal(player1,player2);
        }
            
        else if(choice==2)//Play with Super Computer
        {
            char player[100];
            printf("2\nEnter Name of the Player : ");
            strcpy(player,inputName(player));
            strcpy(player,strupr(player));
            Smart(player);
        }

        else if(choice==3)//Play with Evil Computer
        {
            char player[100];
            printf("3\nEnter Name of the Player : ");
            strcpy(player,inputName(player));
            strcpy(player,strupr(player));
            Evil(player);
        }

        else if(choice==4)//Exit
        {
            printf("4\n");
            system("cls");
            exit(0);
        }

        else //Handle the Invalid User Input
        {
            RED_COLOR_TEXT;
            printf("%d\nInvalid Choice !",choice);
            sleep(1);
            system("cls");
        }
    }

    return 0;
}
