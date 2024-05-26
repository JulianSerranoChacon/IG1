#include "QuadricEntity.h"

QuadricEntity::QuadricEntity()
{
	q = gluNewQuadric();
}

QuadricEntity::~QuadricEntity()
{
	gluDeleteQuadric(q);
}
