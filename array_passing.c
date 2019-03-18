#include <stdio.h>
#include <stdlib.h>
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
    printf("Before size of array: %d\n", (int)(sizeof(arr) / sizeof(int)));
    display((int *)arr, row, column);
    modify((int *)arr, row, column);
    printf("After\n");
    display((int *)arr, row, column);

    printf("Before\n");
    display((int *)arr2, 1, column);
    modify((int *)arr2, 1, column);
    printf("After\n");
    display((int *)arr2, 1, column);
    return 0;
}