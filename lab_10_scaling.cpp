#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2, sx, sy;
    float x3, y3, x4, y4;

    printf("Enter starting point (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter ending point (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 5, y2, "Object");

    x3 = x1 * sx;
    y3 = y1 * sy;
    x4 = x2 * sx;
    y4 = y2 * sy;

    setcolor(YELLOW);
    line(x3, y3, x4, y4);
    outtextxy(x4 + 5, y4, "Image");

    getch();
    closegraph();
    return 0;
}
