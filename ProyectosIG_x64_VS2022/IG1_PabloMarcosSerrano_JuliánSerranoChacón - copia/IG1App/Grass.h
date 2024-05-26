#pragma once
#include "Entity.h"
class Grass: public Abs_Entity
{
public:
	Grass();
	~Grass();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

