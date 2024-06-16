#include <stdio.h>

int main() {
    float temperature;

    // Input the temperature in centigrade
    printf("Enter the temperature in centigrade: ");
    scanf("%f", &temperature);

    // Determine the temperature state
    if (temperature < 0) {
        printf("Freezing weather.\n");
    } else if (temperature >= 0 && temperature <= 10) {
        printf("Very Cold weather.\n");
    } else if (temperature > 10 && temperature <= 20) {
        printf("Cold weather.\n");
    } else if (temperature > 20 && temperature <= 30) {
        printf("Normal in Temp.\n");
    } else if (temperature > 30 && temperature <= 40) {
        printf("It's Hot.\n");
    } else {
        printf("It's Very Hot.\n");
    }

    return 0;
}
