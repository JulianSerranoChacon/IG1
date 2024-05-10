#include "SphereBR.h"
#include "MbR.h"

SphereBR::SphereBR(GLuint r, GLuint p, GLuint m)
{
	//Desde dónde queremos emprezar (ángulo)
	GLdouble alpha = 270.0;
	//
	glm::dvec3* perfil = new glm::dvec3[p+1];
	GLdouble aux = 180.0/ (p-1);
	//creaos polígono
	for (int i = 0; i < p; i++) {
		perfil[i] = glm::dvec3(r * cos(glm::radians(alpha)), r * sin(glm::radians(alpha)), 0.0);
		alpha += aux;
	}

	mMesh = MbR::generaIndexMbR(p, m, perfil);
}

SphereBR::~SphereBR()
{
	delete mMesh;
}


void SphereBR::render(glm::dmat4 const& modelViewMat) const
{
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);

	if (material_ == nullptr) {
		glColor3f(getMColor().x, getMColor().y, getMColor().z);
		mMesh->render();
		glColor3f(1.0, 1.0, 1.0);
	}
	else {
		glDisable(GL_COLOR_MATERIAL);
		//glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		// cara es GL_FRONT , GL_BACK o ambas ,
		// y componenteDeLaLuz es GL_AMBIENT , GL_DIFFUSE , GL_SPECULAR , ...
		glColor3f(getMColor().x, getMColor().y, getMColor().z);
		material_->upload();
		mMesh->render();
		glColor3f(1.0, 1.0, 1.0);
		glEnable(GL_COLOR_MATERIAL);

	}
}