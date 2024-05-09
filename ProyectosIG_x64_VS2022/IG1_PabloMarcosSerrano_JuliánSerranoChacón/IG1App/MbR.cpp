#include "MbR.h"

MbR::MbR(int n, glm::dvec3* perfil, int m): IndexMesh(), n_(n),perfil_(perfil), m_(m)
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
	glm::dvec3 * vs = new glm::dvec3 [mesh->mNumVertices ];
	int indiceMenor = 0;
	for (int i = 0; i < nn; i++) {
		// Generar la muestra i- ésima de vértices
		GLdouble theta = i * 360 / nn;
		GLdouble c = cos(glm::radians(theta));
		GLdouble s = sin(glm::radians(theta));
		for (int j = 0; j < mm; j++) {
			GLdouble x = c * perfil[j].x + s * perfil[j].z;
			GLdouble z = -s * perfil[j].x + c * perfil[j].z;
			vs[indiceMenor] = glm::dvec3(x, perfil[j].y, z);
			indiceMenor++;
		}
	}

	//construimos las normales
	for (int i = 0; i < mesh->mNumVertices; i++) {
		mesh->vVertices.emplace_back(vs[i]);
	}

	mesh->mNumIndices = nn * (mm - 1) * 6;
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

		// Definir los índices de los vértices para el triángulo actual
			mesh->vIndices[indiceMayor] = indice;
			mesh->vIndices[indiceMayor + 1] = (indice + mm) % (nn * mm);
			mesh->vIndices[indiceMayor + 2] = (indice + mm + 1) % (nn * mm);
			mesh->vIndices[indiceMayor + 3] = (indice + mm + 1) % (nn * mm);
			mesh->vIndices[indiceMayor + 4] = indice + 1;
			mesh->vIndices[indiceMayor + 5] = indice;
			// Incrementar el contador de índices
			indiceMayor += 6;
		}
	}

	mesh->vNormals.reserve(mesh->mNumVertices);
	for (int i = 0; i < mesh->mNumVertices; i++)
		mesh->vNormals.emplace_back(0.0, 0.0, 0.0);


	//construimos las normales
	for (int i = 0; i < mesh->mNumIndices; i += 3) {    // Obtener los índices del triángulo actual
		std::vector<GLuint> triangleIndices = {
			mesh->vIndices[i + 2],
			mesh->vIndices[i + 1],
			mesh->vIndices[i]
		};

		// Construir la normal de la cara del triángulo actual
		mesh->buildNormalVectors(mesh, triangleIndices);
	}

	//mesh->vColors.reserve(mesh->mNumVertices);

	//for (int i = 0; i < mesh->mNumVertices; i++)
	//mesh->vColors.emplace_back(mesh->vNormals[i].x, mesh->vNormals[i].y, mesh->vNormals[i].z,1);

	delete[] vs;

	return mesh;
}