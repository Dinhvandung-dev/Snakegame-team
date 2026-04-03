#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;
void gotoxy(int x, int y)
{
    if (x < 0 || y < 0)
        return;
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

const int WIDTH = 50;
const int HEIGHT = 20;

int main()
{
    // TODO: Setup game loop
    return 0;
}