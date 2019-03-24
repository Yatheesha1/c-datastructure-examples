#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define row 3
#define column 4
void display(int *arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = *((arr + i * n) + j);
            printf("%d\t", val);
        }
        printf("\n");
    }
}

void displaychar(char *ch)
{
    printf("%s\t", ch);
}

void modifycharpointer(char **ch)
{
    *ch = "Hello";
}

void modifychar(char *ch)
{
    strcpy(ch, "Hello");
    // *ch = "Hello\n";
}

void modify(int *arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // *((arr + i * n) + j) = 0;
            *(arr++) = 0;
        }
    }
}

int main()
{
    int arr[row][column] = {{0, 1, 2, 3},
                            {3, 4, 5, 6},
                            {6, 7, 8, 9}};
    int arr2[column] = {0, 1, 2, 3};
    char *c, ch[] = "Good";
    c = "Hai";
    printf("Before size of array: %d\n", (int)(sizeof(arr) / sizeof(int)));
    display((int *)arr, row, column);
    modify((int *)arr, row, column);
    printf("After\n");
    display((int *)arr, row, column);

    printf("Before size of array: %d\n", (int)(sizeof(arr2) / sizeof(int)));
    display((int *)arr2, 1, column);
    modify((int *)arr2, 1, column);
    printf("After\n");
    display((int *)arr2, 1, column);

    printf("Before size of array: %d\n", (int)(sizeof(c) / sizeof(char)));
    displaychar(c);
    modifycharpointer(&c);
    printf("\nAfter\n");
    displaychar(c);
    printf("\n");

    printf("Before size of array: %d\n", (int)(sizeof(ch) / sizeof(char)));
    displaychar(ch);
    modifychar(ch);
    printf("\nAfter\n");
    displaychar(ch);
    printf("\n");
    return 0;
}