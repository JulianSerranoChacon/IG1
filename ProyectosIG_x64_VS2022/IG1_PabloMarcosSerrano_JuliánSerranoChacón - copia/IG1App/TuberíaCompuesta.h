#pragma once
#include "CompoundEntity.h"

class SphereBR;
class SemiToroid;

class TuberíaCompuesta: public CompoundEntity
{
public:
	TuberíaCompuesta();
	virtual ~TuberíaCompuesta() {};
	virtual void update() override;

protected:
	CompoundEntity* inventedNode;
	SphereBR* sphereBR;
	SemiToroid* semiToroid;
	GLdouble cont = 0;
	GLdouble mod = 4;
};

