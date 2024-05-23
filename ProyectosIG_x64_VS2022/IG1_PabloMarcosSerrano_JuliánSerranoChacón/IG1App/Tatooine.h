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
	void turnOffTieLantern();
	void turnOnTieLantern();
protected:
	CompoundEntity* inventedNode;
	AdvancedTIE* tie;
	Sphere* tatooine;
};

