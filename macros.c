#include <stdio.h>

#define swap(a,b,c) (c t; t = a, a = b, b = t)


int main () {
    int a = 5, b =10;

    printf("%d %d\n", a, b);

    swap(a, b, int);

    printf("%d %d\n", a, b);

    return 0;
}