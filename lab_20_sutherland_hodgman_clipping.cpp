#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define MAX 20

typedef struct {
    int x, y;
} Point;

int inside(Point p, int edge, int xmin, int xmax, int ymin, int ymax) {
    switch (edge) {
        case 0: return p.y >= ymin; break;  // bottom edge
        case 1: return p.x <= xmax; break;  // right edge
        case 2: return p.y <= ymax; break;  // top edge
        case 3: return p.x >= xmin; break;  // left edge
        default: return 0;
    }
}

Point intersect(Point p1, Point p2, int edge, int xmin, int xmax, int ymin, int ymax) {
    double t;
    Point r;

    if (edge == 0) {
        t = (double)(ymin - p1.y) / (p2.y - p1.y);
    } else if (edge == 1) {
        t = (double)(xmax - p1.x) / (p2.x - p1.x);
    } else if (edge == 2) {
        t = (double)(ymax - p1.y) / (p2.y - p1.y);
    } else {
        t = (double)(xmin - p1.x) / (p2.x - p1.x);
    }

    r.x = (int)(p1.x + t * (p2.x - p1.x));
    r.y = (int)(p1.y + t * (p2.y - p1.y));
    return r;
}

void draw_polygon(Point p[], int n, int color) {
    int i;
    setcolor(color);
    for (i = 0; i < n; i++) {
        line(p[i].x, p[i].y, p[(i + 1) % n].x, p[(i + 1) % n].y);
    }
}

void print_points(Point p[], int n, const char *label) {
    int i;
    printf("%s: ", label);
    for (i = 0; i < n; i++) {
        printf("(%d,%d) ", p[i].x, p[i].y);
    }
    printf("\n");
}

int main() {
    int gd = DETECT, gm;
    int n = 5, i, edge;
    int xmin = 50, xmax = 250, ymin = 50, ymax = 250;
    Point polygon[5] = {{20, 50}, {120, 20}, {220, 80}, {180, 220}, {60, 180}};
    Point input[MAX], output[MAX];
    Point poly[MAX];

    for (i = 0; i < n; i++) {
        poly[i] = polygon[i];
    }

    printf("Sutherland-Hodgman Polygon Clipping Demo\n");
    printf("Clipping window: x = [%d,%d], y = [%d,%d]\n\n", xmin, xmax, ymin, ymax);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(BLACK);
    cleardevice();

    rectangle(xmin, ymin, xmax, ymax);
    outtextxy(20, 20, "Clipping Window");

    draw_polygon(poly, n, WHITE);
    outtextxy(20, 35, "Original Polygon");
    getch();
    cleardevice();

    rectangle(xmin, ymin, xmax, ymax);
    for (i = 0; i < n; i++) {
        input[i] = poly[i];
    }

    for (edge = 0; edge < 4; edge++) {
        int count = 0;
        print_points(input, n, "Before edge");
        for (i = 0; i < n; i++) {
            int j = (i + 1) % n;
            Point p1 = input[i];
            Point p2 = input[j];
            int in1 = inside(p1, edge, xmin, xmax, ymin, ymax);
            int in2 = inside(p2, edge, xmin, xmax, ymin, ymax);

            if (in1 && in2) {
                output[count++] = p2;
            } else if (in1 && !in2) {
                output[count++] = intersect(p1, p2, edge, xmin, xmax, ymin, ymax);
            } else if (!in1 && in2) {
                output[count++] = intersect(p1, p2, edge, xmin, xmax, ymin, ymax);
                output[count++] = p2;
            }
        }

        for (i = 0; i < count; i++) {
            input[i] = output[i];
        }
        n = count;
        printf("After edge %d: %d points\n", edge + 1, n);
        print_points(input, n, "Current");
    }

    setcolor(GREEN);
    draw_polygon(input, n, GREEN);
    outtextxy(20, 20, "Clipped Polygon");

    getch();
    closegraph();
    return 0;
}
