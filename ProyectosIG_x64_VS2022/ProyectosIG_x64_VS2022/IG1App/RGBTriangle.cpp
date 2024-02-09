#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(int r): Abs_Entity()
{
	mMesh = Mesh::generateRGBTriangle(r);
}

RGBTriangle::~RGBTriangle()
{
	delete mMesh;
}

void RGBTriangle::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glPolygonMode(GL_FRONT, GL_FILL);

		//glPolygonMode(GL_BACK, GL_LINE); para que aparezcan las l�neas
		glPolygonMode(GL_BACK, GL_POINT);

		glPointSize(5);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		glPointSize(1);
	}
}
