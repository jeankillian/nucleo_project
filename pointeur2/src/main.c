#include<stdio.h>
#include<string.h>

int main(void){
//
//	const int MAX=7;
//	int tab[MAX], tab2[MAX];
//	int *p;
//
//	p=tab; *p=200;
//	p++; *p=3;
//	p=&tab[2]; *p=-30;
//	p=tab+3; *p=-2;
//	p=tab; *(p+4)=987654;
//	p[5]=-123;
//	*(tab+6)=987654;
//
//	p = tab2;
//
//	printf("%d\n", tab[0]);
//	printf("%d\n", tab[1]);
//	printf("%d\n", tab[2]);
//	printf("%d\n", tab[3]);
//	printf("%d\n", tab[4]);
//	printf("%d\n", tab[5]);
//	printf("%d\n", tab[6]);
//	printf("%d\n", tab[0]);
//	printf("\n");
//	printf("%d\n", tab2[0]);
//	printf("%d\n", tab2[1]);
//	printf("%d\n", tab2[2]);
//	printf("%d\n", tab2[3]);
//	printf("%d\n", tab2[4]);
//	printf("%d\n", tab2[5]);
//	printf("%d\n", tab2[6]);

//--------------------------------
	int len = 256;
	char C;
	char CH[len];
	char *p;

	printf("lettre: \n");
	scanf("%c", &C);
	printf("chaîne: \n");
	scanf("%s", CH);

	p = CH;
	while(*p != '\0')
	{
		if(*p == C)
		{
			strcpy(p, p+1);
		}
		else
			p++;
	}
	printf("%s\n", CH);

	return 0;
}
