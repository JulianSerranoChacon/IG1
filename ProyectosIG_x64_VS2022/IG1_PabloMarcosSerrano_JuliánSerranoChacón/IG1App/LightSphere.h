#pragma once
#include "SphereBR.h"

class SpotLight;

class LightSphere : public SphereBR
{
public:
	LightSphere(GLuint r, GLuint p, GLuint m);
	virtual ~LightSphere();
	virtual void render(glm::dmat4 const& modelViewMat) const;
private:
	SpotLight* me;
};

