#include "TuberíaCompuesta.h"
#include "SemiToroid.h"
#include "SphereWitgLight.h"
#include "Material.h"
#include <glm/gtc/matrix_transform.hpp>

TuberíaCompuesta::TuberíaCompuesta()
{
	semiToroid = new SemiToroid(100, 200, 60, 60);
	semiToroid->setMColor(glm::dvec4(0, 0, 1, 1));
	addEntity(semiToroid);
	inventedNode = new CompoundEntity();
	addEntity(inventedNode);
	sphereBR = new SphereWitgLight(50, 50, 50);
	Material* m = new Material();
	m->setGold();
	sphereBR->setMaterial(m); 
	sphereBR->setModelMat(glm::translate(inventedNode->modelMat(), glm::dvec3(200, 0, 0)));
	inventedNode->addEntity(sphereBR); 
}

void TuberíaCompuesta::update()
{
	inventedNode->setModelMat(glm::rotate(inventedNode->modelMat(), glm::radians(mod), glm::dvec3(0.0, 1.0, 0.0)));
	cont += mod;
	if ((mod > 0 && cont > 90) || (mod < 0 && cont < 0)) {
		mod = -mod;
	}
}
