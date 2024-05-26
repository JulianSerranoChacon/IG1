#pragma once
#include "CompoundEntity.h"

class SphereBR;
class HalfPipe;
class Material;

class TieThroughPipe : public CompoundEntity
{
public:
	TieThroughPipe();
	~TieThroughPipe();
	virtual void update() override;
private:
	HalfPipe* tunnel;
	SphereBR* orb;
	Material* material;
	CompoundEntity* inventedNode;

	GLdouble cont;
	GLdouble mod;
};

