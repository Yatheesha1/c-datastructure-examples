#include <stdio.h>

int main() 
{ 
    unsigned int i = 1; 
    char *c = (char*)&i; 
    if (*c) 
        printf("Little endian\n"); // most of the compiler having this format
    else
        printf("Big endian\n");

    printf("addr:%p, value:%d\n", &i, *c);
    printf("next addr:%p, value:%d\n", &i+1, *(c+1)); 
    return 0; 
} 