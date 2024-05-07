#pragma once
#include "Entity.h"
class SphereBR: public Abs_Entity
{
public:
	SphereBR(GLuint r, GLuint p, GLuint m);
	virtual ~SphereBR();
	virtual void render(glm::dmat4 const& modelViewMat) const;

protected:
	GLuint r_;
	GLuint p_;
	GLuint m_;
};

