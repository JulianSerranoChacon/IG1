#pragma once
#include "Entity.h"

class Top;
class Box: public Abs_Entity
{
private:
	Texture* secondaryTexture = nullptr;
	Top* ceilling = nullptr;
	Top* floor = nullptr;

	GLint grades = 0, giro = 2;
	bool abrir = true;
	GLint lenght_;

public:
	Box(GLuint lenght);
	~Box();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	void setSecundaryTexture(Texture* t);
	void setTopsTexture(Texture* t);
	virtual void update() override;
};

