#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x[4] = {100, 200, 200, 100};
    int y[4] = {100, 100, 200, 200};
    int tx, ty;
    int i;

    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    for (i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);
    }
    outtextxy(20, 20, "Original Rectangle");

    setcolor(YELLOW);
    for (i = 0; i < 4; i++) {
        line(x[i] + tx, y[i] + ty, x[(i + 1) % 4] + tx, y[(i + 1) % 4] + ty);
    }
    outtextxy(20, 40, "Translated Rectangle");

    getch();
    closegraph();
    return 0;
}
