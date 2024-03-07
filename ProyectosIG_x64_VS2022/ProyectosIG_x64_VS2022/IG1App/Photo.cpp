#include "Photo.h"
#include <glm/gtc/matrix_transform.hpp>
Photo::Photo(GLdouble w, GLdouble h)
{
	mMesh = Mesh::generateRectangleTexCor(w, h, 4, 4);
	mModelMat = glm::rotate(mModelMat, glm::radians(-90.0), glm::dvec3(1, 0, 0));
	mModelMat = glm::translate(mModelMat, glm::dvec3(30, -30,1));
}

Photo::~Photo()
{
	delete mMesh;
}

void Photo::render(glm::dmat4 const& modelViewMat) const
{

	if (mMesh != nullptr) {
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		mTexture->unbind();
	}
}
