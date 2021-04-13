#include <stdio.h>
//#define decode(s,t,u,m,p,e,d) m##s##u##t
//#define begin decode(a,n,i,m,a,t,e)

void begin() {
	printf("%s: Hello World\n", __FUNCTION__);
}

void sid() {
	printf("%s: Hello World\n", __FUNCTION__);
}

#define fun m##a##i##n
int fun()
{
	printf("%s: Hello World\n", __FUNCTION__);
	return 0;
}