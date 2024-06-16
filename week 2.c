#include <stdio.h>
#include <stdlib.h> // for malloc and free

// Structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    int marks[3];
    int totalMarks;
    float averageMarks;
};

// Function to read details of 'n' students using dynamic memory allocation
void readStudentDetails(struct Student **students, int n) {
    *students = (struct Student *) malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", (*students)[i].name); // read until newline
        printf("Roll Number: ");
        scanf("%d", &(*students)[i].rollNumber);
        printf("Marks in three subjects: ");
        scanf("%d %d %d", &(*students)[i].marks[0], &(*students)[i].marks[1], &(*students)[i].marks[2]);
    }
}

// Function to calculate total and average marks for each student
void calculateTotalAndAverage(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].totalMarks = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        students[i].averageMarks = (float) students[i].totalMarks / 3;
    }
}

// Function to find and display details of student with highest total marks
void findStudentWithHighestTotal(struct Student *students, int n) {
    int highestTotal = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (students[i].totalMarks > highestTotal) {
            highestTotal = students[i].totalMarks;
            index = i;
        }
    }

    printf("Student with highest total marks:\n");
    printf("Name: %s\n", students[index].name);
    printf("Roll Number: %d\n", students[index].rollNumber);
    printf("Total Marks: %d\n", students[index].totalMarks);
    printf("Average Marks: %.2f\n", students[index].averageMarks);
}

int main() {
    struct Student *students;
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Read details of all students using dynamic memory allocation
    readStudentDetails(&students, n);

    // Calculate total and average marks for each student
    calculateTotalAndAverage(students, n);

    // Display details of each student
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Total Marks: %d\n", students[i].totalMarks);
        printf("Average Marks: %.2f\n", students[i].averageMarks);
        printf("\n");
    }

    // Find and display details of student with highest total marks
    findStudentWithHighestTotal(students, n);

    // Free dynamically allocated memory
    free(students);

    return 0;
}
