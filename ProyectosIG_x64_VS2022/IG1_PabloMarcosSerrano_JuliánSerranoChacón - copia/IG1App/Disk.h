#pragma once

#include "QuadricEntity.h"

class Disk: public QuadricEntity
{
public:
	Disk(GLdouble innerR, GLdouble outerR, GLint slices, GLint rings);
	virtual ~Disk();
	void render(glm::dmat4 const& modelViewMat) const;
private:
	GLdouble innerR_;
	GLdouble outerR_;
	GLint slices_;
	GLint rings_;
};

