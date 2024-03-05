#include "Ground.h"
#include <glm/gtc/matrix_transform.hpp>

Ground::Ground(GLdouble w, GLdouble h)
{

	mMesh = Mesh::generateRectangleTexCor(w, h,4,4);
	mModelMat = glm::rotate(mModelMat, glm::radians(-90.0), glm::dvec3(1, 0, 0));
}

Ground::~Ground()
{
	delete mMesh;
}

void Ground::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glPolygonMode(GL_BACK, GL_FILL);
		//glLineWidth(3);
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		glLineWidth(1);
		mTexture->unbind();
	}
}
