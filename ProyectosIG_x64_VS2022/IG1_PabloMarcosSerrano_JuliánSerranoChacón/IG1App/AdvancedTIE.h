#pragma once
#include "CompoundEntity.h"
class Texture;
class AdvancedTIE: public CompoundEntity
{
public:
	AdvancedTIE();
	virtual ~AdvancedTIE();
	void setWingsTexture(Texture* t);
};

