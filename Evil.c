#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"

// Function to handle evil game mode with computer
void Evil(char *player)
{
    TEXT_COLOR_DECLARATION;
    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int check[3][3]={0};

    // Initial Game Screen
    GameScreen_Computer(player,a,check,1);

    char markplace;
    int occupancy=0;

    // Loop to continue the Game until it is over
    while(occupancy<9)
    {
        // Taking player's move input
        input1:DEFAULT_COLOR_TEXT;
        printf("%s, Enter your marking place : ",player);
        markplace='\0';
        input:markplace=getch();

        // Checking for Invalid Input
        if(markplace<'1' || markplace>'9')goto input;
        int index=markplace-'1';
        int row=index/3;
        int column=index%3;

        // Checking if place is already occupied
        if(check[row][column])
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

        // Evil Computer's turn
        Computers_turn(a,check,1);

        // Count occupied places and update occupancy count
        int count=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)count+=check[i][j];
        occupancy=count;

        // Checking if game is over
        bool result=false;
        if(occupancy>=5)
            result=isGameOver(a);

        sleep(0.5);
        GameScreen_Computer(player,a,check,1);// Update Game Screen after each move

        // Printing Result
        if(result==true)
        {
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            RED_COLOR_TEXT;
            printf("                 YOU LOST!!!\n\n",player);
            return;
        }
        else if(count==9)
        {
            sleep(2);
            system("cls");
            BLUE_COLOR_TEXT;
            printf("################ TIC TAC TOE ################\n\n");
            YELLOW_COLOR_TEXT;
            printf("                   DRAW!!!\n\n",player);
            return;
        }
    }
}