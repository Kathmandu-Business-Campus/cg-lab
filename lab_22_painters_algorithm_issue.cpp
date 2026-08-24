#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float avg_depth;
} Polygon;

int compare(const void *a, const void *b) {
    Polygon *p1 = (Polygon *)a;
    Polygon *p2 = (Polygon *)b;
    if (p1->avg_depth < p2->avg_depth)
        return 1;
    if (p1->avg_depth > p2->avg_depth)
        return -1;
    return 0;
}

int main() {
    Polygon poly[4] = {
        {1, 10.0f},
        {2, 5.0f},
        {3, 20.0f},
        {4, 8.0f}
    };
    int i;

    printf("Painter's Algorithm Demo\n\n");
    printf("Depth values (farther polygons are drawn first):\n");
    for (i = 0; i < 4; i++) {
        printf("Polygon %d avg_depth = %.1f\n", poly[i].id, poly[i].avg_depth);
    }

    printf("\nFigure view:\n");
    printf("Far object  ->  Polygon 3 (20)\n");
    printf("Then         ->  Polygon 1 (10)\n");
    printf("Then         ->  Polygon 4 (8)\n");
    printf("Near object  ->  Polygon 2 (5)\n\n");

    qsort(poly, 4, sizeof(Polygon), compare);

    printf("After sorting (far to near):\n");
    for (i = 0; i < 4; i++) {
        printf("Polygon %d avg_depth = %.1f\n", poly[i].id, poly[i].avg_depth);
    }

    printf("\nDraw order: Polygon 3 -> Polygon 1 -> Polygon 4 -> Polygon 2\n");
    return 0;
}
