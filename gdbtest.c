#include <stdio.h>

int main () {
    int *a = NULL;
    if (*a++) {
        printf("NULL\n");
    }

    printf("\n");
    return 0;
}