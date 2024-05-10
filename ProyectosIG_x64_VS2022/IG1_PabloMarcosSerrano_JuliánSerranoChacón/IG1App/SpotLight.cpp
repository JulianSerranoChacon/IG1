#include "SpotLight.h"

void SpotLight::upload(glm::dmat4 const& modelViewMat) const
{
	PosLight::upload(modelViewMat);
	glLightfv(id, GL_SPOT_DIRECTION, value_ptr(direction));
	glLightf(id, GL_SPOT_CUTOFF, cutoff);
	glLightf(id, GL_SPOT_EXPONENT, exp);
}

void SpotLight::setSpot(glm::fvec3 dir, GLfloat cf, GLfloat e)
{
	direction = glm::fvec4(dir, 0.0); cutoff = cf;
	exp = e;
}
