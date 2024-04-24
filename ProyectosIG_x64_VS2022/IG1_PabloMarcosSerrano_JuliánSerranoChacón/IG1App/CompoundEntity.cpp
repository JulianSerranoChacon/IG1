#include "CompoundEntity.h"

CompoundEntity::~CompoundEntity()
{
	for (Abs_Entity* e : gObjects) {
		delete e;
		e = nullptr;
	}
}

void CompoundEntity::addEntity(Abs_Entity* ae)
{
	gObjects.push_back(ae);
}

void CompoundEntity::render(glm::dmat4 const& modelViewMat) const
{
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);

	for (Abs_Entity* e : gObjects) {
		e->render(aMat);
	}
}
