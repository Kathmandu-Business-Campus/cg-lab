#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define SIZE 8

typedef struct {
    float x, y, z;
} Point3D;

void draw_cube(Point3D p[], int color) {
    int i;
    int sx[SIZE], sy[SIZE];

    for (i = 0; i < SIZE; i++) {
        sx[i] = (int)(p[i].x * 40 + 230);
        sy[i] = (int)(280 - p[i].y * 40 - p[i].z * 25);
    }

    setcolor(color);
    line(sx[0], sy[0], sx[1], sy[1]);
    line(sx[1], sy[1], sx[2], sy[2]);
    line(sx[2], sy[2], sx[3], sy[3]);
    line(sx[3], sy[3], sx[0], sy[0]);
    line(sx[4], sy[4], sx[5], sy[5]);
    line(sx[5], sy[5], sx[6], sy[6]);
    line(sx[6], sy[6], sx[7], sy[7]);
    line(sx[7], sy[7], sx[4], sy[4]);
    line(sx[0], sy[0], sx[4], sy[4]);
    line(sx[1], sy[1], sx[5], sy[5]);
    line(sx[2], sy[2], sx[6], sy[6]);
    line(sx[3], sy[3], sx[7], sy[7]);
}

int main() {
    int gd = DETECT, gm;
    float angle, rad;
    int i;
    Point3D cube[SIZE] = {
        {1, 1, 1}, {2, 1, 1}, {2, 2, 1}, {1, 2, 1},
        {1, 1, 2}, {2, 1, 2}, {2, 2, 2}, {1, 2, 2}
    };

    printf("Enter rotation angle around X-axis in degrees: ");
    scanf("%f", &angle);
    rad = angle * 3.14159265 / 180.0;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    draw_cube(cube, WHITE);
    outtextxy(20, 20, "Original Cube");
    getch();
    cleardevice();

    for (i = 0; i < SIZE; i++) {
        float y = cube[i].y;
        float z = cube[i].z;
        cube[i].y = y * cos(rad) - z * sin(rad);
        cube[i].z = y * sin(rad) + z * cos(rad);
    }

    draw_cube(cube, YELLOW);
    outtextxy(20, 20, "Rotated around X");

    getch();
    closegraph();
    return 0;
}
