#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

#define N 4

int main() {
    int gd = DETECT, gm;
    int x[N] = {100, 200, 200, 100};
    int y[N] = {100, 100, 200, 200};
    int i;
    float angle, rad, xr, yr;
    int cx = 150, cy = 150;

    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    for (i = 0; i < N; i++) {
        line(x[i], y[i], x[(i + 1) % N], y[(i + 1) % N]);
    }
    outtextxy(20, 20, "Original Rectangle");

    rad = angle * 3.14159265 / 180.0;
    setcolor(YELLOW);
    for (i = 0; i < N; i++) {
        int px = x[i] - cx;
        int py = y[i] - cy;
        xr = px * cos(rad) - py * sin(rad);
        yr = px * sin(rad) + py * cos(rad);
        x[i] = (int)(cx + xr);
        y[i] = (int)(cy + yr);
    }

    for (i = 0; i < N; i++) {
        line(x[i], y[i], x[(i + 1) % N], y[(i + 1) % N]);
    }
    outtextxy(20, 40, "Rotated Rectangle");

    getch();
    closegraph();
    return 0;
}
