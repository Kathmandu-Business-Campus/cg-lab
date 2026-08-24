#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int n, i, j, k, gd = DETECT, gm;
    int x[20], y[20], xi[20], temp;
    int a[20][2], ymin, ymax;
    float slope[20];

    printf("Enter number of vertices of polygon: ");
    scanf("%d", &n);

    printf("Enter polygon vertices (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    for (i = 0; i < n; i++) {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    getch();

    for (i = 0; i < n; i++) {
        int dy = a[i + 1][1] - a[i][1];
        int dx = a[i + 1][0] - a[i][0];

        if (dy == 0)
            slope[i] = 1.0;
        else if (dx == 0)
            slope[i] = 0.0;
        else
            slope[i] = (float)dx / dy;
    }

    for (int scan_y = 0; scan_y < getmaxy(); scan_y++) {
        k = 0;
        for (i = 0; i < n; i++) {
            if (((a[i][1] <= scan_y) && (a[i + 1][1] > scan_y)) ||
                ((a[i][1] > scan_y) && (a[i + 1][1] <= scan_y))) {
                xi[k] = (int)(a[i][0] + slope[i] * (scan_y - a[i][1]));
                k++;
            }
        }

        for (j = 0; j < k - 1; j++) {
            for (i = 0; i < k - 1; i++) {
                if (xi[i] > xi[i + 1]) {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
        }

        for (i = 0; i < k; i += 2) {
            line(xi[i], scan_y, xi[i + 1] + 1, scan_y);
        }
    }

    outtextxy(20, 20, "Scan-Line Polygon Fill Algorithm");

    getch();
    closegraph();
    return 0;
}
