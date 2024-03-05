#include "BoxOutline.h"

BoxOutline::BoxOutline(GLdouble lenght)
{
	mMesh = Mesh::generateBoxOutlineTexCor(lenght);
}

BoxOutline::~BoxOutline()
{
	delete mMesh;
}

void BoxOutline::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glPolygonMode(GL_BACK, GL_POINT);
		//glLineWidth(3);

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
	}
}

void BoxOutline::setSecundaryTexture(Texture* t)
{
	secondaryTexture = t;
}
