#include <stdio.h>

#define MAX 20

typedef struct {
    double x, y;
} Point;

int inside(Point p, int edge, double xmin, double ymin, double xmax, double ymax) {
    switch (edge) {
        case 0: return p.x >= xmin;   // left edge
        case 1: return p.y <= ymax;   // top edge
        case 2: return p.x <= xmax;   // right edge
        case 3: return p.y >= ymin;   // bottom edge
        default: return 0;
    }
}

Point intersection(Point p1, Point p2, int edge, double xmin, double ymin, double xmax, double ymax) {
    Point p;
    double m;

    if (p2.x == p1.x)
        m = 0.0;
    else
        m = (p2.y - p1.y) / (p2.x - p1.x);

    switch (edge) {
        case 0:
            p.x = xmin;
            p.y = p1.y + m * (p.x - p1.x);
            break;
        case 1:
            p.y = ymax;
            p.x = p1.x + (p.y - p1.y) / m;
            break;
        case 2:
            p.x = xmax;
            p.y = p1.y + m * (p.x - p1.x);
            break;
        case 3:
            p.y = ymin;
            p.x = p1.x + (p.y - p1.y) / m;
            break;
        default:
            p.x = p1.x;
            p.y = p1.y;
            break;
    }
    return p;
}

void clip_against_edge(Point input[], int n, Point output[], int *out_n, int edge,
                       double xmin, double ymin, double xmax, double ymax) {
    int i, count = 0;

    for (i = 0; i < n; i++) {
        Point p1 = input[i];
        Point p2 = input[(i + 1) % n];
        int in1 = inside(p1, edge, xmin, ymin, xmax, ymax);
        int in2 = inside(p2, edge, xmin, ymin, xmax, ymax);

        if (in1 && in2) {
            output[count++] = p2;
        } else if (in1 && !in2) {
            output[count++] = intersection(p1, p2, edge, xmin, ymin, xmax, ymax);
        } else if (!in1 && in2) {
            output[count++] = intersection(p1, p2, edge, xmin, ymin, xmax, ymax);
            output[count++] = p2;
        }
    }

    *out_n = count;
}

int main() {
    Point input[5] = {{20, 20}, {80, 30}, {100, 100}, {40, 120}, {20, 80}};
    Point output[MAX];
    int n = 5, out_n = 0;
    int edge;

    printf("Sutherland-Hodgman Polygon Clipping Demo\n");
    printf("Original polygon:\n");
    for (edge = 0; edge < n; edge++) {
        printf("(%.1f, %.1f)\n", input[edge].x, input[edge].y);
    }

    for (edge = 0; edge < 4; edge++) {
        clip_against_edge(input, n, output, &out_n, edge, 30, 20, 90, 100);
        n = out_n;
        for (int i = 0; i < n; i++) {
            input[i] = output[i];
        }
    }

    printf("\nClipped polygon:\n");
    for (edge = 0; edge < n; edge++) {
        printf("(%.1f, %.1f)\n", input[edge].x, input[edge].y);
    }

    return 0;
}
