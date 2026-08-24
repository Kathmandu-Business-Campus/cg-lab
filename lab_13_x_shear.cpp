#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float shx;

    printf("Enter shear factor shx: ");
    scanf("%f", &shx);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    line(100, 0, 200, 0);
    line(200, 0, 200, 200);
    line(200, 200, 100, 200);
    line(100, 200, 100, 0);

    setcolor(YELLOW);
    line(100 + (0 * shx), 0, 200 + (0 * shx), 0);
    line(200 + (0 * shx), 0, 200 + (200 * shx), 200);
    line(200 + (200 * shx), 200, 100 + (200 * shx), 200);
    line(100 + (200 * shx), 200, 100 + (0 * shx), 0);

    outtextxy(20, 20, "X-shear");

    getch();
    closegraph();
    return 0;
}
