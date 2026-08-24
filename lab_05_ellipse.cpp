#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

float x, y;
int xc, yc;

void draw_ellipse_points() {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int rx, ry;
    float p1, p2;

    printf("Enter center point (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter rx and ry: ");
    scanf("%d %d", &rx, &ry);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = 0;
    y = ry;
    draw_ellipse_points();

    p1 = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4.0);

    while ((2.0 * ry * ry * x) <= (2.0 * rx * rx * y)) {
        x++;
        if (p1 <= 0) {
            p1 = p1 + (2.0 * ry * ry * x) + (ry * ry);
        } else {
            y--;
            p1 = p1 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (ry * ry);
        }
        draw_ellipse_points();
    }

    x = 0;
    y = 0;
    p2 = (rx * rx) + (2.0 * ry * ry * rx) + ((ry * ry) / 4.0);

    while ((2.0 * ry * ry * x) > (2.0 * rx * rx * y)) {
        y++;
        if (p2 > 0) {
            p2 = p2 + (rx * rx) - (2.0 * rx * rx * y);
        } else {
            x--;
            p2 = p2 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
        }
        draw_ellipse_points();
    }

    outtextxy(20, 20, "Ellipse Generation Algorithm");

    getch();
    closegraph();
    return 0;
}
