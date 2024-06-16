#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a destination
struct Destination {
    char name[50];
    char date[20];
};

typedef struct Destination Destination;

// Function to add a destination to the travel planner
void addDestination(Destination destinations[], int* numDestinations) {
    printf("Enter destination name: ");
    scanf("%s", destinations[*numDestinations].name);
    printf("Enter travel date: ");
    scanf("%s", destinations[*numDestinations].date);
    (*numDestinations)++;
}

// Function to display all destinations in the travel planner
void displayDestinations(Destination destinations[], int numDestinations) {
    printf("\nDestinations in Travel Planner:\n");
    for (int i = 0; i < numDestinations; i++) {
        printf("Destination: %s, Date: %s\n", destinations[i].name, destinations[i].date);
    }
}

int main() {
    Destination destinations[100]; // Assuming a maximum of 100 destinations
    int numDestinations = 0;
    int choice;

    do {
        printf("\nTravel Planner Menu:\n");
        printf("1. Add Destination\n");
        printf("2. Display Destinations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDestination(destinations, &numDestinations);
                break;
            case 2:
                displayDestinations(destinations, numDestinations);
                break;
            case 3:
                printf("Exiting Travel Planner. Have a nice trip!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
