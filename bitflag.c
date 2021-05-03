#include <stdio.h>

typedef struct _EG1 {
    int a:4;
    int b:3;
    int c:2;
    int d:1;
} EG1;

typedef struct _EG2 {
    unsigned int a:4;
    unsigned int b:3;
    unsigned int c:2;
    unsigned int d:1;
} EG2;

EG1 eg1 = {7, 3, 1, 1};
EG2 eg2 = {8, 4, 2, 0};
int main() {
    printf("Size: %lu\n", sizeof(EG1));
    printf("%d:%d:%d:%d\n", eg1.a, eg1.b, eg1.c, eg1.d);
    printf("%d:%d:%d:%d\n", eg2.a, eg2.b, eg2.c, eg2.d);
    return 0;
}