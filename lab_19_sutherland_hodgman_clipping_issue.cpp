#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define MAX 20

int inside(double x, double y, int edge) {
    if (edge == 0) return y >= 0;
    if (edge == 1) return x <= 200;
    if (edge == 2) return y <= 200;
    if (edge == 3) return x >= 0;
    return 0;
}

double intersection(double x1, double y1, double x2, double y2, int edge) {
    double x, y;
    if (edge == 0) {
        x = x1 + (0 - y1) * (x2 - x1) / (y2 - y1);
        y = 0;
    } else if (edge == 1) {
        x = 200;
        y = y1 + (200 - x1) * (y2 - y1) / (x2 - x1);
    } else if (edge == 2) {
        x = x1 + (200 - y1) * (x2 - x1) / (y2 - y1);
        y = 200;
    } else {
        x = 0;
        y = y1 + (0 - x1) * (y2 - y1) / (x2 - x1);
    }
    return (edge == 0 || edge == 2) ? y : x;
}

void draw_polygon(int x[], int y[], int n, int color) {
    int i;
    setcolor(color);
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

int main() {
    int gd = DETECT, gm;
    int i, n = 5;
    int x[MAX] = {20, 180, 140, 80, 20};
    int y[MAX] = {20, 20, 120, 160, 20};
    int out[MAX], outx[MAX], outy[MAX], count;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    draw_polygon(x, y, n, WHITE);
    outtextxy(20, 20, "Original Polygon");
    getch();
    cleardevice();

    for (i = 0; i < 4; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            int k = (j + 1) % n;
            int s1 = inside(x[j], y[j], i);
            int s2 = inside(x[k], y[k], i);

            if (s1 && s2) {
                out[count++] = (int)x[k];
                outy[count++] = (int)y[k];
            } else if (s1 && !s2) {
                outx[count] = x[j];
                outy[count] = y[j];
                count++;
                outx[count] = x[j];
                outy[count] = y[j];
                count++;
            } else if (!s1 && s2) {
                outx[count] = x[j];
                outy[count] = y[j];
                count++;
                outx[count] = x[j];
                outy[count] = y[j];
                count++;
            }
        }

        for (int j = 0; j < count; j++) {
            x[j] = outx[j];
            y[j] = outy[j];
        }
        n = count;
    }

    draw_polygon(x, y, n, GREEN);
    outtextxy(20, 20, "Clipped Polygon");
    getch();
    closegraph();
    return 0;
}
