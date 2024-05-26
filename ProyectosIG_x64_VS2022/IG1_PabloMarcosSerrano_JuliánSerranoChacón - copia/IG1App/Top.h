#pragma once
#include "Entity.h"
class Top: public Abs_Entity
{
private:
	Texture* secondaryTexture = nullptr;
public:
	Top(GLuint lenght);
	~Top();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	void setSecundaryTexture(Texture* t);
};

