#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

int round_value(float x) {
    return (int)(x + 0.5);
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int steps, k;
    float dx, dy, x, y, xincr, yincr;

    printf("Enter x1, y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2, y2: ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = x2 - x1;
    dy = y2 - y1;

    if (fabs(dx) > fabs(dy))
        steps = abs((int)dx);
    else
        steps = abs((int)dy);

    if (steps == 0)
        steps = 1;

    xincr = dx / (float)steps;
    yincr = dy / (float)steps;

    x = x1;
    y = y1;

    for (k = 0; k <= steps; k++) {
        putpixel(round_value(x), round_value(y), WHITE);
        x += xincr;
        y += yincr;
        delay(20);
    }

    outtextxy(20, 20, "DDA Line Drawing Algorithm");
    outtextxy(x1 + 5, y1 - 8, "A");
    outtextxy(x2 + 5, y2 + 5, "B");

    getch();
    closegraph();
    return 0;
}
