#include "IndexMesh.h"

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

		// Nuevos comandos para la tabla de �ndices
		if (vIndices != nullptr) {
			glEnableClientState(GL_INDEX_ARRAY);
			glIndexPointer(GL_UNSIGNED_INT, 0, vIndices);
		}

		draw();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);

		// Nuevo comando para la tabla de �ndices :
		glDisableClientState(GL_INDEX_ARRAY);
	}
}

// Comando para renderizar la malla indexada enviada
void IndexMesh::draw() const {
	glDrawElements(mPrimitive, nNumIndices,
		GL_UNSIGNED_INT, vIndices);

}

IndexMesh* IndexMesh::generateIndexedBox(GLdouble l)
{
	//Creamos el mesh a devolver
	IndexMesh* mesh = new IndexMesh();
	GLdouble m = l / 2.0;
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

	mesh->nNumIndices = 36;
	mesh->vIndices = new GLuint[36]{ 0, 1, 2, 1, 3, 2, 2, 3, 4, 
		3, 5, 4, 4, 5, 6, 5, 7, 6,
		6, 7, 0, 7, 1, 0, 
		0, 2, 4, 4, 6, 0,
		1, 5, 3, 1, 7, 5
	};

	//si comentas este bucle compruebas el correcto comportamiento de las normales

	for (int i = 0; i < mesh->nNumIndices; i = i + 3) {
		std::vector<GLuint> cara;
		cara.push_back(mesh->vIndices[i]);
		cara.push_back(mesh->vIndices[i + 1]);
		cara.push_back(mesh->vIndices[i + 2]);
		mesh->calculoVectorNormalPorNewell(mesh, cara);
	}

	return mesh;
}


void IndexMesh::calculoVectorNormalPorNewell(IndexMesh* mesh, std::vector<GLuint> C)
{
	glm::dvec3 n = glm::dvec3(0, 0, 0);
	for (int i = 0; i < C.size(); i++)
	{
		glm::dvec3 vertActual = mesh->vVertices[C[i]];
		glm::dvec3 vertSiguiente = mesh->vVertices[C[(i + 1) % C.size()]];
		n.x += (vertActual.y - vertSiguiente.y) * (vertActual.z + vertSiguiente.z);
		n.y += (vertActual.z - vertSiguiente.z) * (vertActual.x + vertSiguiente.x);
		n.z += (vertActual.x - vertSiguiente.x) * (vertActual.y + vertSiguiente.y);
	}
	mesh->vNormals.push_back(glm::normalize(n));
}