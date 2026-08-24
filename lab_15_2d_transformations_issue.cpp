#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

#define N 4

void draw_polygon(int x[], int y[], int n, int color) {
    int i;
    setcolor(color);
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void translate_polygon(int x[], int y[], int n, int tx, int ty) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

void scale_polygon(int x[], int y[], int n, float sx, float sy) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] = (int)(x[i] * sx);
        y[i] = (int)(y[i] * sy);
    }
}

void rotate_polygon(int x[], int y[], int n, float angle_deg) {
    int i;
    float angle = angle_deg * 3.14159265 / 180.0;
    float cosA = cos(angle), sinA = sin(angle);
    int xr, yr;

    for (i = 0; i < n; i++) {
        xr = (int)(x[i] * cosA - y[i] * sinA);
        yr = (int)(x[i] * sinA + y[i] * cosA);
        x[i] = xr;
        y[i] = yr;
    }
}

void reflect_polygon(int x[], int y[], int n, int axis) {
    int i;
    for (i = 0; i < n; i++) {
        if (axis == 0) {
            y[i] = -y[i];
        } else {
            x[i] = -x[i];
        }
    }
}

void shear_polygon(int x[], int y[], int n, float shx, float shy) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] = (int)(x[i] + shx * y[i]);
        y[i] = (int)(y[i] + shy * x[i]);
    }
}

int main() {
    int gd = DETECT, gm;
    int i, choice;
    int x[N] = {100, 200, 200, 100};
    int y[N] = {100, 100, 200, 200};
    int tx, ty;
    float sx, sy, angle, shx, shy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("2D Transformation Menu\n");
    printf("1. Translation\n2. Rotation\n3. Scaling\n4. Reflection X\n5. Reflection Y\n6. X-Shear\n7. Y-Shear\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    draw_polygon(x, y, N, WHITE);
    outtextxy(20, 20, "Original");

    switch (choice) {
        case 1:
            printf("Enter tx and ty: ");
            scanf("%d %d", &tx, &ty);
            translate_polygon(x, y, N, tx, ty);
            break;
        case 2:
            printf("Enter rotation angle in degrees: ");
            scanf("%f", &angle);
            rotate_polygon(x, y, N, angle);
            break;
        case 3:
            printf("Enter sx and sy: ");
            scanf("%f %f", &sx, &sy);
            scale_polygon(x, y, N, sx, sy);
            break;
        case 4:
            reflect_polygon(x, y, N, 0);
            break;
        case 5:
            reflect_polygon(x, y, N, 1);
            break;
        case 6:
            printf("Enter shx: ");
            scanf("%f", &shx);
            shear_polygon(x, y, N, shx, 0);
            break;
        case 7:
            printf("Enter shy: ");
            scanf("%f", &shy);
            shear_polygon(x, y, N, 0, shy);
            break;
        default:
            printf("Invalid choice");
            closegraph();
            return 0;
    }

    draw_polygon(x, y, N, YELLOW);
    outtextxy(20, 40, "Transformed");

    getch();
    closegraph();
    return 0;
}
