#pragma once
#include "Entity.h"
class Photo: public Abs_Entity
{
public:
	Photo(GLdouble w, GLdouble h);
	~Photo();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

