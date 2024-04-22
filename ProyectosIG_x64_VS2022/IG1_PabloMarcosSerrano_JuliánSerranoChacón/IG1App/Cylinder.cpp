#include "Cylinder.h"

Cylinder::Cylinder(GLdouble rUp, GLdouble rDown, GLdouble h, GLint slices, GLint stacks)
{
	rUp_ = rUp; rDown_ = rDown; h_ = h; slices_ = slices; stacks_ = stacks;
}

Cylinder::~Cylinder()
{
}

void Cylinder::render(glm::dmat4 const& modelViewMat) const
{
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aquí se puede fijar el color de la esfera así:
	glColor3f (getMColor().x, getMColor().y, getMColor().z);
	// Aquí se puede fijar el modo de dibujar la esfera :
	// gluQuadricDrawStyle (q, ...);
	gluCylinder(q,rDown_,rUp_,h_,slices_,stacks_);
	// Aquí se debe recuperar el color :
	glColor3f (1.0 , 1.0 , 1.0);
}
