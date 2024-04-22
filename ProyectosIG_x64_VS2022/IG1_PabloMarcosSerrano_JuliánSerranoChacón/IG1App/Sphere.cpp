#include "Sphere.h"

Sphere::Sphere(GLdouble r, GLint slices, GLint stacks) { r_ = r; slices_ = slices; stacks_ = stacks; }

Sphere::~Sphere()
{
}

void Sphere::render(glm::dmat4 const& modelViewMat) const {
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aquí se puede fijar el color de la esfera así:
	glColor3f(mColor.x, mColor.y, mColor.z);
	gluQuadricDrawStyle(q, GLU_FILL);
	gluSphere(q, r_, slices_, stacks_);
	// Aquí se debe recuperar el color :
	glColor3f(1.0, 1.0, 1.0);
}