#include <stdio.h>
#include <math.h> // for M_PI and pow

// Define constants for shape types
#define CIRCLE 0
#define SQUARE 1
#define RECTANGLE 2

// Define union for shapes
union Shape {
    struct {
        double radius;
    } circle;
    struct {
        double sideLength;
    } square;
    struct {
        double length;
        double width;
    } rectangle;
};

// Function to calculate area of a circle
double calculateCircleArea(double radius) {
    return M_PI * pow(radius, 2);
}

// Function to calculate area of a square
double calculateSquareArea(double sideLength) {
    return pow(sideLength, 2);
}

// Function to calculate area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width;
}

// Function to calculate area based on shape type
double calculateArea(union Shape shape, int shapeType) {
    switch (shapeType) {
        case CIRCLE:
            return calculateCircleArea(shape.circle.radius);
        case SQUARE:
            return calculateSquareArea(shape.square.sideLength);
        case RECTANGLE:
            return calculateRectangleArea(shape.rectangle.length, shape.rectangle.width);
        default:
            return 0.0; // Invalid shape type
    }
}

// Function to print areas of all shapes
void printAreas(union Shape shapes[], double areas[], int numShapes) {
    printf("Areas of shapes:\n");
    for (int i = 0; i < numShapes; i++) {
        switch (i % 3) { // Map i to shape type (0 for circle, 1 for square, 2 for rectangle)
            case CIRCLE:
                printf("Area of circle %d: %.2f\n", i + 1, areas[i]);
                break;
            case SQUARE:
                printf("Area of square %d: %.2f\n", i + 1, areas[i]);
                break;
      
