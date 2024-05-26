#include "RegularPolygon.h"

RegularPolygon::RegularPolygon(int num, int r): Abs_Entity()
{
	mMesh = Mesh::generateRegularPolygon(num, r);
}

RegularPolygon::~RegularPolygon()
{
	delete mMesh;
}

void RegularPolygon::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		glLineWidth(2);
		glColor4d(mColor.r, mColor.g, mColor.b, mColor.a);
		mMesh->render();
		glLineWidth(1);
		glColor4d(1,1,1,1);
	}
}

