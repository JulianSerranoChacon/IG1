#include "SphereWitgLight.h"
#include "SpotLight.h"

SphereWitgLight::SphereWitgLight(GLuint r, GLuint p, GLuint m): SphereBR(r,p,m)
{
	lantern = new SpotLight(glm::fvec3(150, 0, 0));
}

SphereWitgLight::~SphereWitgLight()
{
	delete lantern;
}

void SphereWitgLight::render(glm::dmat4 const& modelViewMat) const
{
	SphereBR::render(modelViewMat);
	glm::dmat4 aMat = modelViewMat * mModelMat;
	lantern->upload(aMat);
}
