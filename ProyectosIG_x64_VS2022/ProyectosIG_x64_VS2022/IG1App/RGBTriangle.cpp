#include "RGBTriangle.h"


#include <glm/gtc/matrix_transform.hpp>

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
	glm::dmat4 m1 = mModelMat;
	glm::dmat4 m2 = glm::rotate(glm::dmat4(1.0), glm::radians(2.0), glm::dvec3(0, 0, 1));

	m1 = glm::rotate(m1, glm::radians(-4.0), glm::dvec3(0, 0, 1));
	m1 = m2 * m1;
	setModelMat(m1);
}

void RGBTriangle::setMr(const int nMr)
{
	mr = nMr;
}