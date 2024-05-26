#pragma once
#include "CompoundEntity.h"
class RGBTriangle;

class NodeRGBTriangle: public CompoundEntity
{
public:
	NodeRGBTriangle(GLuint l);
	virtual ~NodeRGBTriangle();
	virtual void update();
protected:
	CompoundEntity* inventedNode;
	RGBTriangle* tr;
};

