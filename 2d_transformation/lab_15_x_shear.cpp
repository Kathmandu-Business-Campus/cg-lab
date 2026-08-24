#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float shx;
    int i;
    int x1[4] = {100, 200, 200, 100};
    int y1[4] = {0, 0, 200, 200};
    int x2[4], y2[4];

    printf("Enter shear factor shx: ");
    scanf("%f", &shx);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    for (i = 0; i < 4; i++) {
        line(x1[i], y1[i], x1[(i + 1) % 4], y1[(i + 1) % 4]);
    }
    outtextxy(20, 20, "Original Rectangle");

    setcolor(YELLOW);
    for (i = 0; i < 4; i++) {
        x2[i] = (int)(x1[i] + shx * y1[i]);
        y2[i] = y1[i];
    }

    for (i = 0; i < 4; i++) {
        line(x2[i], y2[i], x2[(i + 1) % 4], y2[(i + 1) % 4]);
    }
    outtextxy(20, 40, "X-Shear");

    getch();
    closegraph();
    return 0;
}
