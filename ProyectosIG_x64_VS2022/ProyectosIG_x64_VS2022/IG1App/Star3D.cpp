#include "Star3D.h"

Star3D::Star3D(GLdouble re, GLuint np, GLdouble h)
{
	mMesh = Mesh::generateStar3D(re, np, h);
	secondaryMesh = Mesh::generateStar3D(re, np, -h);
}

Star3D::~Star3D()
{
	delete mMesh;
	delete secondaryMesh;
}

void Star3D::render(glm::dmat4 const& modelViewMat) const
{

	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		upload(aMat);
		glLineWidth(2);
		mMesh->render();
		glLineWidth(1);
	}
	if (secondaryMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		upload(aMat);
		glLineWidth(2);
		secondaryMesh->render();
		glLineWidth(1);
	}
}
