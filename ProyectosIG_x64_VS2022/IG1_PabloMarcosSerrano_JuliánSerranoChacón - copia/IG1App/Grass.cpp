#include "Grass.h"
#include <glm/gtc/matrix_transform.hpp>

Grass::Grass()
{
	mMesh = Mesh::generateRectangleTexCor(50, 50, 1, 1);
	mModelMat = glm::rotate(mModelMat, glm::radians(90.0), glm::dvec3(0, 0, 1));
	mModelMat = glm::translate(mModelMat, glm::dvec3(25, 0, 50));
}

Grass::~Grass()
{
	delete mMesh;
}

void Grass::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glEnable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		aMat = glm::rotate(aMat, glm::radians(45.0), glm::dvec3(1, 0, 0));
		upload(aMat);
		mMesh->render();
		aMat = glm::rotate(aMat, glm::radians(45.0), glm::dvec3(1, 0, 0));
		upload(aMat);
		mMesh->render();
		mTexture->unbind();
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
	}
}
