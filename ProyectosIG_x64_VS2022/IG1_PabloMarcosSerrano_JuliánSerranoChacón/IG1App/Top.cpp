#include "Top.h"

Top::Top(GLuint lenght)
{
	mMesh = Mesh::generateRectangleTexCor(lenght, lenght, 1, 1);
}

Top::~Top()
{
	delete mMesh;
}

void Top::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		mTexture->unbind();

		glCullFace(GL_FRONT);
		secondaryTexture->setWrap(GL_REPEAT);
		secondaryTexture->bind(GL_REPLACE);
		upload(aMat);
		mMesh->render();
		secondaryTexture->unbind();
		glDisable(GL_CULL_FACE);
	}
}

void Top::setSecundaryTexture(Texture* t)
{
	secondaryTexture = t;
}
