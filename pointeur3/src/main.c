#include<stdio.h>

int main(void){

	int const constVar = 42;
	int variable = 11;

	const int * constPointer1 = constVar;
	int const * constPointer2 = variable;
	int* const constPointer3 = &variable;
	int* const constPointer4 = &constVar;
	int const * const constPointer5 = &constVar;
	const int* const constPointer6 = &variable;

	printf("%d\n", constPointer1);
	printf("%d\n", constPointer2);
	printf("%d	%p\n", *constPointer3, constPointer3);
	printf("%d	%p\n", *constPointer4, constPointer4);
	printf("%d	%p\n", *constPointer5, constPointer5);
	printf("%d	%p\n", *constPointer6, constPointer6);

//	char *pc, carac = 'A';
//	int c = 0;
//	int *pi, entier = 55;
//	int i = 0;
//	pc = &carac;
//	pi = &entier;
//	i = (int) *pc;
//	c = (char) *pi;
//	pi= (void *) pc;
//
//	printf("%d\n", i); // 65
//	printf("%d\n", c); // 55
//	printf("%c\n", *pi); // A
//	printf("%c\n", *pc); // A

	return 0;
}
