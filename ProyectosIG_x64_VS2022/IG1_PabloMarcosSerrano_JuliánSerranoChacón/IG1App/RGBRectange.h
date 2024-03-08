#pragma once
#include "Entity.h"
class RGBRectange: public Abs_Entity
{
public:
	RGBRectange(GLdouble w, GLdouble h);
	virtual ~RGBRectange();
	virtual void render(glm::dmat4 const& modelViewMat) const;

};

