#pragma once
#include "Entity.h"

class WingAdvanceTIE: public Abs_Entity
{
public:
	WingAdvanceTIE(GLdouble w, GLdouble h);
	virtual ~WingAdvanceTIE();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

