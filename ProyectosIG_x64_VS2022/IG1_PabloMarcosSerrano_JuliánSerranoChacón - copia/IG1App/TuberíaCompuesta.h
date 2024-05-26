#pragma once
#include "CompoundEntity.h"

class SphereBR;
class SemiToroid;

class Tuber�aCompuesta: public CompoundEntity
{
public:
	Tuber�aCompuesta();
	virtual ~Tuber�aCompuesta() {};
	virtual void update() override;

protected:
	CompoundEntity* inventedNode;
	SphereBR* sphereBR;
	SemiToroid* semiToroid;
	GLdouble cont = 0;
	GLdouble mod = 4;
};

