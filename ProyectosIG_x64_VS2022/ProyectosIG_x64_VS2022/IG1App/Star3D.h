#pragma once
#include "Entity.h"
class Star3D: public Abs_Entity
{
private:
	Mesh* secondaryMesh = nullptr;
public:
	Star3D(GLdouble re, GLuint np, GLdouble h);
	~Star3D();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	virtual void update() override;
};

