#pragma once
#include "Entity.h"

class RGBTriangle: public Abs_Entity
{
private:
	int mr;
public:
	RGBTriangle(int r);
	virtual ~RGBTriangle();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	virtual void update() override;
	void setMr(const int nMr);
};

