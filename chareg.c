#include <stdio.h>
#include <string.h>

void copy(char ch[], int len) {
	printf("%s %p\n", ch, ch);
	//ch[0] = "Hello";
	//ch[0] = 'h';
	//printf("%c %p\n", ch[0][0], &ch[0][0]);
}

void main () {
	char *pch = "World";
	char ch[] = "Hai";
	int len = strlen(pch);
	//pch[0] = 'w';

	copy(pch, len);
	printf("%s %p\n", pch, pch);
}