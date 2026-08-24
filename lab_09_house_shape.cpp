#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(60, 80, 150, 200);
    rectangle(95, 140, 120, 200);
    line(60, 80, 105, 20);
    line(105, 20, 150, 80);
    circle(105, 60, 10);

    outtextxy(20, 20, "House Shape");

    getch();
    closegraph();
    return 0;
}
