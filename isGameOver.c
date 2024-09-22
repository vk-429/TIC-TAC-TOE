#include <stdbool.h>
#include "TIC_TAC_TOE.h"

// Function to check if the game is over
bool isGameOver(char (*a)[3])
{
    int i,j,k=0;
    int freqx[8]={0}; // Counters for 'X'
    int freqo[8]={0}; // Counters for 'O'

    // Checking rows, columns, and diagonals for winning condition
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='X')
            {
                freqx[i]++;
                freqx[j+3]++;
                if(i==j)freqx[6]++;
                if(i==(2-j))freqx[7]++;
            }
            else if(a[i][j]=='O')
            {
                freqo[i]++;
                freqo[j+3]++;
                if(i==j)freqo[6]++;
                if(i==(2-j))freqo[7]++;
            }
        }
    }

    // Checking if any counter reached 3, meaning a player has won
    for(i=0;i<8;i++)
        if(freqx[i]==3 || freqo[i]==3)
            return true;
    return false;
}
