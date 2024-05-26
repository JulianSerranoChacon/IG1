#pragma once
#pragma once
#include "Entity.h"
class HalfPipe : public Abs_Entity
{
public:
	HalfPipe(GLuint r, GLuint R, GLuint m, GLuint p);
	~HalfPipe();
	virtual void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLuint r_, R_, m_, p_;
};
