#pragma once
#include "entity.h"
class BoxOutline: public Abs_Entity
{
private:
	Texture* secondaryTexture;
public:
	BoxOutline(GLdouble lenght);
	virtual ~BoxOutline();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	void setSecundaryTexture(Texture* t);
};

