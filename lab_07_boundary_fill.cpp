#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void boundary_fill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        delay(10);
        putpixel(x, y, fill_color);
        boundary_fill(x + 1, y, fill_color, boundary_color);
        boundary_fill(x - 1, y, fill_color, boundary_color);
        boundary_fill(x, y + 1, fill_color, boundary_color);
        boundary_fill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    int x, y, fill_color, boundary_color;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(200, 200, 70);

    printf("Enter seed point (x, y): ");
    scanf("%d %d", &x, &y);
    printf("Enter boundary color: ");
    scanf("%d", &boundary_color);
    printf("Enter fill color: ");
    scanf("%d", &fill_color);

    boundary_fill(x, y, fill_color, boundary_color);

    outtextxy(20, 20, "4-connected Boundary Fill");

    getch();
    closegraph();
    return 0;
}
