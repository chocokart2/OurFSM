#pragma once
#include "characterState.h"

class character
{
	character* state;
public:
	character();
	void setState(characterState* state);
};
