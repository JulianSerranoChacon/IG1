#pragma once
#include "Entity.h"


class Cube: public Abs_Entity
{
public:
	Cube(GLdouble lenght);
	~Cube();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

