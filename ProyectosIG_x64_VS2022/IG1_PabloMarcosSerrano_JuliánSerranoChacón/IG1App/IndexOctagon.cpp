#include "IndexOctagon.h"
#include "IndexMesh.h"

IndexOctagon::IndexOctagon(GLuint l)
{
	mMesh = IndexMesh::generateIndexOctagon(l);
}

IndexOctagon::~IndexOctagon()
{
	delete mMesh;
}

void IndexOctagon::render(glm::dmat4 const& modelViewMat) const
{
	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}
