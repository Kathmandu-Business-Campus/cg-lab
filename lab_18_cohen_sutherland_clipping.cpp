#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int compute_code(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int xmin = 150, ymin = 150, xmax = 350, ymax = 350;
    int code1, code2, accept = 0, done = 0;
    float m, x, y;

    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    outtextxy(20, 20, "Original Line");

    code1 = compute_code(x1, y1, xmin, ymin, xmax, ymax);
    code2 = compute_code(x2, y2, xmin, ymin, xmax, ymax);

    while (!done) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            done = 1;
        } else if (code1 & code2) {
            done = 1;
        } else {
            if (code1 != 0) {
                m = (float)(y2 - y1) / (x2 - x1);
                if (code1 & LEFT) {
                    y = y1 + (xmin - x1) * m;
                    x = xmin;
                } else if (code1 & RIGHT) {
                    y = y1 + (xmax - x1) * m;
                    x = xmax;
                } else if (code1 & BOTTOM) {
                    x = x1 + (ymin - y1) / m;
                    y = ymin;
                } else if (code1 & TOP) {
                    x = x1 + (ymax - y1) / m;
                    y = ymax;
                }
                x1 = (int)x;
                y1 = (int)y;
                code1 = compute_code(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                m = (float)(y2 - y1) / (x2 - x1);
                if (code2 & LEFT) {
                    y = y2 + (xmin - x2) * m;
                    x = xmin;
                } else if (code2 & RIGHT) {
                    y = y2 + (xmax - x2) * m;
                    x = xmax;
                } else if (code2 & BOTTOM) {
                    x = x2 + (ymin - y2) / m;
                    y = ymin;
                } else if (code2 & TOP) {
                    x = x2 + (ymax - y2) / m;
                    y = ymax;
                }
                x2 = (int)x;
                y2 = (int)y;
                code2 = compute_code(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(GREEN);
        line(x1, y1, x2, y2);
        outtextxy(20, 20, "Clipped Line");
    } else {
        outtextxy(20, 20, "Line Completely Outside");
    }

    getch();
    closegraph();
    return 0;
}
