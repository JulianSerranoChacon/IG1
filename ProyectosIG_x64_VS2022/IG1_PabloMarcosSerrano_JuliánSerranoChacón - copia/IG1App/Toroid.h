#pragma once
#include "Entity.h"
class Toroid: public Abs_Entity
{
public:
	Toroid(GLuint r, GLuint R, GLuint m, GLuint p);
	~Toroid();
	virtual void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLuint r_, R_, m_, p_;
};

