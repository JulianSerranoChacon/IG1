#pragma once
#include "CompoundEntity.h"
class Texture;
class SpotLight;

class AdvancedTIE: public CompoundEntity
{
public:
	AdvancedTIE();
	virtual ~AdvancedTIE();
	void setWingsTexture(Texture* t);
	virtual void render(glm::dmat4 const& modelViewMat) const;

	void turnOffLantern();
	void turnOnLantern();
protected:
	SpotLight* lantern = nullptr;
};

