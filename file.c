#include <stdio.h>

int main () {

    FILE *fp = stdout;

    fprintf(fp, "%d ", 45);
    fflush(stdout);
    fprintf(stderr, "%d", 65);

    return 0;
}