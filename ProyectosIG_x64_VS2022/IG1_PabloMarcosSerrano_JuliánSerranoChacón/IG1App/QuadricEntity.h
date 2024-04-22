#pragma once

#include "Entity.h"

class QuadricEntity: public Abs_Entity
{
public:
	QuadricEntity();
	virtual ~QuadricEntity();
	virtual void render(glm::dmat4 const& modelViewMat) const = 0;
	virtual void setColor(glm::dvec4 color) { setMColor(color); };
protected:
	GLUquadricObj* q;
};

