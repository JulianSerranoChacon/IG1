#pragma once
#include "Entity.h"

class IndexedOctogone: public Abs_Entity
{
public:
	IndexedOctogone(GLdouble l, GLdouble h);
	~IndexedOctogone();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

