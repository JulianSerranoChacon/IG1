#include "LightSphere.h"
#include "SpotLight.h"

LightSphere::LightSphere(GLuint r, GLuint p, GLuint m) : SphereBR(r, p, m)
{
	me = new SpotLight();
}

LightSphere::~LightSphere()
{
	delete me;
	me = nullptr;
}

void LightSphere::render(glm::dmat4 const& modelViewMat) const
{
	SphereBR::render(modelViewMat);
	glm::dmat4 amat = modelViewMat * mModelMat;
	me->upload(amat);
}
