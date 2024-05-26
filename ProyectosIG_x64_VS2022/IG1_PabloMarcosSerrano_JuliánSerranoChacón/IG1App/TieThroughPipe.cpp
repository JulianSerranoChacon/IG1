#include "TieThroughPipe.h"
#include "SphereBR.h"
#include "SpotLight.h"
#include "HalfPipe.h"
#include "Material.h"
#include "LightSphere.h"

TieThroughPipe::TieThroughPipe()
{
	tunnel = new HalfPipe(100, 200, 60, 60);
	tunnel->setMColor(glm::dvec4(0, 1, 1, 1));
	gObjects.push_back(tunnel);

	inventedNode = new CompoundEntity();
	gObjects.push_back(inventedNode);

	material = new Material();
	material->setGold();
	orb = new SphereBR(50, 40, 40);
	orb->setMaterial(material);
	orb->setModelMat(glm::translate(orb->modelMat(), glm::dvec3(200.0, 0.0, 0)));
	inventedNode->addEntity(orb);
	
	cont = 0;
	mod = 2.0;
}

TieThroughPipe::~TieThroughPipe()
{
}

void TieThroughPipe::update()
{
	inventedNode->setModelMat(glm::rotate(inventedNode->modelMat(), glm::radians(mod), glm::dvec3(0.0, 1.0, 0.0)));
	cont += mod;
	if ((mod > 0 && cont > 90) || (mod < 0 && cont < 0)) {
		mod = -mod;
	}
}
