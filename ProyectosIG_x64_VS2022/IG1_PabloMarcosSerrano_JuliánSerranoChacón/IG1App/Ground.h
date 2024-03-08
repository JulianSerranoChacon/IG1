#pragma once
#include "Entity.h"
class Ground: public Abs_Entity
{
public:
	Ground(GLdouble w, GLdouble h);
	~Ground();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};