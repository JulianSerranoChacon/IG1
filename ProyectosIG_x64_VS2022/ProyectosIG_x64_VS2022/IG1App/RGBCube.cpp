#include "RGBCube.h"

RGBCube::RGBCube(GLdouble lenght)
{
	mMesh = Mesh::generateRGBCubeTriangles(lenght);
}

RGBCube::~RGBCube()
{
	delete mMesh;
}

void RGBCube::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
	}
}
