#pragma once
#include "Entity.h"
class IndexedBox: public Abs_Entity
{
public:
	IndexedBox(GLuint l);
	virtual ~IndexedBox();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

