#include "RGBCube.h"
#include <glm/gtc/matrix_transform.hpp>

RGBCube::RGBCube(GLdouble lenght)
{
	mMesh = Mesh::generateRGBCubeTriangles(lenght);
}

RGBCube::~RGBCube()
{
	delete mMesh;
}

void RGBCube::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
	}
}

void RGBCube::update()
{
	grades -= 2;

	glm::dmat4 m1 = glm::rotate(glm::dmat4(1.0), glm::radians(2.0), glm::dvec3(rotX, rotY, rotZ));
	m1 = m1 * mModelMat;
	setModelMat(m1);

	if (grades <= -180) {

		rotY = (nRot % 3) % 2;
		rotZ = ((nRot + 1) % 3) % 2;
		rotX = ((nRot + 2) % 3) % 2;
		nRot ++;
		grades = 0;
	}
}
