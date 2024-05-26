#include "SemiToroid.h"
#include "MbR.h"

SemiToroid::SemiToroid(GLuint r, GLuint R, GLuint m, GLuint p)
{
	//Desde d�nde queremos emprezar (�ngulo)
	GLdouble alpha = 90;
	//
	glm::dvec3* perfil = new glm::dvec3[p + 1];
	GLdouble aux = 360.0 / (p - 1);
	//creaos pol�gono
	for (int i = 0; i < p; i++) {
		perfil[i] = glm::dvec3(r * cos(glm::radians(alpha)) + R, r * sin(glm::radians(alpha)), 0);
		alpha += aux;
	}

	mMesh = MbR::generaIndexMbRIncompleto(p, m, perfil);
}

SemiToroid::~SemiToroid()
{
	delete mMesh;
}

void SemiToroid::render(glm::dmat4 const& modelViewMat) const
{
	glColor3f(getMColor().x, getMColor().y, getMColor().z);
	mMesh->render();
	glColor3f(1.0, 1.0, 1.0);
}
