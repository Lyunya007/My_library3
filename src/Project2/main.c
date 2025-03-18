#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate age based on birth date
int calculateAge(int birthYear, int birthMonth, int birthDay) {
    time_t t = time(NULL);  // Get the current time
    struct tm currentTime = *localtime(&t);  // Convert current time to tm structure

    int age = currentTime.tm_year + 1900 - birthYear;  // Calculate the current year minus birth year
    // If the user hasn't had their birthday yet this year, subtract one from the age
    if (currentTime.tm_mon + 1 < birthMonth || (currentTime.tm_mon + 1 == birthMonth && currentTime.tm_mday < birthDay)) {
        age--;
    }
    return age;
}

int main() {
    char firstName[50], lastName[50];  // Arrays to store the user's first and last name
    int birthYear, birthMonth, birthDay;  // Variables to store the birth date

    // Prompt user for input
    printf("Please enter your first name: ");
    scanf_s("%49s", firstName, sizeof(firstName));  // Using scanf_s with buffer size

    printf("Please enter your last name: ");
    scanf_s("%49s", lastName, sizeof(lastName));  // Using scanf_s with buffer size

    printf("Please enter your birth year: ");
    scanf_s("%d", &birthYear);  // Using scanf_s

    printf("Please enter your birth month: ");
    scanf_s("%d", &birthMonth);  // Using scanf_s

    printf("Please enter your birth day: ");
    scanf_s("%d", &birthDay);  // Using scanf_s

    // Calculate the user's age
    int age = calculateAge(birthYear, birthMonth, birthDay);

    // Display the greeting and age
    printf("Hello, %s %s! You are %d years old.\n", firstName, lastName, age);

    return 0;
}