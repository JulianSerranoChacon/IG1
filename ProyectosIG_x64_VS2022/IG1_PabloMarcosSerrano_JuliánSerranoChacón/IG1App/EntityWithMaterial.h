#pragma once
#include "Entity.h"
#include "Material.h"

class EntityWithMaterial: public Abs_Entity
{
protected:
	Material* material_;
public:
	EntityWithMaterial() : Abs_Entity() { };
	virtual ~EntityWithMaterial() { };
	void setMaterial(Material* matl) { material_ = matl; };
};

