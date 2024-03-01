#include "Scene.h"
#include "CheckML.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RegularPolygon.h"
#include "RGBTriangle.h"
#include "RGBRectange.h"
#include "Cube.h"
#include "RGBCube.h"
#include "Ground.h"
#include "BoxOutline.h"

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	/*RegularPolygon* triangle = new RegularPolygon(3, 200);
	triangle->setMColor(glm::dvec4(0.0, 255.0, 255.0, 1.0));
	gObjects.push_back(triangle);*/

	/*RGBTriangle* treiangleRGB = new RGBTriangle(150);
	treiangleRGB->setMColor(glm::dvec4(0.0, 255.0, 255.0, 1.0));
	gObjects.push_back(treiangleRGB);*/

	//RGBRectange* rectangle = new RGBRectange(100, 200);
	//gObjects.push_back(rectangle);

	//Cube* cube = new Cube(200);
	//gObjects.push_back(cube);

	//RegularPolygon* circle = new RegularPolygon(100, 200);
	//circle->setMColor(glm::dvec4(255.0, 0.0, 255.0, 1.0));
	//gObjects.push_back(circle);

	//RGBCube* cubeRGB = new RGBCube(200);
	//gObjects.push_back(cubeRGB);

	//gObjects.push_back(new EjesRGB(400.0));

	//setScene(0);
}
void
Scene::free()
{ // release memory and resources

	for (Abs_Entity* el : gObjects) {
		delete el;
		el = nullptr;
		gObjects.pop_back();
	}
}
void
Scene::setGL()
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);          // enable Depth test
	glEnable(GL_TEXTURE_2D);
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
	glDisable(GL_TEXTURE_2D);
}

void
Scene::render(Camera const& cam) const
{
	cam.upload();

	for (Abs_Entity* el : gObjects) {
		el->render(cam.viewMat());
	}
}

void Scene::update()
{
	for (Abs_Entity* el : gObjects) {
		el->update();
	}
}

void Scene::setScene(int id) {
	free();
	switch (id) {
		case 0:
			triangleRGB = new RGBTriangle(50);
			triangleRGB->setMColor(glm::dvec4(0.0, 255.0, 255.0, 1.0));
			triangleRGB->setMr(r);
			glm::dmat4 m = glm::translate(triangleRGB->modelMat(), dvec3(r, 0, 0));
			triangleRGB->setModelMat(m);
			gObjects.push_back(triangleRGB);

			rectangle = new RGBRectange(100, 150);
			gObjects.push_back(rectangle);

			circle = new RegularPolygon(200, r);
			circle->setMColor(glm::dvec4(0.0, 255.0, 255.0, 1.0));
			gObjects.push_back(circle);
			break;
		case 1:
			cubeRGB = new RGBCube(100);
			glm::dmat4 ma = glm::translate(cubeRGB->modelMat(), dvec3(50, 50, -50));
			cubeRGB->setModelMat(ma);
			gObjects.push_back(cubeRGB);
			break;
		case 2:
			ground = new Ground(150, 150);
			gObjects.push_back(ground);
			break;
		case 3:
			box = new BoxOutline(100);
			gObjects.push_back(box);
			break;
		default:
				break;
	}
	ejesRGB = new EjesRGB(400.0);
	gObjects.push_back(ejesRGB);
}
