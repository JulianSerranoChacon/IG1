#include "IndexMesh.h"
#include <iostream>


void IndexMesh::render() const {

	if (vVertices.size() > 0) { // transfer data
		// transfer the coordinates of the vertices
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(
			3, GL_DOUBLE, 0, vVertices.data()); // number of coordinates per vertex, type of
		// each coordinate, stride, pointer
		if (vColors.size() > 0) {             // transfer colors
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(
				4, GL_DOUBLE, 0, vColors.data()); // components number (rgba=4), type of
			// each component, stride, pointer
		}
		if (vTexCoords.size() > 0) {

			//texruras
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_DOUBLE, 0, vTexCoords.data());
		}

		if (vNormals.size() > 0) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_DOUBLE, 0, vNormals.data());
		}

		// Nuevos comandos para la tabla de índices
		if (vIndices != nullptr) {
			glEnableClientState(GL_INDEX_ARRAY);
			glIndexPointer(GL_UNSIGNED_INT, 0, vIndices);
		}

		draw();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);

		// Nuevo comando para la tabla de índices :
		glDisableClientState(GL_INDEX_ARRAY);
	}
}

// Comando para renderizar la malla indexada enviada
void IndexMesh::draw() const {
	glDrawElements(mPrimitive, mNumIndices,
		GL_UNSIGNED_INT, vIndices);

}

IndexMesh* IndexMesh::generateIndexedBox(GLdouble l)
{
	//Creamos el mesh a devolver
	IndexMesh* mesh = new IndexMesh();
	GLdouble m = l * 0.5;
	//inicializamos los vertices de la malla
	mesh->mNumVertices = 8;
	mesh->vVertices.reserve(mesh->mNumVertices);
	mesh->vVertices.emplace_back(-m, m, m);//0
	mesh->vVertices.emplace_back(-m, -m, m);//1
	mesh->vVertices.emplace_back(m, m, m);//2
	mesh->vVertices.emplace_back(m, -m, m);//3
	mesh->vVertices.emplace_back(m, m, -m);//4
	mesh->vVertices.emplace_back(m, -m, -m);//5
	mesh->vVertices.emplace_back(-m, m, -m);//6
	mesh->vVertices.emplace_back(-m, -m, -m);//7

	mesh->mNumIndices = 36;
	mesh->vIndices = new GLuint[36]{
		2, 0, 4, 6, 4, 0,
		0, 3, 2, 1, 3, 0,
		2, 4, 3, 4, 5, 3,
		0, 7, 1, 0, 6, 7,
		5, 7, 1, 5, 1, 3,
		5, 7, 6, 6, 4, 5
	};

	//si comentas este bucle compruebas el correcto comportamiento de las normales

		//construimos las normales
	mesh->vNormals.reserve(mesh->mNumIndices);
	for (int i = 0; i < mesh->mNumVertices; i++)
		mesh->vNormals.emplace_back(0.0, 0.0, 0.0);

	for (int i = 0; i < mesh->mNumIndices; i += 3) {    // Obtener los índices del triángulo actual
		std::vector<GLuint> triangleIndices = {
			mesh->vIndices[i + 2],
			mesh->vIndices[i + 1],
			mesh->vIndices[i]
		};

		// Construir la normal de la cara del triángulo actual
		mesh->buildNormalVectors(mesh, triangleIndices);
	}

	return mesh;
}


void IndexMesh::buildNormalVectors(IndexMesh* mesh, std::vector<GLuint> C)
{
	//int numVertices = C.size();

	//glm::dvec3 vertActual = mesh->vVertices[C[0]];
	//glm::dvec3 vertSiguiente = mesh->vVertices[C[1]];
	//glm::dvec3 vertSiguiente2 = mesh->vVertices[C[2]];
	//glm::dvec3 v1 = vertActual - vertSiguiente;
	//glm::dvec3 v2 = vertSiguiente2 - vertSiguiente;
	//glm::dvec3 normal = glm::normalize(glm::cross(v1, v2));
	//mesh->vNormals[C[0]] = normal;



	glm::dvec3 n = glm::dvec3(0.0, 0.0, 0.0);
	int numVertices = C.size();

	// Calcular la normal de la cara usando el m�todo de Newell
	for (int i = 0; i < numVertices; i++)
	{
		glm::dvec3 vertActual = mesh->vVertices[C[i]];
		glm::dvec3 vertSiguiente = mesh->vVertices[C[(i + 1) % numVertices]];
		n.x += (vertActual.y - vertSiguiente.y) * (vertActual.z + vertSiguiente.z);
		n.y += (vertActual.z - vertSiguiente.z) * (vertActual.x + vertSiguiente.x);
		n.z += (vertActual.x - vertSiguiente.x) * (vertActual.y + vertSiguiente.y);
	}

	// Normalizar la normal calculada
	n = glm::normalize(n);
	mesh->vNormals[C[0]] = n;
}