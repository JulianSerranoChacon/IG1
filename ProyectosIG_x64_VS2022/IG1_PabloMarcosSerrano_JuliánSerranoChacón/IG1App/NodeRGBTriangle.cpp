#include "NodeRGBTriangle.h"
#include "RGBTriangle.h"
#include <glm/gtc/matrix_transform.hpp>

NodeRGBTriangle::NodeRGBTriangle(GLuint l)
{
	inventedNode = new CompoundEntity();
	gObjects.push_back(inventedNode);
	tr = new RGBTriangle(l);
	inventedNode->addEntity(tr);
	tr->setModelMat(glm::translate(inventedNode->modelMat(),glm::dvec3(200, 0, 0)));
}

NodeRGBTriangle::~NodeRGBTriangle()
{
}

void NodeRGBTriangle::update()
{
	inventedNode->setModelMat(glm::rotate(inventedNode->modelMat(), glm::radians(3.0), glm::dvec3(0, 0, 1)));
	tr->setModelMat(glm::rotate(tr->modelMat(), glm::radians(-6.0), glm::dvec3(0, 0, 1)));
}
