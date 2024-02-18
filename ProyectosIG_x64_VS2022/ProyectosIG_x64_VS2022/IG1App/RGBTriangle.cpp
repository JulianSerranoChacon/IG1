#include "RGBTriangle.h"


#include <glm/gtc/matrix_transform.hpp>

RGBTriangle::RGBTriangle(int r): Abs_Entity(), mr(r)
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

		//glPolygonMode(GL_BACK, GL_LINE); para que aparezcan las líneas
		glPolygonMode(GL_BACK, GL_POINT);

		glPointSize(5);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		glPointSize(1);
	}
}

void RGBTriangle::update()
{
	//glm::dmat4 m ;
	mModelMat = glm::rotate(mModelMat, glm::radians(-10.0), glm::dvec3(0, 0, 1));

}
