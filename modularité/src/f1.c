// Explicit definition, this actually allocates
// as well as describing
#include <stdio.h>
#include "f1.h"
//int Global_Variable;
// Function prototype (declaration), assumes
// defined elsewhere, normally from include file.
void SomeFunction(void); // A supprimer en v4

int main(void) {
	printf("main : Global_Variable is %d\n", Global_Variable);
	Global_Variable = 1;
	printf("main : Global_Variable is %d\n", Global_Variable);
	SomeFunction();
	printf("main : Global_Variable is %d\n", Global_Variable);

	return 0;
}
