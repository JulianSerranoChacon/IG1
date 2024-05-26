#include "IndexedOctogone.h"
#include "IndexMesh.h"

IndexedOctogone::IndexedOctogone(GLdouble l, GLdouble h)
{
	mMesh = IndexMesh::generateIndexedOctogone(l,h);
}

IndexedOctogone::~IndexedOctogone()
{
	delete mMesh;
}

void IndexedOctogone::render(glm::dmat4 const& modelViewMat) const
{
	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}
