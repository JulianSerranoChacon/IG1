#include "RegularPolygon.h"

RegularPolygon::RegularPolygon(int num, int r): Abs_Entity()
{
	mMesh = Mesh::generateRegularPolygon(num, r);
}

RegularPolygon::~RegularPolygon()
{

}

void RegularPolygon::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		glLineWidth(2);
		mMesh->render();
		glLineWidth(1);
	}
}

