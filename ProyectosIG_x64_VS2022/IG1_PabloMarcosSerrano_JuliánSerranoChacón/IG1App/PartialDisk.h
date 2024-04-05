#pragma once
#include "QuadricEntity.h"

class PartialDisk: public QuadricEntity
{
public:
	PartialDisk(GLdouble innerR, GLdouble outerR, GLint slices, GLint rings, GLdouble startA, GLdouble sweepA);
	virtual ~PartialDisk(); 
	void render(glm::dmat4 const& modelViewMat) const;

private:
	GLdouble innerR_;
	GLdouble outerR_;
	GLint slices_;
	GLint rings_; 
	GLdouble startA_;
	GLdouble sweepA_;
};

