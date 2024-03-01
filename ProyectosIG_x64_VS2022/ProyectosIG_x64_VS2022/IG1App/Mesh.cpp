#include "Mesh.h"
#include "CheckML.h"
#include <fstream>
#include "Texture.h"
using namespace std;
using namespace glm;

void
Mesh::draw() const
{
	glDrawArrays(
	  mPrimitive,
	  0,
	  size()); // primitive graphic, first index and number of elements to be rendered
}

Mesh* Mesh::generateRegularPolygon(GLuint num, GLdouble r)
{
	//Creamos el mesh a devolver
	Mesh* mesh = new Mesh();
	//Desde dónde queremos emprezar (ángulo)
	float alpha = 90;
	//inicializamos los vertices de la malla
	mesh->mNumVertices = num;
	mesh->vVertices.reserve(mesh->mNumVertices);

	//creaos polígono
	for (int i = 0; i < mesh->mNumVertices; i++) {
		mesh->vVertices.emplace_back(r * cos(radians(alpha)), r * sin(radians(alpha)), 0);
		alpha += 360.0/ num;
	}
	//guardamos primitiva
	mesh->mPrimitive = GL_LINE_LOOP;
	return mesh;
}

Mesh* Mesh::generateRGBTriangle(GLdouble r)
{
	//Creamos el mesh a devolver
	Mesh* mesh = generateRegularPolygon(3, r);

	mesh->vColors.reserve(mesh->mNumVertices);

	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	//guardamos primitiva
	mesh->mPrimitive = GL_TRIANGLES;
	return mesh;
}

Mesh* Mesh::generateRectangle(GLdouble w, GLdouble h)
{
	//Creamos el mesh a devolver
	Mesh* mesh = new Mesh();
	//Desde dónde queremos emprezar (ángulo)

	//inicializamos los vertices de la malla
	mesh->mNumVertices = 4;
	mesh->vVertices.reserve(mesh->mNumVertices);

	mesh->vVertices.emplace_back(-w*0.5, -h*0.5, 0.0);
	mesh->vVertices.emplace_back(w * 0.5, -h * 0.5, 0.0);
	mesh->vVertices.emplace_back(-w * 0.5, h * 0.5, 0.0);
	mesh->vVertices.emplace_back(w * 0.5, h * 0.5, 0.0);

	//guardamos primitiva
	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	return mesh;
}

