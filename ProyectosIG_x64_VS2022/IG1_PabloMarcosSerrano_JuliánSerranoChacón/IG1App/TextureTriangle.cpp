#include "TextureTriangle.h"
#include "IndexMesh.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

TextureTriangle::TextureTriangle(GLdouble la)
{
	mMesh = IndexMesh::generateTexturePiramid(la);
	//mMesh = IndexMesh::generateTetahedron(l);
    l = la;
}

TextureTriangle::~TextureTriangle()
{
	delete mMesh;
}

void TextureTriangle::render(glm::dmat4 const& modelViewMat) const
{
    if (mMesh != nullptr) {
        mTexture->setWrap(GL_REPEAT);
        mTexture->bind(GL_REPLACE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::dmat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
        upload(aMat);
        mMesh->render();


        aMat = glm::translate(aMat, glm::dvec3(0, -l, 0));
        aMat = glm::scale(aMat, glm::dvec3(1.9, 1.9, 1.9));
        upload(aMat);
        mMesh->render();

        double lado = 360.0 / 3;
        double t = 0.0;
        aMat = modelViewMat * mModelMat;
        for (int i = 0; i < 3; i++) {
            double x = l * glm::cos(glm::radians(t));
            double z = l * glm::sin(glm::radians(t));
            aMat = glm::translate(aMat, glm::dvec3(x, -l, z));
            upload(aMat);
            mMesh->render();
            aMat = modelViewMat * mModelMat;
            t += lado;
        }

        t = 180.0;
        aMat = modelViewMat * mModelMat;
        for (int i = 0; i < 3; i++) {
            aMat = glm::scale(aMat, glm::dvec3(1, -1, 1));
            double x = l * glm::cos(glm::radians(t));
            double z = l * glm::sin(glm::radians(t));
            aMat = glm::translate(aMat, glm::dvec3(-x, l, -z));
            upload(aMat);
            mMesh->render();
            aMat = modelViewMat * mModelMat;
            t += lado;
        }

        aMat = modelViewMat * mModelMat; // glm matrix multiplication
        aMat = glm::translate(aMat, glm::dvec3(0, -l * 2, 0));
        aMat = glm::scale(aMat, glm::dvec3(1, -1, 1));
        upload(aMat);
        mMesh->render();

        aMat = glm::translate(aMat, glm::dvec3(0, -l, 0));
        aMat = glm::scale(aMat, glm::dvec3(1.9, 1.9, 1.9));
        upload(aMat);
        mMesh->render();

        mTexture->unbind();
        glDisable(GL_BLEND);
    }
}
