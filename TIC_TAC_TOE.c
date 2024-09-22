#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include <unistd.h>
#include <stdbool.h>

// Color definitions for console text
#define TEXT_COLOR_DECLARATION HANDLE hConsole;hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define BLUE_COLOR_TEXT SetConsoleTextAttribute(hConsole, 9);
#define GREEN_COLOR_TEXT SetConsoleTextAttribute(hConsole, 2);
#define RED_COLOR_TEXT SetConsoleTextAttribute(hConsole, 12);
#define DEFAULT_COLOR_TEXT SetConsoleTextAttribute(hConsole, 15);
#define YELLOW_COLOR_TEXT SetConsoleTextAttribute(hConsole, 6);

// Enum for border characters
enum borderlines{columnline='|',rowline=196};

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
