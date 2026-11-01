
#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
    float marks;
};

struct Student s[100];
int count = 0;

// Function to add student
void addStudent() {
    if (count >= 100) {
        printf("\nRecord limit reached!");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter Age: ");
    scanf("%d", &s[count].age);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;

    printf("\nStudent Record Added Successfully!\n");
}

// Function to display students
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--- STUDENT RECORDS ---\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nAge: %d", s[i].age);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

// Function to search student
void searchStudent() {
    int roll, i;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("\nStudent Found!");
            printf("\nName: %s", s[i].name);
            printf("\nAge: %d", s[i].age);
            printf("\nMarks: %.2f\n", s[i].marks);
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Function to update student
void updateStudent() {
    int roll, i;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", s[i].name);

            printf("Enter New Age: ");
            scanf("%d", &s[i].age);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Function to delete student
void deleteStudent() {
    int roll, i, j;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            for (j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }

            count--;
            printf("\nRecord Deleted Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT RECORD MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank You! Exiting System.\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}
