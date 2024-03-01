#include "BoxOutline.h"

BoxOutline::BoxOutline(GLdouble lenght)
{
	mMesh = Mesh::generateBoxOutlineTexCor(lenght);

	mTexture = new Texture();
	mTexture->load("../bmps/baldosaC.bmp", 1);
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
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		glLineWidth(1);
		mTexture->unbind();
	}
}
