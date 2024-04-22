#include "WingAdvanceTIE.h"

WingAdvanceTIE::WingAdvanceTIE(GLdouble w, GLdouble h)
{
	mMesh = Mesh::generateWingsTexCor(w, h);
}

WingAdvanceTIE::~WingAdvanceTIE()
{
	delete mMesh;
}

void WingAdvanceTIE::render(glm::dmat4 const& modelViewMat) const
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