Mesh* Mesh::generateRGBRectangle(GLdouble w, GLdouble h)
{
	//Creamos el mesh a devolver
	Mesh* mesh = generateRectangle(w, h);

	mesh->vColors.reserve(mesh->mNumVertices);

	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

Mesh* Mesh::generateCube(GLdouble lenght)
{

	//Creamos el mesh a devolver
	Mesh* mesh = new Mesh();
	GLdouble m = lenght / 2.0;
	//inicializamos los vertices de la malla
	mesh->mNumVertices = 36;
	mesh->vVertices.reserve(mesh->mNumVertices);

	mesh->vVertices.emplace_back(-m, -m, -m);//0
	mesh->vVertices.emplace_back(m, -m, -m);//1
	mesh->vVertices.emplace_back(m, -m, m);//2
	mesh->vVertices.emplace_back(-m, -m, -m);//0
	mesh->vVertices.emplace_back(m, -m, m);//2
	mesh->vVertices.emplace_back(-m, -m, m);//3

	mesh->vVertices.emplace_back(-m, -m, m);//3
	mesh->vVertices.emplace_back(-m, m, m);//4
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(-m, -m, m);//3
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(-m, -m, -m);//0

	mesh->vVertices.emplace_back(-m, -m, -m);//0
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(m, -m, -m);//1
	mesh->vVertices.emplace_back(m, -m, -m);//1
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(m, m, -m);//6

	mesh->vVertices.emplace_back(-m, m, m);//4
	mesh->vVertices.emplace_back(m, m, -m);//6	
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(-m, m, m);//4
	mesh->vVertices.emplace_back(m, m, m);//7
	mesh->vVertices.emplace_back(m, m, -m);//6	

	mesh->vVertices.emplace_back(m, m, -m);//6	
	mesh->vVertices.emplace_back(m, m, m);//7
	mesh->vVertices.emplace_back(m, -m, -m);//1
	mesh->vVertices.emplace_back(m, -m, -m);//1
	mesh->vVertices.emplace_back(m, m, m);//7
	mesh->vVertices.emplace_back(m, -m, m);//2

	mesh->vVertices.emplace_back(m, -m, m);//2
	mesh->vVertices.emplace_back(m, m, m);//7
	mesh->vVertices.emplace_back(-m, -m, m);//3
	mesh->vVertices.emplace_back(m, m, m);//7
	mesh->vVertices.emplace_back(-m, m, m);//4
	mesh->vVertices.emplace_back(-m, -m, m);//3


	mesh->mPrimitive = GL_TRIANGLES;

	return mesh;
}

Mesh* Mesh::generateRGBCubeTriangles(GLdouble lenght)
{
	//Creamos el mesh a devolver
	Mesh* mesh = generateCube(lenght);

	mesh->vColors.reserve(mesh->mNumVertices);
	int x, y, z;

	for (int i = 0; i < 6; i++) {
		y = (i % 3) % 2;
		z = ((i + 1) % 3) % 2;
		x = ((i + 2) % 3) % 2;
		for (int j = 0; j < 6; j++) {
			mesh->vColors.emplace_back(x, y, z, 1.0);
		}
	}

	return mesh;
}

Mesh* Mesh::generateRectangleTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh)
{
	//Creamos el mesh a devolver
	Mesh* mesh = generateRectangle(w, h);

	mesh->vTexCoords.reserve(mesh->mNumVertices);
	mesh->vTexCoords.emplace_back(glm::dvec2(0, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(0, 1 * rw));
	mesh->vTexCoords.emplace_back(glm::dvec2(1 * rh, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(1 * rh, 1 * rw));


	
	return mesh;
}

Mesh* Mesh::generateBoxOutline(GLdouble length)
{
	//Creamos el mesh a devolver
	Mesh* mesh = new Mesh();
	GLdouble m = length / 2.0;
	//inicializamos los vertices de la malla
	mesh->mNumVertices = 10;
	mesh->vVertices.reserve(mesh->mNumVertices);

	mesh->vVertices.emplace_back(m, m, m);//1
	mesh->vVertices.emplace_back(m, -m, m); //0
	mesh->vVertices.emplace_back(m, m, -m);//3
	mesh->vVertices.emplace_back(m, -m, -m);//2
	mesh->vVertices.emplace_back(-m, m, -m);//5
	mesh->vVertices.emplace_back(-m, -m, -m);//4
	mesh->vVertices.emplace_back(-m, m, m);//7
	mesh->vVertices.emplace_back(-m, -m, m);//6
	mesh->vVertices.emplace_back(m, m, m);//9
	mesh->vVertices.emplace_back(m, -m, m);//8

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	return mesh;
}

Mesh* Mesh::generateBoxOutlineTexCor(GLdouble longitud)
{
	//Creamos el mesh a devolver
	Mesh* mesh = Mesh::generateBoxOutline(longitud);

	mesh->vTexCoords.reserve(mesh->mNumVertices);
	mesh->vTexCoords.emplace_back(glm::dvec2(0, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(0, 1));
	mesh->vTexCoords.emplace_back(glm::dvec2(1, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(1, 1));

	mesh->vTexCoords.emplace_back(glm::dvec2(2, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(2, 1));
	mesh->vTexCoords.emplace_back(glm::dvec2(3, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(3, 1));

	mesh->vTexCoords.emplace_back(glm::dvec2(4, 0));
	mesh->vTexCoords.emplace_back(glm::dvec2(4, 1));

	return mesh;
}



void
Mesh::render() const
{
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

		draw();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

Mesh*
Mesh::createRGBAxes(GLdouble l)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_LINES;

	mesh->mNumVertices = 6;
	mesh->vVertices.reserve(mesh->mNumVertices);

	// X axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(l, 0.0, 0.0);
	// Y axis vertices
	mesh->vVertices.emplace_back(0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, l, 0.0);
	// Z axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, 0.0, l);

	mesh->vColors.reserve(mesh->mNumVertices);
	// X axis color: red  (Alpha = 1 : fully opaque)
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}
