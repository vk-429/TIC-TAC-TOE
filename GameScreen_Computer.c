#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"


// Function to display the game screen for computer mode(evil or smart)
// isEvil == 0 --> Smart Computer
// isEvil == 1 --> Evil Computer
void GameScreen_Computer(char *player,char (*a)[3],int (*check)[3],int isEvil)
{
    TEXT_COLOR_DECLARATION;
    system("cls");
    BLUE_COLOR_TEXT;
    printf("################ TIC TAC TOE ################\n\n");
    GREEN_COLOR_TEXT;
    if(isEvil==1)
        printf("           %s Vs EVIL COMPUTER\n\n",player);
    else
        printf("           %s Vs SMART COMPUTER\n\n",player);  
    DEFAULT_COLOR_TEXT;
    printf("Mark of %s : O\n",player);
    DEFAULT_COLOR_TEXT;
    printf("Mark of COMPUTER : ");
    RED_COLOR_TEXT;
    printf("X\n\n");
    GREEN_COLOR_TEXT;

    // Printing Matrix 
    PrintMatrix(a,check);

    DEFAULT_COLOR_TEXT;
}

