#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"

// Function to input player name
char* inputName(char *player)
{
    TEXT_COLOR_DECLARATION; 

    while(1)
    {
        fflush(stdin);
        fgets(player,100,stdin);
        player[strlen(player)-1]='\0';

        if(strlen(player)==0)// Check whether user presses enter without entering any name
        {
            RED_COLOR_TEXT;
            printf("Please Enter Some Name!");
            DEFAULT_COLOR_TEXT;
            sleep(1);
            printf("\r\033[K");
        }
        else
        {
            DEFAULT_COLOR_TEXT;
            return player;
        }
    } 
}
