// Implicit declaration, this only describes and
// assumes allocated elsewhere, normally from include
extern int Global_Variable; // v2 : Cette ligne doit disparaître en v3 :-)
// Function header (definition)

void SomeFunction(void) {
	++Global_Variable;
}
