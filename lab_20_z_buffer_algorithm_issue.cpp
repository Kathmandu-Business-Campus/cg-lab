#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

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

    Pixel polygons[5] = {
        {1, 1, 20.0f, 1},
        {2, 3, 15.0f, 2},
        {3, 2, 25.0f, 3},
        {4, 1, 18.0f, 4},
        {2, 2, 30.0f, 5}
    };

    printf("Z-Buffer Algorithm Demo\n");
    printf("Each pixel stores the closest visible depth value.\n\n");

    for (i = 0; i < 5; i++) {
        if (polygons[i].x >= 0 && polygons[i].x < WIDTH && polygons[i].y >= 0 && polygons[i].y < HEIGHT) {
            if (polygons[i].z > zbuffer[polygons[i].x][polygons[i].y]) {
                zbuffer[polygons[i].x][polygons[i].y] = polygons[i].z;
                image[polygons[i].x][polygons[i].y] = polygons[i].color;
            }
        }
    }

    printf("Depth buffer (closest visible value)\n");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%5.1f ", zbuffer[i][j]);
        }
        printf("\n");
    }

    printf("\nColor map\n");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image[i][j] == 0) {
                printf(" .  ");
            } else {
                printf(" %d  ", image[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nFigure view:\n");
    printf("  0 1 2 3 4\n");
    for (i = 0; i < WIDTH; i++) {
        printf("%d ", i);
        for (j = 0; j < HEIGHT; j++) {
            if (image[i][j] == 0) printf(" . ");
            else printf(" %d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nVisible strongest pixel is at (2,2) with color 5 and depth 30.0\n");
    return 0;
}
