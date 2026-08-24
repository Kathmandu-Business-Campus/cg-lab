#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

#define SIZE 8

// Seperate each transformation into its own program
// Rendering takes time

struct Point3D {
    float x, y, z;
};

void draw_cube(struct Point3D p[], int color) {
    int i;
    int sx[SIZE], sy[SIZE];

    for (i = 0; i < SIZE; i++) {
        sx[i] = (int)(p[i].x * 40 + 250);
        sy[i] = (int)(250 - p[i].y * 40 - p[i].z * 20);
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

void translate_3d(struct Point3D p[], int n, float tx, float ty, float tz) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].x += tx;
        p[i].y += ty;
        p[i].z += tz;
    }
}

void scale_3d(struct Point3D p[], int n, float sx, float sy, float sz) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].x *= sx;
        p[i].y *= sy;
        p[i].z *= sz;
    }
}

void rotate_x(struct Point3D p[], int n, float angle_deg) {
    int i;
    float a = angle_deg * 3.14159265 / 180.0;
    float c = cos(a), s = sin(a);
    for (i = 0; i < n; i++) {
        float y = p[i].y;
        float z = p[i].z;
        p[i].y = y * c - z * s;
        p[i].z = y * s + z * c;
    }
}

void rotate_y(struct Point3D p[], int n, float angle_deg) {
    int i;
    float a = angle_deg * 3.14159265 / 180.0;
    float c = cos(a), s = sin(a);
    for (i = 0; i < n; i++) {
        float x = p[i].x;
        float z = p[i].z;
        p[i].x = x * c + z * s;
        p[i].z = -x * s + z * c;
    }
}

void rotate_z(struct Point3D p[], int n, float angle_deg) {
    int i;
    float a = angle_deg * 3.14159265 / 180.0;
    float c = cos(a), s = sin(a);
    for (i = 0; i < n; i++) {
        float x = p[i].x;
        float y = p[i].y;
        p[i].x = x * c - y * s;
        p[i].y = x * s + y * c;
    }
}

void reflect_3d(struct Point3D p[], int n, int axis) {
    int i;
    for (i = 0; i < n; i++) {
        switch (axis) {
            case 1: p[i].x = -p[i].x; break;
            case 2: p[i].y = -p[i].y; break;
            case 3: p[i].z = -p[i].z; break;
        }
    }
}

void shear_3d(struct Point3D p[], int n, float shxy, float shxz, float shyx, float shyz, float shzx, float shzy) {
    int i;
    for (i = 0; i < n; i++) {
        float x = p[i].x;
        float y = p[i].y;
        float z = p[i].z;

        p[i].x = x + shxy * y + shxz * z;
        p[i].y = shyx * x + y + shyz * z;
        p[i].z = shzx * x + shzy * y + z;
    }
}

int main() {
    int gd = DETECT, gm;
    int choice;
    float tx, ty, tz, sx, sy, sz, angle;
    struct Point3D cube[SIZE] = {
        {1, 1, 1}, {2, 1, 1}, {2, 2, 1}, {1, 2, 1},
        {1, 1, 2}, {2, 1, 2}, {2, 2, 2}, {1, 2, 2}
    };

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("3D Transformation Menu\n");
    printf("1. Translation\n2. Scaling\n3. Rotation X\n4. Rotation Y\n5. Rotation Z\n6. Reflection\n7. Shear\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    draw_cube(cube, WHITE);
    outtextxy(20, 20, "Original 3D Object");
    getch();
    cleardevice();

    switch (choice) {
        case 1:
            printf("Enter tx ty tz: ");
            scanf("%f %f %f", &tx, &ty, &tz);
            translate_3d(cube, SIZE, tx, ty, tz);
            break;
        case 2:
            printf("Enter sx sy sz: ");
            scanf("%f %f %f", &sx, &sy, &sz);
            scale_3d(cube, SIZE, sx, sy, sz);
            break;
        case 3:
            printf("Enter angle in degrees: ");
            scanf("%f", &angle);
            rotate_x(cube, SIZE, angle);
            break;
        case 4:
            printf("Enter angle in degrees: ");
            scanf("%f", &angle);
            rotate_y(cube, SIZE, angle);
            break;
        case 5:
            printf("Enter angle in degrees: ");
            scanf("%f", &angle);
            rotate_z(cube, SIZE, angle);
            break;
        case 6:
            printf("Choose axis (1:X, 2:Y, 3:Z): ");
            scanf("%d", &choice);
            reflect_3d(cube, SIZE, choice);
            break;
        case 7:
            printf("Enter shxy shxz shyx shyz shzx shzy: ");
            scanf("%f %f %f %f %f %f", &tx, &ty, &tz, &sx, &sy, &sz);
            shear_3d(cube, SIZE, tx, ty, tz, sx, sy, sz);
            break;
        default:
            printf("Invalid choice");
            closegraph();
            return 0;
    }

    draw_cube(cube, YELLOW);
    outtextxy(20, 20, "Transformed 3D Object");
    getch();
    closegraph();
    return 0;
}
