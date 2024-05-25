#include "AdvancedTIE.h"
#include "Entity.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Disk.h"
#include "WingAdvanceTIE.h"
#include "Texture.h"
#include <glm/gtc/matrix_transform.hpp>
#include "SpotLight.h"

AdvancedTIE::AdvancedTIE()
{
	lantern = new SpotLight(glm::fvec3(0, 0, 0));

	gObjects.push_back(new Sphere(30, 30, 30));//0
	gObjects[0]->setMColor(glm::dvec4(0, 0.25, 0.41, 1));

	gObjects.push_back(new Cylinder(8,8,180,30,30));//1
	gObjects[1]->setMColor(glm::dvec4(0, 0.25, 0.41, 1));
	gObjects[1]->setModelMat(glm::translate(gObjects[1]->modelMat(), glm::dvec3(0, 0, -90)));

	gObjects.push_back(new Cylinder(12, 12, 20, 30, 30));//2
	gObjects[2]->setMColor(glm::dvec4(0, 0.25, 0.41, 1));
	gObjects[2]->setModelMat(glm::rotate(glm::dmat4(1.0), glm::radians(90.0), glm::dvec3(0, 1, 0)));
	gObjects[2]->setModelMat(glm::translate(gObjects[2]->modelMat(), glm::dvec3(0, 0, 20)));

	gObjects.push_back(new Disk(12,0,30,30));
	gObjects[3]->setMColor(glm::dvec4(0, 0.25, 0.41, 1));
	gObjects[3]->setModelMat(glm::rotate(glm::dmat4(1.0), glm::radians(90.0), glm::dvec3(0, 1, 0)));
	gObjects[3]->setModelMat(glm::translate(gObjects[3]->modelMat(), glm::dvec3(0, 0, 20)));

	//alas
	gObjects.push_back(new WingAdvanceTIE(90, 120));//3
	gObjects[4]->setModelMat(glm::translate(gObjects[4]->modelMat(), glm::dvec3(0, 0, 38)));

	gObjects.push_back(new WingAdvanceTIE(90, 120));//4
	gObjects[5]->setModelMat(glm::rotate(glm::dmat4(1.0), glm::radians(180.0), glm::dvec3(0, 1, 0)));
	gObjects[5]->setModelMat(glm::translate(gObjects[5]->modelMat(), glm::dvec3(0, 0, 38)));


}

AdvancedTIE::~AdvancedTIE()
{
	for (Abs_Entity* e : gObjects) {
		delete e;
		e = nullptr;
		gObjects.pop_back();
	}
	delete lantern;
	lantern = nullptr;
}

void AdvancedTIE::setWingsTexture(Texture* t)
{
	gObjects[4]->setTexture(t);
	gObjects[5]->setTexture(t);
}

void AdvancedTIE::render(glm::dmat4 const& modelViewMat) const
{
	CompoundEntity::render(modelViewMat);
	glm::dmat4 aMat = modelViewMat * mModelMat;
	lantern->upload(aMat);
}

void AdvancedTIE::turnOffLantern()
{
	lantern->disable();
}

void AdvancedTIE::turnOnLantern()
{
	lantern->enable();
}
