#include<stdio.h>
#include"TIC_TAC_TOE.h"

// Function to insert 'X' in the specified row
void insert_in_row(char (*a)[3],int (*check)[3],int i)
{
    for(int j=0;j<3;j++)
    {
        if(check[i][j]==0)
        {
            a[i][j]='X';
            check[i][j]=1;
            return;
        }
    }
}

// Function to insert 'X' in the specified column
void insert_in_column(char (*a)[3],int (*check)[3],int i)
{
    for(int j=0;j<3;j++)
    {
        if(check[j][i]==0)
        {
            a[j][i]='X';
            check[j][i]=1;
            return;
        }
    }
}

// Function to insert 'X' in the main diagonal
void insert_in_diag1(char (*a)[3],int (*check)[3])
{
    for(int j=0;j<3;j++)
    {
        if(check[j][j]==0)
        {
            a[j][j]='X';
            check[j][j]=1;
            return;
        }
    }
}

// Function to insert 'X' in the anti-diagonal
void insert_in_diag2(char (*a)[3],int (*check)[3])
{
    for(int j=0;j<3;j++)
    {
        if(check[j][2-j]==0)
        {
            a[j][2-j]='X';
            check[j][2-j]=1;
            return;
        }
    }
}

// Function to insert 'X' in the first empty spot
void insert(char (*a)[3],int (*check)[3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(check[i][j]==0)
            {
                a[i][j]='X';
                check[i][j]=1;
                return;
            }
        }
    }
}

// Function to handle the Computer's Turn in both mode depending upon the value of isEvil 
// isEvil == 0 --> Smart Computer
// isEvil == 1 --> Evil Computer
void Computers_turn(char (*a)[3],int (*check)[3],int isEvil)
{
    int i,j;
    int win_row_index=-1;
    int win_column_index=-1;
    int win_diag1_flag=0;
    int win_diag2_flag=0;
    int row_index=-1;
    int column_index=-1;
    int diag1_flag=0;
    int diag2_flag=0;
    int row_count01_index=-1;
    int column_count01_index=-1;
    int diag1_count01_flag=0;
    int diag2_count01_flag=0;
    
    // Analyze the board to determine the next move
    for(i=0;i<3;i++)
    {
        int count_row0=0;
        int count_rowx=0;
        int count_column0=0;
        int count_columnx=0;
        int diag1_count0=0;
        int diag1_countx=0;
        int diag2_count0=0;
        int diag2_countx=0;

        for(j=0;j<3;j++)
        {
            if(a[i][j]=='O') count_row0++;
            else if(a[i][j]=='X') count_rowx++;
            if(a[j][i]=='O') count_column0++;
            else if(a[j][i]=='X') count_columnx++;
            if(a[j][j]=='O') diag1_count0++;
            else if(a[j][j]=='X') diag1_countx++;
            if(a[j][2-j]=='O') diag2_count0++;
            else if(a[j][2-j]=='X') diag2_countx++;
        }

        if(count_rowx==2 && count_row0==0) win_row_index=i;
        else if(count_row0==2 && count_rowx==0) row_index=i;
        else if(count_row0==0 && count_rowx==1) row_count01_index=i;
        if(count_columnx==2 && count_column0==0) win_column_index=i;
        else if(count_column0==2 && count_columnx==0) column_index=i;
        else if(count_column0==0 && count_columnx==1) column_count01_index=i;
        if(diag1_countx==2 && diag1_count0==0) win_diag1_flag=1;
        else if(diag1_count0==2 && diag1_countx==0) diag1_flag=1;
        else if(diag1_count0==0 && diag1_countx==1) diag1_count01_flag=1;
        if(diag2_countx==2 && diag2_count0==0) win_diag2_flag=1;
        else if(diag2_count0==2 && diag2_countx==0) diag2_flag=1;
        else if(diag2_count0==0 && diag2_countx==1) diag2_count01_flag=1; 
    }

    // First priority: Win if possible
    if(win_row_index!=-1) insert_in_row(a,check,win_row_index);
    else if(win_column_index!=-1) insert_in_column(a,check,win_column_index);
    else if(win_diag1_flag==1) insert_in_diag1(a,check);
    else if(win_diag2_flag==1) insert_in_diag2(a,check);

    // Second priority: Block the opponent
    else if(row_index!=-1) insert_in_row(a,check,row_index);
    else if(column_index!=-1) insert_in_column(a,check,column_index);
    else if(diag1_flag==1) insert_in_diag1(a,check);
    else if(diag2_flag==1) insert_in_diag2(a,check);

    // Otherwise, choose a position inteding to win
    else if(row_count01_index!=-1) insert_in_row(a,check,row_count01_index);
    else if(column_count01_index!=-1) insert_in_column(a,check,column_count01_index);
    else if(diag1_count01_flag==1) insert_in_diag1(a,check);
    else if(diag2_count01_flag==1) insert_in_diag2(a,check);

    // If none of the above, choose the first available position
    else insert(a,check);

    // Cheking if game is not over, then block opponent in each possibility to win in next move 
    if(!isGameOver(a) && isEvil==1)
    {
        if(row_index!=-1) insert_in_row(a,check,row_index);
        if(column_index!=-1) insert_in_column(a,check,column_index);
        if(diag1_flag==1) insert_in_diag1(a,check);
        if(diag2_flag==1) insert_in_diag2(a,check);
    }
}
