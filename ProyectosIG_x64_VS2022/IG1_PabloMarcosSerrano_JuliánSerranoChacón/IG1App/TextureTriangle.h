#pragma once
#include "Entity.h"

class TextureTriangle : public Abs_Entity
{
public:
	TextureTriangle(GLdouble); 
	~TextureTriangle(); 
	virtual void render(glm::dmat4 const& modelViewMat) const;
private: 
	GLdouble l;
};

