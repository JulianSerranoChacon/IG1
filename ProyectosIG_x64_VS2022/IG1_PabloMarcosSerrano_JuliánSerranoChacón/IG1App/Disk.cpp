#include "Disk.h"

Disk::Disk(GLdouble innerR, GLdouble outerR, GLint slices, GLint rings)
{
	innerR_ = innerR; outerR_ = outerR; slices_ = slices; rings_ = rings;
}

Disk::~Disk()
{
}

void Disk::render(glm::dmat4 const& modelViewMat) const
{
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aquí se puede fijar el color de la esfera así:
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f (0.0,0.0,1.0);
	gluQuadricDrawStyle(q, GLU_FILL);
	// Aquí se puede fijar el modo de dibujar la esfera
	gluDisk(q, innerR_, outerR_, slices_, rings_);
	// Aquí se debe recuperar el color :
	glColor3f (1.0 , 1.0 , 1.0);
	glDisable(GL_COLOR_MATERIAL);
}
