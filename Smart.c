#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"

// Function to handle smart game mode with computer
void Smart(char *player)
{
    TEXT_COLOR_DECLARATION;
    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int check[3][3]={0};

    // Initial Game Screen
    GameScreen_Computer(player,a,check,0);

    char markplace;
    int turn_no;

    // Loop to continue the Game until it is over
    for(turn_no=0;turn_no<5;turn_no++)
    {
        input1:DEFAULT_COLOR_TEXT;

        // Taking player's move input
        printf("%s, Enter your marking place : ",player);
        markplace='\0';
        input:markplace=getch();

        // Checking for Invalid Input
        if(markplace<'1' || markplace>'9')goto input;

        int index=markplace-'1';
        int row=index/3;
        int column=index%3;

        if(check[row][column]) // Cheking if place is already occupied
        {
            RED_COLOR_TEXT;
            printf("Place Already Occupied!");
            sleep(1);
            printf("\r\033[K");
            goto input1;
        }

        // Update Matrices
        check[row][column]=1;
        a[row][column]='O';

        // Checking if Game is over(for player)
        bool result=false;
        if(turn_no>=2)
            result=isGameOver(a);

        // Printing Result(for player) 
        if(result==true)
        {
            GameScreen_Computer(player,a,check,0);
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            GREEN_COLOR_TEXT;
            printf("                 YOU WON!!!\n\n",player);
            return;
        }
        else if(turn_no==4)
        {
            GameScreen_Computer(player,a,check,0);
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            YELLOW_COLOR_TEXT;
            printf("                   DRAW!!!\n\n",player);
            return;
        }

        // Computer's move
        if(turn_no<=3)
            Computers_turn(a,check,0);
        
        sleep(0.5);
        GameScreen_Computer(player,a,check,0); // Update Game Screen after every move 

        // Checking if Game is over(for computer)
        if(turn_no>=2)
            result=isGameOver(a);

        // Printing Result(for computer) 
        if(result==true)
        {
            RED_COLOR_TEXT;
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            RED_COLOR_TEXT;
            printf("                 YOU LOST!!!\n\n",player);
            return;
        }
    }
}