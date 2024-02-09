#pragma once
#include "Entity.h"

class RGBTriangle: public Abs_Entity
{
private:

public:
	RGBTriangle(int r);
	virtual ~RGBTriangle();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

