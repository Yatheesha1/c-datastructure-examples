#include <stdio.h>

void fun() {
    static int x = 5;
    x++;
    printf("%d ", x);
}

int main () {
    fun();
    fun();

    char a = 'A', b = 'B';
    printf("\n%d", a&b);

    return 0;
}