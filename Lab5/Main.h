#pragma once
#include "GameCharacter.h"

GameCharacter foo1(GameCharacter p);
GameCharacter& foo2(GameCharacter& p);
GameCharacter foo3(GameCharacter& p);
GameCharacter& foo4(GameCharacter p);
GameCharacter& foo5(const GameCharacter& p);