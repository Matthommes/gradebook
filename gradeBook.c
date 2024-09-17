// A basic C program that allows the user to store and calculate the grades of students dynamically.

#include <stdio.h>
#include <stdlib.h>

// Function to determine suffix

char *get_suffix(int number)
{
    if (number % 100 >= 11 && number % 100 <= 13)
    {
        return "th";
    }

    switch (number % 10)
    {
    case 1:
        return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    default:
        return "th";
    }
}

int main()
{

    int num_of_students;

    printf("Welcome to the Grade Book: A Grade Calculator!\n");
    printf("Please enter the numbers of students: \n");
    scanf("%d", &num_of_students);

    // Dynamically allocating memory for the student grades and names.

    float *grades = malloc(num_of_students * sizeof(float));
    char(*names)[50] = malloc(num_of_students * 50 * sizeof(char));

    // Confirm successful memory allocation.

    if (grades == NULL || names == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input student names and grades.

    for (int i = 0; i < num_of_students; i++)
    {

        const char *suffix = get_suffix(i + 1);
        printf("Enter the %d%s student's name: \n", i + 1, suffix);
        scanf("%s", names[i]);
        printf("Enter %s's grade: \n", names[i]);
        scanf("%f", &grades[i]);
    }

    // Calculate and display the grade information.

    float sum = 0, highest = grades[0], lowest = grades[0];
    int highest_grade_index = 0, lowest_grade_index = 0;

    // Sort grades by highest_grade_index

    for (int i = 0; i < num_of_students; i++)
    {
        sum += grades[i];
        if (grades[i] > highest)
        {
            highest = grades[i];
            highest_grade_index = i;
        }

        if (grades[i] < lowest)
        {
            lowest = grades[i];
            lowest_grade_index = i;
        }
    }

    float average = sum / num_of_students;

    // Display results
    printf("\nGrade Report:\n");
    printf("Average Grade: %.2f\n", average);
    printf("Highest Grade: %.2f (by %s)\n", highest, names[highest_grade_index]);
    printf("Lowest Grade: %.2f (by %s)\n", lowest, names[lowest_grade_index]);

    free(names);
    free(grades);
    return 0;
}