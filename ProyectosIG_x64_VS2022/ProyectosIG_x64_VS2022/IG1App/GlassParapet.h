#pragma once
#include "Entity.h"
class GlassParapet: public Abs_Entity
{
public:
	GlassParapet(GLdouble lenght);
	~GlassParapet();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

