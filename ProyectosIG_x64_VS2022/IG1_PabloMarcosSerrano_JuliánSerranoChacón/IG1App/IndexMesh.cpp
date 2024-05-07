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

	for (int i = 0; i < mesh->mNumIndices; i = i + 3) {
		std::vector<GLuint> cara;
		cara.push_back(mesh->vIndices[i]);
		cara.push_back(mesh->vIndices[i + 1]);
		cara.push_back(mesh->vIndices[i + 2]);
		mesh->buildNormalVectors(mesh, cara);
	}

	return mesh;
}


void IndexMesh::buildNormalVectors(IndexMesh* mesh, std::vector<GLuint> C)
{
	glm::dvec3 n = glm::dvec3(0.0, 0.0, 0.0);
	int numVertices = C.size();

	// Calcular la normal de la cara usando el método de Newell
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
	// Asignar la normal a cada vértice de la cara
	for (int i = 0; i < numVertices; i++)
	{
		mesh->vNormals.push_back(n);
		std::cout << " normal" << n.x << " " << n.y << " " << n.z << std::endl;
	}
}