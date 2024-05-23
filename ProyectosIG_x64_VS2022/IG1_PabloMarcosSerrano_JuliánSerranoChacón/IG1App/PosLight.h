#pragma once
#include "Light.h"

class PosLight : public Light {
protected:
	// Factores de atenuación
	GLfloat kc_ = 1, kl_ = 0, kq_ = 0;
public:
	PosLight() :Light() {};
	~PosLight() {};
	virtual void upload(glm::dmat4 const& modelViewMat) const;
	void setPosDir(glm::fvec3 dir);
	void setAtte(GLfloat kc, GLfloat kl, GLfloat kq);
};

