#pragma once
#include "SphereBR.h"

class SpotLight;

class SphereWitgLight: public SphereBR
{
public:
	SphereWitgLight(GLuint r, GLuint p, GLuint m);
	virtual ~SphereWitgLight();
	virtual void render(glm::dmat4 const& modelViewMat) const;
protected:
	SpotLight* lantern;
};

