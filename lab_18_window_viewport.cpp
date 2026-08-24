#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void draw_window_viewport(int wx1, int wy1, int wx2, int wy2, int vx1, int vy1, int vx2, int vy2) {
    setcolor(WHITE);
    rectangle(wx1, wy1, wx2, wy2);
    setcolor(LIGHTGREEN);
    rectangle(vx1, vy1, vx2, vy2);
    outtextxy(wx1 + 10, wy1 - 15, "Window");
    outtextxy(vx1 + 10, vy1 - 15, "Viewport");
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int wx1 = 100, wy1 = 100, wx2 = 300, wy2 = 300;
    int vx1 = 360, vy1 = 120, vx2 = 560, vy2 = 320;
    float sx, sy;
    int mapped_x1, mapped_y1, mapped_x2, mapped_y2;

    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(BLACK);
    cleardevice();

    draw_window_viewport(wx1, wy1, wx2, wy2, vx1, vy1, vx2, vy2);

    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    outtextxy(20, 20, "Original line in window");

    sx = (float)(vx2 - vx1) / (wx2 - wx1);
    sy = (float)(vy2 - vy1) / (wy2 - wy1);

    mapped_x1 = vx1 + (int)((x1 - wx1) * sx);
    mapped_y1 = vy2 - (int)((y1 - wy1) * sy);
    mapped_x2 = vx1 + (int)((x2 - wx1) * sx);
    mapped_y2 = vy2 - (int)((y2 - wy1) * sy);

    setcolor(LIGHTCYAN);
    line(mapped_x1, mapped_y1, mapped_x2, mapped_y2);
    outtextxy(vx1 + 20, vy2 + 20, "Mapped line in viewport");

    outtextxy(20, 40, "Window-to-Viewport mapping is shown");

    getch();
    closegraph();
    return 0;
}
