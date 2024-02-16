#include "Cube.h"


Cube::Cube(GLdouble lenght)
{
	mMesh = Mesh::generateCube(lenght);
}

Cube::~Cube()
{
	delete mMesh;
}

void Cube::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_POINT);
		glLineWidth(3);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		glLineWidth(1);
	}
}