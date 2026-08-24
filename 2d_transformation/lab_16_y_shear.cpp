#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float shy;
    int i;
    int x1[4] = {100, 200, 200, 100};
    int y1[4] = {10, 10, 200, 200};
    int x2[4], y2[4];

    printf("Enter shear factor shy: ");
    scanf("%f", &shy);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    for (i = 0; i < 4; i++) {
        line(x1[i], y1[i], x1[(i + 1) % 4], y1[(i + 1) % 4]);
    }
    outtextxy(20, 20, "Original Rectangle");

    setcolor(YELLOW);
    for (i = 0; i < 4; i++) {
        x2[i] = x1[i];
        y2[i] = (int)(y1[i] + shy * x1[i]);
    }

    for (i = 0; i < 4; i++) {
        line(x2[i], y2[i], x2[(i + 1) % 4], y2[(i + 1) % 4]);
    }
    outtextxy(20, 40, "Y-Shear");

    getch();
    closegraph();
    return 0;
}
