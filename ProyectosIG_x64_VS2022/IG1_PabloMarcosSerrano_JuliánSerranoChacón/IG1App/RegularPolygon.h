#pragma once
#include "Entity.h"
class RegularPolygon: public Abs_Entity
{
public:
	//Constructora
	RegularPolygon(int num, int r);
	//destructora
	virtual ~RegularPolygon();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};