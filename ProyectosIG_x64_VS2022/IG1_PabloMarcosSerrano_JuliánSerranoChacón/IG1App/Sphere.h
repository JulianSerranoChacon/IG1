#pragma once

#include "QuadricEntity.h"

class Sphere: public QuadricEntity
{
public:
	Sphere(GLdouble r, GLint slices, GLint stacks); // r es el radio de la esfera
	virtual ~Sphere();
	void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLdouble r_;
	GLint slices_;
	GLint stacks_;
};

