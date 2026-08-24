#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x[4] = {100, 200, 200, 100};
    int y[4] = {100, 100, 200, 200};
    int i;
    float sx, sy;

    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    for (i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);
    }
    outtextxy(20, 20, "Original Rectangle");

    setcolor(YELLOW);
    for (i = 0; i < 4; i++) {
        line((int)(x[i] * sx), (int)(y[i] * sy), (int)(x[(i + 1) % 4] * sx), (int)(y[(i + 1) % 4] * sy));
    }
    outtextxy(20, 40, "Scaled Rectangle");

    getch();
    closegraph();
    return 0;
}
