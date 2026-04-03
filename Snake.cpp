#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

#define MINX 0
#define MAXX 79
#define MINY 0
#define MAXY 23

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Point {
    int x, y;
};

class CONRAN {
public:
    Point A[100];
    int DoDai;
    CONRAN() {
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve() {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
    }
    void DiChuyen(int Huong) {
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x++;
        if (Huong == 1) A[0].y++;
        if (Huong == 2) A[0].x--;
        if (Huong == 3) A[0].y--;
    }
};

void VeKhung() {
    for (int i = MINX; i <= MAXX; i++) {
        gotoxy(i, MINY); cout << "+";
        gotoxy(i, MAXY); cout << "+";
    }
    for (int j = MINY; j <= MAXY; j++) {
        gotoxy(MINX, j); cout << "+";
        gotoxy(MAXX, j); cout << "+";
    }
}

int main() {
    CONRAN r;
    int Huong = 0;
    char t;

    while (1) {
        if (kbhit()) {
            t = getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 'x') Huong = 1;
        }
        system("cls");
        VeKhung();
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(300);
    }
    return 0;
}
