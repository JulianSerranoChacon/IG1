#pragma once
#include "entity.h"
class BoxOutline: public Abs_Entity
{
public:
	BoxOutline(GLdouble lenght);
	~BoxOutline();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

