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

void VeKhung() {
    SetColor(11); // cyan

       for (int i = 0; i <= WIDTH + 1; i++) {
        gotoxy(i, 0); cout << char(219);
        gotoxy(i, HEIGHT); cout << char(219);
    }

    for (int i = 0; i <= HEIGHT; i++) {    
        gotoxy(0, i); cout << char(219);
        gotoxy(1, i); cout << char(219);

        gotoxy(WIDTH, i); cout << char(219);
        gotoxy(WIDTH + 1, i); cout << char(219);
    }
}

void VeThongTin(int score, int speed) {
    SetColor(14); // vàng
    gotoxy(WIDTH + 4, 2); cout << "SNAKE GAME";
    gotoxy(WIDTH + 4, 4); cout << "Score: " << score;
    gotoxy(WIDTH + 4, 5); cout << "Speed: " << 200 - speed;

    SetColor(10);
    gotoxy(WIDTH + 4, 7); cout << "W A S D: Move";
    gotoxy(WIDTH + 4, 8); cout << "P: Pause";
    gotoxy(WIDTH + 4, 9); cout << "ESC: Exit";
}

int main()
{
    // TODO: Setup game loop
    return 0;
}