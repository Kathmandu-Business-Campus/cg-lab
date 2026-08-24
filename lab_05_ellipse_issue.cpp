#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int xc, yc;

void draw_ellipse_points(int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int rx, ry;
    int x = 0, y = 0;
    int rx2, ry2;
    int p1, p2;

    printf("Enter center point (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter rx and ry: ");
    scanf("%d %d", &rx, &ry);

    if (rx <= 0 || ry <= 0) {
        printf("Radius values must be positive.\n");
        return 1;
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(BLACK);
    cleardevice();

    rx2 = rx * rx;
    ry2 = ry * ry;
    x = 0;
    y = ry;
    draw_ellipse_points(x, y);

    p1 = (ry2) - (rx2 * ry) + (rx2 / 4);
    while ((2 * ry2 * x) <= (2 * rx2 * y)) {
        x++;
        if (p1 <= 0) {
            p1 = p1 + (2 * ry2 * x) + ry2;
        } else {
            y--;
            p1 = p1 + (2 * ry2 * x) - (2 * rx2 * y) + ry2;
        }
        draw_ellipse_points(x, y);
    }

    p2 = (ry2 * (x + 1) * (x + 1)) + (rx2 * (y - 0.5) * (y - 0.5)) - (rx2 * ry2);
    while (y >= 0) {
        draw_ellipse_points(x, y);
        if (p2 > 0) {
            y--;
            p2 = p2 + (rx2) - (2 * rx2 * y);
        } else {
            x++;
            p2 = p2 + (2 * ry2 * x) + rx2;
        }
        if (x > rx) break;
    }

    outtextxy(20, 20, "Ellipse Generation Algorithm");
    outtextxy(20, 35, "Midpoint Ellipse Method");

    getch();
    closegraph();
    return 0;
}
