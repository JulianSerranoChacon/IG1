#include "SphereBR.h"
#include "MbR.h"

SphereBR::SphereBR(GLuint r, GLuint p, GLuint m)
{
	//Desde d�nde queremos emprezar (�ngulo)
	GLdouble alpha = 90;
	//
	glm::dvec3* perfil = new glm::dvec3[p + 1];
	GLdouble aux = 180.0 / p - 1;
	//creaos pol�gono
	for (int i = 0; i < perfil->length(); i++) {
		perfil[i] = glm::dvec3(r * cos(glm::radians(alpha)), r * sin(glm::radians(alpha)), 0);
		alpha += aux;
	}

	mMesh = MbR::generaIndexMbR(p,m, perfil);
}

SphereBR::~SphereBR()
{
	delete mMesh;
}


void SphereBR::render(glm::dmat4 const& modelViewMat) const
{
	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}