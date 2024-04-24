#include "Tatooine.h"
#include "AdvancedTIE.h"
#include "Sphere.h"
#include <glm/gtc/matrix_transform.hpp>

Tatooine::Tatooine()
{
	inventedNode = new CompoundEntity();
	gObjects.push_back(inventedNode);
	tatooine = new Sphere(300, 50, 50);
	tatooine->setColor(glm::dvec4(255, 233, 0,1));
	tie = new AdvancedTIE();
	inventedNode->addEntity(tatooine);
	inventedNode->addEntity(tie);
	tie->setModelMat(glm::translate(inventedNode->modelMat(), glm::dvec3(0, 340, 0)));
}

Tatooine::~Tatooine()
{
}

void Tatooine::rotate()
{
	inventedNode->setModelMat(glm::rotate(inventedNode->modelMat(), glm::radians(3.0), glm::dvec3(0, 1, 0)));
}

void Tatooine::orbit()
{
	inventedNode->setModelMat(glm::rotate(inventedNode->modelMat(), glm::radians(-3.0), glm::dvec3(0, 0, 1)));
}

void Tatooine::setWingsTexture(Texture* t)
{
	tie->setWingsTexture(t);
	tie->setWingsTexture(t);
}
