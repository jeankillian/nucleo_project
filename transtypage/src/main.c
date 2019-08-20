#include<stdio.h>

int main(void){
	int var = 0x11026535;
	char *pvar = &var;
//	char var_cast;

//	var_cast = pvar;
	printf("%d\n",var);
	printf("%c\n",*(pvar));
	printf("%c\n",*(pvar+1));
	printf("%c\n",*(pvar+2));
	printf("%c\n",*(pvar+3));

	return 0;
}
