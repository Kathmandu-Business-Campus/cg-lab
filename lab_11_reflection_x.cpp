#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int i;
    int triangle[3][2] = {{30, 80}, {140, 80}, {80, 180}};
    int reflected[3][2];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(0, 240, 639, 240);
    line(320, 0, 320, 479);

    setcolor(WHITE);
    for (i = 0; i < 3; i++) {
        int x1 = triangle[i][0] + 320;
        int y1 = 240 - triangle[i][1];
        int x2 = triangle[(i + 1) % 3][0] + 320;
        int y2 = 240 - triangle[(i + 1) % 3][1];
        line(x1, y1, x2, y2);
    }

    getch();
    cleardevice();

    line(0, 240, 639, 240);
    line(320, 0, 320, 479);

    setcolor(YELLOW);
    for (i = 0; i < 3; i++) {
        reflected[i][0] = triangle[i][0];
        reflected[i][1] = 480 - triangle[i][1];

        int x1 = reflected[i][0] + 320;
        int y1 = 240 - reflected[i][1];
        int x2 = reflected[(i + 1) % 3][0] + 320;
        int y2 = 240 - reflected[(i + 1) % 3][1];
        line(x1, y1, x2, y2);
    }

    outtextxy(20, 20, "Reflection along X-axis");

    getch();
    closegraph();
    return 0;
}
