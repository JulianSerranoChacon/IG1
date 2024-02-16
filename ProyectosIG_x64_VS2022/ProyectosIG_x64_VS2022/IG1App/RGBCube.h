#pragma once
#include "Entity.h"

class RGBCube: public Abs_Entity
{
public:
	RGBCube(GLdouble lenght);
	~RGBCube();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

