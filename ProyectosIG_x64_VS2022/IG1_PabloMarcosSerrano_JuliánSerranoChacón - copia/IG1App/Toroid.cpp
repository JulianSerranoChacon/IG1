#include "Toroid.h"
#include "MbR.h"
#include <glm/gtc/matrix_transform.hpp>

Toroid::Toroid(GLuint r, GLuint R, GLuint m, GLuint p)
{
	//Desde dónde queremos emprezar (ángulo)
	GLdouble alpha = 90;
	//
	glm::dvec3* perfil = new glm::dvec3[p + 1];
	GLdouble aux = 360.0 / (p - 1);
	//creaos polígono
	for (int i = 0; i < p; i++) {
		perfil[i] = glm::dvec3(r * cos(glm::radians(alpha)) + R, r * sin(glm::radians(alpha)) , 0);
		alpha += aux;
	}

	mMesh = MbR::generaIndexMbR(p, m, perfil);

	//setModelMat(glm::translate(mModelMat, glm::dvec3(r, 0, 0)));
}

Toroid::~Toroid()
{
	delete mMesh;
}

void Toroid::render(glm::dmat4 const& modelViewMat) const
{
	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}
