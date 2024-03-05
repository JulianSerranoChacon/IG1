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
#include "Star3D.h"

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures
}
void
Scene::free()
{ // release memory and resources

	for (Abs_Entity* el : gObjects) {
		delete el;
		el = nullptr;
		gObjects.pop_back();
	}

	for (Texture* el : gTextures) {
		delete el;
		el = nullptr;
		gTextures.pop_back();
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

			t1 = new Texture();
			t1->load("../bmps/baldosaC.bmp", 1);
			gTextures.push_back(t1);

			ground->setTexture(gTextures[0]);
			gObjects.push_back(ground);
			break;
		case 3:
			box = new BoxOutline(100);

			t = new Texture();
			t->load("../bmps/container.bmp", 1);
			gTextures.push_back(t);
			t2 = new Texture();
			t2->load("../bmps/papelE.bmp", 1);
			gTextures.push_back(t2);

			box->setTexture(gTextures[0]);
			box->setSecundaryTexture(gTextures[1]);
			gObjects.push_back(box);
			break;
		case 4:
			star = new Star3D(100,6,100);
			gObjects.push_back(star);
			break;
		default:
				break;
	}
	ejesRGB = new EjesRGB(400.0);
	gObjects.push_back(ejesRGB);
}
