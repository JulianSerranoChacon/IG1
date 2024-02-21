#pragma once
#include "Entity.h"

class RGBCube: public Abs_Entity
{
private:
	GLint rotX = 1, rotY = 0, rotZ = 0, grades = 0, nRot = 0;

public:
	RGBCube(GLdouble lenght);
	~RGBCube();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	virtual void update() override;
};

