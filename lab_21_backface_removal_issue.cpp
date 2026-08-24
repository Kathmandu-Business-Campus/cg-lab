#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point3D;

typedef struct {
    Point3D p1, p2, p3;
} Triangle;

double dot(Point3D a, Point3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(Point3D a, Point3D b) {
    Point3D c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

int main() {
    Triangle t = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 0}
    };
    Point3D view = {0, 0, -1};
    Point3D u, v, normal;

    u.x = t.p2.x - t.p1.x;
    u.y = t.p2.y - t.p1.y;
    u.z = t.p2.z - t.p1.z;

    v.x = t.p3.x - t.p1.x;
    v.y = t.p3.y - t.p1.y;
    v.z = t.p3.z - t.p1.z;

    normal = cross(u, v);

    printf("Triangle normal: (%.2f, %.2f, %.2f)\n", normal.x, normal.y, normal.z);

    if (dot(normal, view) < 0) {
        printf("Back-face removed: triangle is facing away from the viewer.\n");
    } else {
        printf("Front-face visible: triangle is facing the viewer.\n");
    }

    return 0;
}
