#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define N 3

int main() {
    int gd = DETECT, gm;
    int triangle[N][2] = {{30, 80}, {140, 80}, {80, 180}};
    int i;
    int cx = 320, cy = 240;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(0, cy, 639, cy);
    line(cx, 0, cx, 479);
    setcolor(WHITE);
    for (i = 0; i < N; i++) {
        int x1 = triangle[i][0] + cx;
        int y1 = cy - triangle[i][1];
        int x2 = triangle[(i + 1) % N][0] + cx;
        int y2 = cy - triangle[(i + 1) % N][1];
        line(x1, y1, x2, y2);
    }
    outtextxy(20, 20, "Original Triangle");

    setcolor(YELLOW);
    for (i = 0; i < N; i++) {
        int x1 = (-(triangle[i][0])) + cx;
        int y1 = cy - triangle[i][1];
        int x2 = (-(triangle[(i + 1) % N][0])) + cx;
        int y2 = cy - triangle[(i + 1) % N][1];
        line(x1, y1, x2, y2);
    }
    outtextxy(20, 40, "Reflection across Y-axis");

    getch();
    closegraph();
    return 0;
}
