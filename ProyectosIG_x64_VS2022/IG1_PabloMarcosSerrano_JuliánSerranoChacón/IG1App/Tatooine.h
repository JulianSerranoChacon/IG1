#pragma once
#include "CompoundEntity.h"

class AdvancedTIE;
class Sphere;

class Tatooine: public CompoundEntity
{
public:
	Tatooine();
	~Tatooine();
	void rotate();
	void orbit();
	void setWingsTexture(Texture* t);
protected:
	CompoundEntity* inventedNode;
	AdvancedTIE* tie;
	Sphere* tatooine;
};

