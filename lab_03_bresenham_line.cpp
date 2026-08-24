#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, sx, sy, err, e2;

    printf("Enter first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = (x1 < x2) ? 1 : -1;
    sy = (y1 < y2) ? 1 : -1;
    err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        putpixel(x1, y1, WHITE);
        e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }

        delay(20);
    }

    putpixel(x1, y1, WHITE);
    outtextxy(20, 20, "Bresenham's Line Drawing Algorithm");

    getch();
    closegraph();
    return 0;
}
