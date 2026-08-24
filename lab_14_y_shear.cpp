#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    float shy;

    printf("Enter shear factor shy: ");
    scanf("%f", &shy);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    line(100, 10, 200, 10);
    line(200, 10, 200, 200);
    line(200, 200, 100, 200);
    line(100, 200, 100, 10);

    setcolor(YELLOW);
    line(100, 10 + (shy * 100), 200, 10 + (shy * 200));
    line(200, 10 + (shy * 200), 200, 200 + (shy * 200));
    line(200, 200 + (shy * 200), 100, 200 + (shy * 100));
    line(100, 200 + (shy * 100), 100, 10 + (shy * 100));

    outtextxy(20, 20, "Y-shear");

    getch();
    closegraph();
    return 0;
}
