#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Point {
    int x, y;
};

struct Snake {
    Point Body[100];
    int length;
};

void gotoxy(int column, int line) {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE),
    coord
    );
}

void init(Snake& s) {
    s.length = 5;
    s.Body[0].x = 4; s.Body[0].y = 3;
    s.Body[1].x = 3; s.Body[1].y = 3;
    s.Body[2].x = 2; s.Body[2].y = 3;
    s.Body[3].x = 2; s.Body[3].y = 2;
    s.Body[4].x = 1; s.Body[4].y = 2;
}

void draw(Snake s) {
    system("cls");
    for (int i = 0; i < s.length; i++) {
        gotoxy(s.Body[i].x, s.Body[i].y);
        cout << "X";
    }
}

void run(Snake& s, int dir) {
    for (int i = s.length; i > 0; i++) {
        s.Body[i] = s.Body[i - 1];
    }
    if (dir == 0) s.Body[0].x = s.Body[0].x+1;
    if (dir == 1) s.Body[0].x = s.Body[0].y+1;
    if (dir == 2) s.Body[0].x = s.Body[0].x-1;
    if (dir == 3) s.Body[0].x = s.Body[0].y-1;
}

int main() {
    Snake s;
    int dir = 1; // 4 huong: 1, 2, 3, 0
    init(s);
    draw(s);
    char t;
    while (1) {
        if (kbhit()) {
            t = getch();
            if (t == 'w') dir = 3;
            else if (t == 'a') dir = 2;
            else if (t == 'z') dir = 1;
            else if (t == 'd') dir = 0;
            else if (t == 'q') break;
        }
        run(s, dir);
        draw(s);
        Sleep(500);
    }
    return 0;
}