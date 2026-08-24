#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void flood_fill(int x, int y, int new_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        delay(10);
        putpixel(x, y, new_color);
        flood_fill(x + 1, y, new_color, old_color);
        flood_fill(x - 1, y, new_color, old_color);
        flood_fill(x, y + 1, new_color, old_color);
        flood_fill(x, y - 1, new_color, old_color);
        flood_fill(x + 1, y + 1, new_color, old_color);
        flood_fill(x - 1, y + 1, new_color, old_color);
        flood_fill(x + 1, y - 1, new_color, old_color);
        flood_fill(x - 1, y - 1, new_color, old_color);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle(150, 150, 300, 250);
    flood_fill(180, 180, 12, 0);

    outtextxy(20, 20, "8-connected Flood Fill");

    getch();
    closegraph();
    return 0;
}
