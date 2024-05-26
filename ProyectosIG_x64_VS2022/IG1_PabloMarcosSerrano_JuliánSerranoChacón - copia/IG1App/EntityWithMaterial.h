#pragma once
#include "Entity.h"
#include "Material.h"

class EntityWithMaterial: public Abs_Entity
{
protected:
	Material* material_ = nullptr;
public:
	EntityWithMaterial() : Abs_Entity() { };
	virtual ~EntityWithMaterial() { delete material_; };
	void setMaterial(Material* matl) { material_ = matl; };
};

