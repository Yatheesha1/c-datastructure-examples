#include <stdio.h>
int main()
{
    size_t n = 1; //unsigned int
    char *c = (char *)&n;
    if (*c)
    {
        printf("Big endian\n");
    }
    else
    {
        printf("Little endian\n");
    }
}