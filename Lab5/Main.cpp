#include "Main.h"
#include <iostream>

/*
6.
	foo1 
		- 2 copies 
		- receives by value and returns by value.
	foo2 
		- 0 copies 
	    - receives by reference and returns by reference.
	foo3
		- 1 copy 
	    - receives by reference and returns by value.
	foo4
		- 1 copy
		- receives by value and returns by reference.
		- this one may actually be dangerous to use, since the variable that was created goes out of scope?
		- since it goes out of scope, it gets destroyed and calls the deconstructor...
	foo5
		- 0 copies
		- recieves by reference and returns by reference.
		- may be dangerous to use for the same reason as foo4
	Total of 4 copies from the foo functions

7.
	The copy constructor is called when a variable is passed by value, and not when passed by reference.
	The copy constructor is called when a variable is set to another during initialization.
	The assignment operator is called when a variable is set to another after initialization.
*/
int main() {
	//Testing parameterized constructor
	//std::string tools[] = { "pickaxe", "shovel", "bow"};
	//GameCharacter gc("Miner", tools, TOOLS_COUNT);
	//std::cout << gc << std::endl;

	GameCharacter p1;
	GameCharacter p2 = p1;
	p1 = p2;

	foo1(p1);
	foo2(p1);
	foo3(p1);
	foo4(p1);
	foo5(p1);

	return 0;
}


//2 copies
GameCharacter foo1(GameCharacter p)
{
	return p;
}
//0 copies
GameCharacter& foo2(GameCharacter& p)
{
	return p;
}
//1 copy
GameCharacter foo3(GameCharacter& p)
{
	return p;
}
//1 copy
GameCharacter& foo4(GameCharacter p)
{
	return p;
}
//0 copies
GameCharacter& foo5(const GameCharacter& p)
{
	GameCharacter gc;
	return gc;
}
