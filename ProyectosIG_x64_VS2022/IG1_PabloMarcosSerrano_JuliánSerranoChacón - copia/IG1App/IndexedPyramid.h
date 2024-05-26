#pragma once
#include "Entity.h"

class IndexedPyramid: public Abs_Entity
{
public:
	IndexedPyramid(GLdouble l);
	~IndexedPyramid();
	virtual void render(glm::dmat4 const& modelViewMat) const;
private:
	GLdouble l;
};

