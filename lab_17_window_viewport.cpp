#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void draw_window_viewport(int wx1, int wy1, int wx2, int wy2, int vx1, int vy1, int vx2, int vy2) {
    setcolor(WHITE);
    rectangle(wx1, wy1, wx2, wy2);
    rectangle(vx1, vy1, vx2, vy2);
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int wx1 = 100, wy1 = 100, wx2 = 300, wy2 = 300;
    int vx1 = 350, vy1 = 100, vx2 = 550, vy2 = 300;

    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    draw_window_viewport(wx1, wy1, wx2, wy2, vx1, vy1, vx2, vy2);

    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    outtextxy(20, 20, "Window");
    outtextxy(vx1 + 20, vy2 + 20, "Viewport");

    getch();
    closegraph();
    return 0;
}
