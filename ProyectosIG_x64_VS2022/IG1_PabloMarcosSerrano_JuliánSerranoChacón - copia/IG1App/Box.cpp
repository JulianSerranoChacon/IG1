#include "Box.h"
#include "Top.h"
#include <glm/gtc/matrix_transform.hpp>

Box::Box(GLuint lenght)
{
	lenght_ = lenght;
	mMesh = Mesh::generateBoxOutlineTexCor(lenght);
	floor = new Top(lenght);
	ceilling = new Top(lenght);
	floor->setModelMat(glm::rotate(floor->modelMat(), glm::radians(90.0), glm::dvec3(1, 0, 0)));
	floor->setModelMat(glm::translate(floor->modelMat(), glm::dvec3(0,0,lenght * 0.5)));

	ceilling->setModelMat(glm::rotate(ceilling->modelMat(), glm::radians(-90.0), glm::dvec3(1, 0, 0)));
	ceilling->setModelMat(glm::translate(ceilling->modelMat(), glm::dvec3(0, 0, lenght * 0.5)));
}

Box::~Box()
{
	delete mMesh;
	delete ceilling;
	delete floor;
}

void Box::render(glm::dmat4 const& modelViewMat) const
{

	if (mMesh != nullptr) {

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		mTexture->setWrap(GL_REPEAT);
		mTexture->bind(GL_REPLACE);
		glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mMesh->render();
		mTexture->unbind();

		glCullFace(GL_FRONT);
		secondaryTexture->setWrap(GL_REPEAT);
		secondaryTexture->bind(GL_REPLACE);
		upload(aMat);
		mMesh->render();
		secondaryTexture->unbind();
		glDisable(GL_CULL_FACE);
	}
	ceilling->render(modelViewMat);
	floor->render(modelViewMat);
}

void Box::setSecundaryTexture(Texture* t)
{
	secondaryTexture = t;
	ceilling->setSecundaryTexture(t);
	floor->setSecundaryTexture(t);
}

void Box::setTopsTexture(Texture* t)
{
	ceilling->setTexture(t);
	floor->setTexture(t);
}

void Box::update()
{
	grades += giro;
	double radians = grades;
	GLfloat mid = lenght_ / 2.0;
	if (abrir) {
		glm::dmat4 m = glm::rotate(glm::dmat4(1.0), glm::radians(-90.0), glm::dvec3(1, 0, 0));
		m = m * glm::translate(glm::dmat4(1.0), glm::dvec3(0, mid, mid));
		m = m * glm::rotate(glm::dmat4(1), glm::radians(-radians), glm::dvec3(1, 0, 0));
		m = m * glm::translate(glm::dmat4(1.0), glm::dvec3(0 , -mid,0));
		ceilling->setModelMat(m);
	}
	else {
		glm::dmat4 m = glm::rotate(glm::dmat4(1.0), glm::radians(-90.0), glm::dvec3(1, 0, 0));
		m = m * glm::translate(glm::dmat4(1.0), glm::dvec3(0, mid, mid));
		m = m * glm::rotate(glm::dmat4(1), glm::radians(-radians), glm::dvec3(1, 0, 0));
		m = m * glm::translate(glm::dmat4(1.0), glm::dvec3(0, -mid, 0));
		ceilling->setModelMat(m);
	}

	if (abrir && grades >= 120) {
		abrir = false;
		giro = giro * -1;
	}
	else if (!abrir && grades <= 0) {
		abrir = true;
		giro = giro * -1;
	}
}