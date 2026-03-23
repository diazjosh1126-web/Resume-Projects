/*
 * Student Record Management System
 * --------------------------------
 * Features:
 * - Add student
 * - View all students
 * - Save to file
 * - Load from file
 *
 * Concepts Demonstrated:
 * - Structures
 * - File I/O
 * - Arrays
 * - Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define student structure
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

int main() {
    Student students[MAX];
    int count = 0;
    int choice;

    // Load existing data from file
    loadFromFile(students, &count);

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                printf("Data saved. Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Add a new student
void addStudent(Student students[], int *count) {
    if (*count >= MAX) {
        printf("Database full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);

    (*count)++;
    printf("Student added successfully.\n");
}

// Display all students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nGPA: %.2f\n",
               students[i].id,
               students[i].name,
               students[i].gpa);
    }
}

// Save data to file
void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);

    fclose(file);
}

// Load data from file
void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");

    if (!file) return;

    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(Student), *count, file);

    fclose(file);
}
