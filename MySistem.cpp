
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(void)
{
    int fg, op, num;

    srand(time(NULL)); // Gera um valor aleatorio
    system("cls");     // Limpa o console

    printf("Uma baguncinha em Roli udi");

    gotoxy(0, 5);
}