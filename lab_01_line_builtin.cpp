#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    line(100, 100, 350, 220);

    outtextxy(110, 80, "Built-in line() function");

    getch();
    closegraph();
    return 0;
}
