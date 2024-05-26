#include "Trifuerza.h"
#include "TextureTriangle.h"

Trifuerza::Trifuerza()
{
	//gObjects.push_back(new TextureTriangle());
}

Trifuerza::~Trifuerza()
{
}

void Trifuerza::setTextures(Texture* t)
{
}

void Trifuerza::render(glm::dmat4 const& modelViewMat) const
{
	CompoundEntity::render(modelViewMat);
}
