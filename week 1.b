#include <stdio.h>

int main() {
    int x, y;

    // Input the coordinates
    printf("Enter the coordinates (x y): ");
    scanf("%d %d", &x, &y);

    // Determine the quadrant
    if (x > 0 && y > 0) {
        printf("The coordinate point (%d,%d) lies in the First quadrant.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("The coordinate point (%d,%d) lies in the Second quadrant.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("The coordinate point (%d,%d) lies in the Third quadrant.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("The coordinate point (%d,%d) lies in the Fourth quadrant.\n", x, y);
    } else if (x == 0 && y != 0) {
        printf("The coordinate point (%d,%d) lies on the Y-axis.\n", x, y);
    } else if (y == 0 && x != 0) {
        printf("The coordinate point (%d,%d) lies on the X-axis.\n", x, y);
    } else {
        printf("The coordinate point (%d,%d) is at the origin.\n", x, y);
    }

    return 0;
}
