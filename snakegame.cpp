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

    void TaoMoi() {
        bool trung;
        do {
            trung = false;
            // Đảm bảo mồi luôn xuất hiện ở tọa độ chẵn (2, 4, 6... 48)
            Moi.x = (rand() % ((WIDTH - 2) / 2)) * 2 + 2;
            Moi.y = rand() % (HEIGHT - 1) + 1; // y có thể lẻ




            // Kiểm tra trùng thân rắn
            for (int i = 0; i < DoDai; i++) {
                if (A[i].x == Moi.x && A[i].y == Moi.y) {
                    trung = true;
                    break;
                }
            }
        } while (trung);

        SetColor(12);
        gotoxy(Moi.x, Moi.y);
        cout << char(219) << char(219);
    }

    Point DiChuyen(int Huong) {
        Point tail = A[DoDai - 1];

        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x += 2; // Đi phải
        if (Huong == 2) A[0].x -= 2; // Đi trái
        if (Huong == 1) A[0].y++;    // Đi xuống
        if (Huong == 3) A[0].y--;    // Đi lên

        return tail;
    }

    void Ve(Point tail) {
        if (tail.x != A[DoDai - 1].x || tail.y != A[DoDai - 1].y) {
            gotoxy(tail.x, tail.y);
            cout << "  "; 
        }

        for (int i = 0; i < DoDai; i++) {
            SetColor(i == 0 ? 10 : 2); // Đầu màu xanh lá nhạt, thân xanh lá đậm
            gotoxy(A[i].x, A[i].y);
            cout << char(219) << char(219);
        }
    }

    void KiemTraAnMoi(Point tail) {
        if (A[0].x == Moi.x && A[0].y == Moi.y) {
            A[DoDai] = tail;
            DoDai++;
            score += 10;
            if (speed > 50) speed -= 5;
            Beep(1500, 50);
            TaoMoi();
        }
    }

    bool KiemTraChet() {       
        if (A[0].x < 2 || A[0].x > WIDTH - 2 || A[0].y <= 0 || A[0].y >= HEIGHT)
            return true;

        // Kiểm tra cắn vào thân
        for (int i = 1; i < DoDai; i++)
            if (A[0].x == A[i].x && A[0].y == A[i].y)
                return true;
        return false;
    }

};


int main() {
    cout << endl;
    system("mode con cols=100 lines=30");
    SetConsoleOutputCP(437);
    srand(time(0));
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    ManHinhStart();
    VeKhung();
    CONRAN r;
    int Huong = 0;
    bool pause = false;
    r.Ve(r.A[r.DoDai - 1]);
    while (true) {
        if (kbhit()) {
            char t = getch();
            if (t == 27) break; // ESC
            if (t == 'p' || t == 'P') pause = !pause;
            if (!pause) {
                if ((t == 'a' || t == 'A') && Huong != 0) Huong = 2;
                if ((t == 'd' || t == 'D') && Huong != 2) Huong = 0;
                if ((t == 'w' || t == 'W') && Huong != 1) Huong = 3;
                if ((t == 's' || t == 'S') && Huong != 3) Huong = 1;
            }
        }
        if (!pause) {
            Point tail = r.DiChuyen(Huong);
                if (r.KiemTraChet()) {
                Beep(500, 1000);
                GameOverScreen(r.score);
                break;
            }
            r.KiemTraAnMoi(tail);
            r.Ve(tail);
        }
        VeThongTin(r.score, r.speed);
        Sleep(r.speed);
    }
    return 0;
}
