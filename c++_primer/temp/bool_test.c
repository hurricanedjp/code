#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
	bool a,b,c,d,e;
	a = true;
	b = false;
	c = 0;
	d=1;
	e=5;
	printf("bool=%d\n",sizeof(a));
	printf("a=%d;b=%d;c=%d;d=%d;e=%d\n",a,b,c,d,e);
	return 0;
}

