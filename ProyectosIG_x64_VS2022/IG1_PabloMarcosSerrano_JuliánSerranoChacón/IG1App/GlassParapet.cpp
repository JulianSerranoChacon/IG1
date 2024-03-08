#include "GlassParapet.h"

GlassParapet::GlassParapet(GLdouble lenght)
{
	mMesh = Mesh::generateBoxOutlineTexCor(lenght);
}

GlassParapet::~GlassParapet()
{
	delete mMesh;
}

void GlassParapet::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		mTexture->unbind();
		glDisable(GL_BLEND);
	}
}
