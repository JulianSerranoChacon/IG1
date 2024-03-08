#include "Star3D.h"
#include <glm/gtc/matrix_transform.hpp>

Star3D::Star3D(GLdouble re, GLuint np, GLdouble h)
{
	mMesh = Mesh::generateStar3DTexCor(re, np, h);
	secondaryMesh = Mesh::generateStar3DTexCor(re, np, -h);
}

Star3D::~Star3D()
{
	delete mMesh;
	delete secondaryMesh;
}

void Star3D::render(glm::dmat4 const& modelViewMat) const
{

	if (mMesh != nullptr) {
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		mTexture->unbind();
	}
	if (secondaryMesh != nullptr) {
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		secondaryMesh->render();
		mTexture->unbind();
	}
}

void Star3D::update()
{
	glm::dmat4 m1 = glm::rotate(mModelMat, glm::radians(2.0), glm::dvec3(0, 0, 1));
	glm::dmat4 m2 = glm::rotate(glm::dmat4(1.0), glm::radians(2.0), glm::dvec3(0, 1, 0));
	glm::dmat4 ma = m2 * m1;
	setModelMat(ma); 
}