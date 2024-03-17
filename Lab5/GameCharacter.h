#pragma once
#include <iostream>
#define TOOLS_COUNT 3

class GameCharacter {
	/// @brief The name of the Game Character.
	///
	/// What others call the Game Character.
	std::string name;
	/// @brief The tools the Game Character uses.
	///
	/// Has a maximum number of tools: TOOLS_COUNT.
	/// It's a pointer to a tools array that has been allocated in the heap.
	std::string* tools;

public:
	/// @brief Default Constructor. Initializes with all "" values.
	///
	/// Allocates tools to the heap.
	GameCharacter();
	/// @brief Parameterized Constructor. Initializes with parameters.
	/// 
	/// Allocates tools to the heap.
	/// Initializes assuming that input parameter tools is an array that is TOOLS_COUNT long.
	/// @param name The name of the Game Character.
	/// @param tools The tools the Game Character uses. Has a maximum number of tools: TOOLS_COUNT.
	/// @param arrLen The length of the input array. Must not be bigger than TOOLS_COUNT to be valid.
	GameCharacter(std::string name, std::string* tools, int arrLen);
	/// @brief Copy Constructor. Initializes with copy.
	/// 
	/// Allocates tools to the heap.
	/// Creates a deep copy of tools.
	/// @param rhs The Game Character that is being copied from.
	GameCharacter(GameCharacter& rhs);
	/// @brief Assignment Operator. Sets left hand side to right hand side.
	/// 
	/// Does a deep copy of tools.
	/// @param rhs The Game Character that is being copied from.
	/// @return The left hand side of the assignment operator. (=)
	GameCharacter& operator = (GameCharacter& rhs);
	/// @brief Deallocate memory.
	///
	/// Deallocates tools from the heap.
	~GameCharacter();

	/// @brief Sets the name of the Game Character.
	/// @param name New name of the character.
	/// @return The Game Character that is being changed.
	GameCharacter& setName(std::string name);
	/// @brief Gets the current name of the Game Character.
	/// @return The current name of the character.
	std::string getName();
	/// @brief Sets the tools of the Game Character.
	/// 
	/// Sets tools in the character up to arrLen. Any tools remaining to be set will be set with "".
	/// @param tools The tools of the character. A string array.
	/// @param arrLen The length of the input array. Must not be bigger than TOOLS_COUNT to be valid.
	/// @return The Game Character that is being changed.
	GameCharacter& setTools(std::string tools[TOOLS_COUNT], int arrLen);
	/// @brief Gets the tools of the Game Character.
	/// @return The pointer to the tools in the heap.
	std::string* getTools();

	/// @brief Prints the name and tools of the Game Character.
	/// @param cout_ A reference to cout.
	/// @param gc The game character being printed.
	/// @return Cout, with the prints added.
	friend std::ostream& operator << (std::ostream& cout_, GameCharacter& gc);
};