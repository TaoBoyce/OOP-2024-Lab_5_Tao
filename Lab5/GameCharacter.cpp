#include "GameCharacter.h"
#include <iostream>
using namespace std;

GameCharacter::GameCharacter()
{
	cout << "Default constructor called." << endl;
	this->tools = new string[TOOLS_COUNT];
	setName("");
	//initializes tools array as all ""
	string tools[TOOLS_COUNT];
	setTools(tools, TOOLS_COUNT);
}

GameCharacter::GameCharacter(string name, string* tools, int arrLen)
{
	cout << "Parameterized constructor called." << endl;
	this->tools = new string[TOOLS_COUNT];
	setName(name);
	setTools(tools, arrLen);
}

GameCharacter::GameCharacter(GameCharacter& rhs)
{
	cout << "Copy constructor called." << endl;
	this->tools = new string[TOOLS_COUNT];
	setName(rhs.getName());
	setTools(rhs.getTools(), TOOLS_COUNT);
}

GameCharacter& GameCharacter::operator=(GameCharacter& rhs)
{
	cout << "Assignment operator called." << endl;
	if (this == &rhs) {
		return *this;
	}
	setName(rhs.getName());
	setTools(rhs.getTools(), TOOLS_COUNT);
	return *this;
}

GameCharacter::~GameCharacter()
{
	cout << "Deconstructor called." << endl;
	//delete[] is for deleting dynamic array memory allocation
	delete[] this->tools;
}

GameCharacter& GameCharacter::setName(string name)
{
	this->name = name;
	return *this;
}

string GameCharacter::getName()
{
	return this->name;
}

GameCharacter& GameCharacter::setTools(string tools[TOOLS_COUNT], int arrLen)
{
	if (tools == NULL) { //don't do anything if it's a null pointer
		fprintf(stderr, "ERROR: Null ptr tools in setTools");
		return *this;
	}
	if (arrLen > TOOLS_COUNT) { //don't do anything if arrLen is bigger than allocated memory
		fprintf(stderr, "ERROR: tools array longer than allocated memory");
		return *this;
	}
	int i = 0;
	for (i = 0; i < arrLen; i++) {
		this->tools[i] = tools[i];
	};
	while(i < TOOLS_COUNT) {
		this->tools[i] = "";
		i++;
	}
	return *this;
}

string* GameCharacter::getTools()
{
	return this->tools;
}

std::ostream& operator<<(std::ostream& cout_, GameCharacter& gc)
{
	cout_ << "Name: " << gc.getName();
	cout_ << " | Tools: ";
	string* tools = gc.getTools();
	if (tools == NULL) {
		cout << "NULL";
	}
	else {
		for (int i = 0; i < TOOLS_COUNT; i++) {
			cout << tools[i] << " ";
		}
	}
	return cout_;
}