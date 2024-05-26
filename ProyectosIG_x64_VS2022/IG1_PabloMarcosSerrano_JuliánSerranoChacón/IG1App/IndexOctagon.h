#pragma once
#include "Entity.h"
class IndexOctagon : public Abs_Entity
{
public:
	IndexOctagon(GLuint l);
	virtual ~IndexOctagon();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

