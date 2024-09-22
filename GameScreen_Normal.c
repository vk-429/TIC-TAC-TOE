#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"

// Function to display the game screen for normal mode
void GameScreen_Normal(char *player1,char *player2,char (*a)[3],int (*check)[3])
{
    TEXT_COLOR_DECLARATION;
    system("cls");
    BLUE_COLOR_TEXT;
    printf("################ TIC TAC TOE ################\n\n");
    GREEN_COLOR_TEXT;
    printf("               %s Vs %s\n\n",player1,player2);
    DEFAULT_COLOR_TEXT;
    printf("Mark of %s : O\n",player1);
    DEFAULT_COLOR_TEXT;
    printf("Mark of %s : ",player2);
    RED_COLOR_TEXT;
    printf("X\n\n");
    GREEN_COLOR_TEXT;

    // Printing Matrix
    PrintMatrix(a,check);

    DEFAULT_COLOR_TEXT;
}

// Function to handle normal game mode between two players
void Normal(char* player1,char* player2)
{
    TEXT_COLOR_DECLARATION;
    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int check[3][3]={0};

    // Initial Game Screen
    GameScreen_Normal(player1,player2,a,check);

    char markplace;
    int turn_no;

    // Loop to continue the Game until it is over
    for(turn_no=1;turn_no<=9;turn_no++)
    {
        input1:DEFAULT_COLOR_TEXT;

        // Taking player move input 
        if(turn_no%2)
            printf("%s, Enter your marking place : ",player1);
        else
            printf("%s, Enter your marking place : ",player2);
        markplace='\0';
        input:markplace=getch();

        // Checking for Invalid Input
        if(markplace<'1' || markplace>'9')goto input;

        int index=markplace-'1';
        int row=index/3;
        int column=index%3;

        if(check[row][column]) // Checking if place is already occupied
        {
            RED_COLOR_TEXT;
            printf("Place Already Occupied!");
            sleep(1);
            printf("\r\033[K");
            goto input1;
        }

        // Update Matrces
        if(turn_no%2)
            a[row][column]='O';
        else
            a[row][column]='X';
        check[row][column]=1;

        // Update Game Screen after every move
        GameScreen_Normal(player1,player2,a,check);

        // Checking if any player has won
        bool result=false;
        if(turn_no>=5)
            result=isGameOver(a);

        // Printing result  
        if(result==true)
        {
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            GREEN_COLOR_TEXT;
            if(turn_no%2)
                printf("                 %s WON!!!\n\n",player1);
            else
                printf("                 %s WON!!!\n\n",player2);
            return;
        }
        else if(turn_no==9)
        {
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            YELLOW_COLOR_TEXT;
            printf("                   DRAW!!!\n\n",player2);
            return;
        }   
    }
    
}

