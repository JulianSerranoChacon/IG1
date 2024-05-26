#pragma once
#include "Entity.h"
class SemiToroid: public Abs_Entity
{
public:
	SemiToroid(GLuint r, GLuint R, GLuint m, GLuint p);
	~SemiToroid();
	virtual void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLuint r_, R_, m_, p_;

};

