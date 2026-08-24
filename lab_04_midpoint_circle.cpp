#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void plot_circle_points(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    int x = 0, y, p;

    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius r: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = 0;
    y = r;
    p = 1 - r;

    while (x <= y) {
        plot_circle_points(xc, yc, x, y);
        delay(40);

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    outtextxy(20, 20, "Midpoint Circle Algorithm");

    getch();
    closegraph();
    return 0;
}
