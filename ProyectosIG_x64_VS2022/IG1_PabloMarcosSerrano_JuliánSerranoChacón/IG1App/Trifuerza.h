#pragma once
#include "CompoundEntity.h"
class Texture;

class Trifuerza :public CompoundEntity
{
public:
	Trifuerza();
	virtual ~Trifuerza();
	void setTextures(Texture* t);
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

