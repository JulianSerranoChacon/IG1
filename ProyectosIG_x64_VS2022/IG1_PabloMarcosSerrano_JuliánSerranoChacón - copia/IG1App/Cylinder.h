#pragma once

#include "QuadricEntity.h"

class Cylinder: public QuadricEntity
{
public:
	Cylinder(GLdouble rUp, GLdouble rDown, GLdouble h, GLint slices, GLint stacks);
	virtual ~Cylinder();
	virtual void render(glm::dmat4 const& modelViewMat) const;
private:
	GLdouble rUp_;
	GLdouble rDown_;
	GLdouble h_;
	GLdouble slices_;
	GLdouble stacks_;
};

