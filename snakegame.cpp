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

struct Point {
    int x, y;
};


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

void ManHinhStart() {
    system("cls");
    SetColor(10);
    gotoxy(20, 8); cout << "SNAKE GAME";
    gotoxy(18, 10); cout << "Press any key to start...";
    getch();
    system("cls");
}
void GameOverScreen(int score) {
    SetColor(12);
    gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    cout << "GAME OVER!";

    SetColor(14);
    gotoxy(WIDTH / 2 - 6, HEIGHT / 2 + 1);
    cout << "Score: " << score;

    SetColor(7);
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 3);
    cout << "Press any key to exit...";
    getch();
}

// ================= GAME =================
class CONRAN {
public:
    Point A[200];
    int DoDai;
    Point Moi;
    int speed;
    int score;




    CONRAN() {
        DoDai = 3;
        A[0] = {10, 10};
        A[1] = {8, 10};
        A[2] = {6, 10};
        speed = 150;
        score = 0;
        TaoMoi();
    }
};


int main()
{
    // TODO: Setup game loop
    return 0;
}