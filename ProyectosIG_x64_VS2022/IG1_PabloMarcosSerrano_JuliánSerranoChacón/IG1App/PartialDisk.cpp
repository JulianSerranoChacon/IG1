#include "PartialDisk.h"

PartialDisk::PartialDisk(GLdouble innerR, GLdouble outerR, GLint slices, GLint rings, GLdouble startA, GLdouble sweepA)
{
	innerR_ = innerR; outerR_ = outerR; slices_ = slices; rings_ = rings; startA_ = startA; sweepA_ = sweepA;
}

PartialDisk::~PartialDisk()
{
}

void PartialDisk::render(glm::dmat4 const& modelViewMat) const
{
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aquí se puede fijar el color de la esfera así:
	// glEnable ( GL_COLOR_MATERIAL );
	// glColor3f (...);
	// Aquí se puede fijar el modo de dibujar la esfera :
	// gluQuadricDrawStyle (q, ...);
	gluPartialDisk(q, innerR_, outerR_, slices_, rings_,startA_,sweepA_);
	// Aquí se debe recuperar el color :
	// glColor3f (1.0 , 1.0 , 1.0);
}
