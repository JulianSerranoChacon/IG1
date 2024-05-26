#pragma once
#include "Entity.h"
class Photo: public Abs_Entity
{
private:
	GLdouble w_;
	GLdouble h_;
public:
	Photo(GLdouble w, GLdouble h);
	~Photo();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	virtual void update() override;
};

