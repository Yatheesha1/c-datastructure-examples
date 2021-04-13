#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n, position, status;
    printf("Enter a number:");
    scanf("%d", &n);
    printf("Enter position to toggle:");
    scanf("%d", &position);
    status = (n >> position) & 1;
    printf("Before toggle: %d and Number: %d\n", status, n);
    status = !status;
    n ^= 1 << position; //toggle
    // n |= 1 << position;    //set
    // n &= ~(1 << position); //clear
    printf("After toggle:%d and Number: %d\n", status, n);
    return 0;
}