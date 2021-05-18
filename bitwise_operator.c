#include <stdio.h>

int main () {

    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int i = 0;
    int *addr = a;
    int j, k = 0;
    printf("%p:%d\n", a, a[i]);

    printf("%p:%d\n", addr++, a[i++]);

    printf("%p:%d\n", ++addr, a[++i]);

    i = 0;
    printf("%p, %p, %p:%d, %d, %d\n", ++addr, addr++, addr++, a[++i], a[i++], a[i++]); // left to right opration

    for (i = 0, j = 0; i < 10; ++i, j = i++, k = i++) { // left to right operation
        printf("i:%d, j:%d, k:%d\n", i, j, k);
    }

    printf("i:%d, j:%d, k:%d\n", i, j, k);

    i = 1;

    printf("%d\n", (((i++) + 1) * i + 1) ); // = (1+1) * 2 + 1 = 2*2+1 = 5 // left to right operation BODMAS

    return 0;
}