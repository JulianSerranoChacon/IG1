#include "MbR.h"

MbR::MbR(int n, glm::dvec3* perfil, int m): n_(n),perfil_(perfil), m_(m)
{
}

MbR::~MbR()
{
	delete[] perfil_;
}

MbR* MbR::generaIndexMbR(int mm, int nn, glm::dvec3* perfil)
{
	MbR* mesh = new MbR(nn, perfil, mm);

	// Usar un vector auxiliar de vértices
	mesh->mPrimitive = GL_TRIANGLES;

	mesh->mNumVertices = nn * mm;
	int indiceMenor = 0;
	glm::dvec3 * vs = new glm::dvec3 [mesh->mNumVertices ];
	for (int i = 0; i < nn; i++) {
		// Generar la muestra i- ésima de vértices
		GLdouble theta = i * 360 / nn;
		GLdouble c = cos(glm::radians(theta));
		GLdouble s = sin(glm::radians(theta));
		for (int j = 0; j < mm; j++) {
			GLdouble z = -s * perfil[j].x + c * perfil[j].z;
			GLdouble x = c * perfil[j].x + s * perfil[j].z;
			vs[indiceMenor] = glm::dvec3(x, perfil[j].y, z);
			indiceMenor++;
		}
	}

 
	//construimos las normales
	for (int i = 0; i < mesh->mNumVertices; i = i + 3) {
		mesh->vVertices.emplace_back(vs[i]);
	}

	mesh->vIndices = new GLuint[mesh->mNumIndices];

	int indiceMayor = 0;
	for (int i = 0; i < nn; i++) {
		// El contador j recorre los vértices del perfil ,
		// de abajo arriba . Las caras cuadrangulares resultan
		// al unir la muestra i- ésima con la (i +1)% nn - ésima
		for (int j = 0; j < mm - 1; j++)
		{
			// El contador indice sirve para llevar cuenta
			// de los índices generados hasta ahora . Se recorre
			// la cara desde la esquina inferior izquierda
			int indice = i * mm + j;
			// Los cuatro índices son entonces :
			//indice, (indice + mm) % (nn * mm), (indice + mm + 1) % (nn * mm), indice + 1;

			mesh->vIndices[indiceMayor] = indice;
			indiceMayor++;
			mesh-> vIndices[indiceMayor] = (indice + mm) % (nn * mm);
			indiceMayor++;
			mesh-> vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
			indiceMayor++;

			// Y análogamente se añaden los otros tres índices
			mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
			indiceMayor++;
			mesh->vIndices[indiceMayor] = indice + 1;
			indiceMayor++;
			mesh->vIndices[indiceMayor] = indice;
			indiceMayor++;
		}
	}

	mesh->vNormals.reserve(mesh->mNumVertices);

	//construimos las normales
	for (int i = 0; i < mesh->mNumVertices; i = i + 3) {
		std::vector<GLuint> cara;
		cara.push_back(mesh->vIndices[i]);
		cara.push_back(mesh->vIndices[i + 1]);
		cara.push_back(mesh->vIndices[i + 2]);
		mesh->buildNormalVectors(mesh, cara);
	}

	delete[] vs;

	return mesh;
}