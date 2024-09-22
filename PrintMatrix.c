#include <stdio.h>
#include<windows.h>
#include "TIC_TAC_TOE.h"

// Function to print the game matrix
void PrintMatrix(char (*a)[3],int (*check)[3])
{
    int i,j,k=0;
    TEXT_COLOR_DECLARATION;

    for(i=0;i<5;i++)
    {
        if(i%2==0)
        {
            printf("                 ");
            for(j=0;j<2;j++)
            {
                if(check[k][j]==1)
                {
                    if(a[k][j]=='O'){DEFAULT_COLOR_TEXT;} 
                    else if(a[k][j]=='X'){RED_COLOR_TEXT;}    
                }
                printf(" %c ",a[k][j]);
                GREEN_COLOR_TEXT;
                printf("%c",columnline);
            }
            if(check[k][j]==1)
            {
                if(a[k][j]=='O'){DEFAULT_COLOR_TEXT;} 
                else if(a[k][j]=='X'){RED_COLOR_TEXT;}    
            }
            printf(" %c",a[k][j]);
            GREEN_COLOR_TEXT;
            k++;
        }
        else
        {
            printf("                ");
            for(j=0;j<6;j++)
                printf(" %c",rowline);
        }
        printf("\n");
    }
    printf("\n");
}

