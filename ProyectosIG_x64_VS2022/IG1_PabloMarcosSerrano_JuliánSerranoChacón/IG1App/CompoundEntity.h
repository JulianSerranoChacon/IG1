#pragma once
#include "Entity.h"

class CompoundEntity: public Abs_Entity
{
public:
	virtual ~CompoundEntity();
	virtual void addEntity(Abs_Entity* ae);
	virtual void render(glm::dmat4 const& modelViewMat) const;
protected:
	std::vector<Abs_Entity*> gObjects;
};

