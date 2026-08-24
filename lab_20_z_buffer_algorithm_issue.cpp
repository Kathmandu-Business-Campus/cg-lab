#include <stdio.h>
#include <stdlib.h>

#define WIDTH 4
#define HEIGHT 4

// Show in figure as well

int main() {
    int image[WIDTH][HEIGHT];
    float zbuffer[WIDTH][HEIGHT];
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j] = 0;
            zbuffer[i][j] = -9999.0f;
        }
    }

    typedef struct {
        int x, y;
        float z;
        int color;
    } Pixel;

    Pixel polygons[3] = {
        {1, 1, 20.0f, 1},
        {2, 2, 15.0f, 2},
        {3, 3, 25.0f, 3}
    };

    printf("Z-Buffer Algorithm Demo\n");
    printf("Depth values are simulated for a small image buffer.\n\n");

    for (i = 0; i < 3; i++) {
        if (polygons[i].z > zbuffer[polygons[i].x][polygons[i].y]) {
            zbuffer[polygons[i].x][polygons[i].y] = polygons[i].z;
            image[polygons[i].x][polygons[i].y] = polygons[i].color;
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("(%d,%d): color=%d depth=%.1f | ", i, j, image[i][j], zbuffer[i][j]);
        }
        printf("\n");
    }

    printf("\nVisible pixel at (3,3) has the highest depth value: %d\n", image[3][3]);
    return 0;
}
