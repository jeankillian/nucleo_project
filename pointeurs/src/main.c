#include<stdio.h>

int main(void){
	int a = 1;
	int b = 2;
	int c = 3;
	int *p1 = NULL;
	int *p2 = NULL;

	p1 = &a;
	p2 = &c;
	*p1 = *p2;
	b = *p1 + *p2;
	*p2 = *p1 / *p2;
	a  +=  *p1;
	p1 = p2;
	*p2  +=  *p1 + a;
	(*p2)++;
	*p2 = *p1 - 2 * *p2;
	(*p2) --;
	a = (2 + *p2) * *p1;
	*p1 = a + *p2;
	p1 = NULL;

	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("c: %d\n", c);
	printf("&a: %p\n", &a);
	printf("&b: %p\n", &b);
	printf("&c: %p\n", &c);
	printf("p2: %p\n", p2);
//	printf("p1: %p\n", &p1);
//	printf("p2: %p\n", &p2);
	printf("*p2: %d\n", *p2);

	printf("p1: %p\n", p1);
	printf("*p1: %d\n", *p1);
	return 0;
}
