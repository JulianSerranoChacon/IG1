#include "PosLight.h"

void PosLight::upload(glm::dmat4 const& modelViewMat) const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));
	glLightfv(id, GL_POSITION, value_ptr(posDir));
	glLightf(id, GL_CONSTANT_ATTENUATION, kc_);
	glLightf(id, GL_LINEAR_ATTENUATION, kl_);
	glLightf(id, GL_QUADRATIC_ATTENUATION, kq_);
	uploadL();
}

void PosLight::setPosDir(glm::fvec3 dir)
{
	posDir = glm::fvec4(dir, 1.0);
}

void PosLight::setAtte(GLfloat kc, GLfloat kl, GLfloat kq)
{
	kc_ = kc;
	kl_ = kl;
	kq_ = kq;
}
