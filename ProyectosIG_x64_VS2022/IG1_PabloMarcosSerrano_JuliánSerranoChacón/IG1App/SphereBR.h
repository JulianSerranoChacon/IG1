#pragma once
#include "EntityWithMaterial.h"

class SphereBR: public EntityWithMaterial
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

