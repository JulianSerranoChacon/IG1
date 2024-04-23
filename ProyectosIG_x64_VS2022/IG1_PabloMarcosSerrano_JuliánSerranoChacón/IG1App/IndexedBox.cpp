#include "IndexedBox.h"
#include "IndexMesh.h"
IndexedBox::IndexedBox(GLuint l)
{
	mMesh = IndexMesh::generateIndexedBox(l);
}

IndexedBox::~IndexedBox()
{
	delete mMesh;
}

void IndexedBox::render(glm::dmat4 const& modelViewMat) const
{

	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}
