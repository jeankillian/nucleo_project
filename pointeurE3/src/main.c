#include<stdio.h>

int main(void){

	const int MAX=7;
	int tab[MAX], tab2[MAX];
	int * p;

	p=tab; *p=200;
	p++; *p=3;
	p=&tab[2]; *p=-30;
	p=tab+3; *p=-2;
	p=tab; *(p+4)=987654;
	p[5]=-123;
	*(tab+6)=987654;

	*tab2 = *p;
	for (int i = 0; i<7; i++)
	{
		printf("tab : %d\n", tab[i]);
	}
	printf("\n");
	for (int i = 0; i<7; i++)
	{
		printf("tab2 : %d\n", tab2[i]);
	}

	return 0;
}
