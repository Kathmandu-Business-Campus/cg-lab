#include <stdio.h>
#include <math.h>

void print_rgb_to_cmy(float r, float g, float b) {
    float c, m, y;
    c = 1.0f - r / 255.0f;
    m = 1.0f - g / 255.0f;
    y = 1.0f - b / 255.0f;
    printf("RGB to CMY -> C=%.3f, M=%.3f, Y=%.3f\n", c, m, y);
}

void print_rgb_to_yiq(float r, float g, float b) {
    float y, i, q;
    y = 0.299f * r + 0.587f * g + 0.114f * b;
    i = 0.596f * r - 0.275f * g - 0.321f * b;
    q = 0.212f * r - 0.528f * g + 0.311f * b;
    printf("RGB to YIQ -> Y=%.3f, I=%.3f, Q=%.3f\n", y, i, q);
}

int main() {
    float r, g, b;

    printf("Color Model Demo\n");
    printf("Enter RGB values (0 to 255): ");
    scanf("%f %f %f", &r, &g, &b);

    print_rgb_to_cmy(r, g, b);
    print_rgb_to_yiq(r, g, b);

    return 0;
}
