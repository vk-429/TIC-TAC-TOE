#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

void PrintMatrix(char (*a)[3], int (*check)[3]);
bool isGameOver(char (*a)[3]);
void GameScreen_Normal(char *player1, char *player2, char (*a)[3], int (*check)[3]);
void Normal(char* player1, char* player2);
void GameScreen_Computer(char *player, char (*a)[3], int (*check)[3], int isEvil);
void Smart(char *player);
void Evil(char *player);
void Computers_turn(char (*a)[3], int (*check)[3], int isEvil);

// Color definitions for console text
#define TEXT_COLOR_DECLARATION HANDLE hConsole;hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define BLUE_COLOR_TEXT SetConsoleTextAttribute(hConsole, 9);
#define GREEN_COLOR_TEXT SetConsoleTextAttribute(hConsole, 2);
#define RED_COLOR_TEXT SetConsoleTextAttribute(hConsole, 12);
#define DEFAULT_COLOR_TEXT SetConsoleTextAttribute(hConsole, 15);
#define YELLOW_COLOR_TEXT SetConsoleTextAttribute(hConsole, 6);

// Enum for border characters
enum borderlines{columnline='|',rowline=196};

#endif
