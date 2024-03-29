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
#include "GlassParapet.h"
#include "Photo.h"
#include "Box.h"
#include "Grass.h"

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

	for (Abs_Entity* el : gObjectsTrans) {
		delete el;
		el = nullptr;
		gObjectsTrans.pop_back();
	}

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

	for (Abs_Entity* el : gObjectsTrans) {
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
	mId = id;
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

			grass = new Grass();
			t = new Texture();
			t->load("../bmps/grass.bmp", glm::u8vec3(0, 0, 0), 0.0);
			gTextures.push_back(t);
			grass->setTexture(t);
			gObjects.push_back(grass);

			photo = new Photo(200, 100);
			t1 = new Texture();
			t1->loadColorBuffer(200,100);
			photo->setTexture(t1);
			gTextures.push_back(t1);
			gObjects.push_back(photo);
			break;
		case 3:
			boxOutline = new BoxOutline(100);

			t = new Texture();
			t->load("../bmps/container.bmp", 1);
			gTextures.push_back(t);
			t2 = new Texture();
			t2->load("../bmps/papelE.bmp", 1);
			gTextures.push_back(t2);

			boxOutline->setTexture(gTextures[0]);
			boxOutline->setSecundaryTexture(gTextures[1]);
			gObjects.push_back(boxOutline);
			break;
		case 4:
			star = new Star3D(100,8,100);
			t = new Texture();
			t->load("../bmps/baldosaP.bmp", 1);
			gTextures.push_back(t);
			star->setTexture(gTextures[0]);
			gObjects.push_back(star);
			break;
		case 5:
			parapet = new GlassParapet(100);
			glm::dmat4 mb = glm::scale(parapet->modelMat(), dvec3(1, 0.5, 1));
			parapet->setModelMat(mb);
			t = new Texture();
			t->load("../bmps/windowV.bmp", 100);
			gTextures.push_back(t);
			parapet->setTexture(gTextures[0]);
			gObjectsTrans.push_back(parapet);
			break;
		case 6:
			box = new Box(100);

			t = new Texture();
			t->load("../bmps/container.bmp", 1);
			gTextures.push_back(t);
			t2 = new Texture();
			t2->load("../bmps/papelE.bmp", 1);
			gTextures.push_back(t2);

			box->setTexture(gTextures[0]);
			box->setTopsTexture(gTextures[0]);
			box->setSecundaryTexture(gTextures[1]);
			gObjects.push_back(box);
			break;
		case 7:
			ground = new Ground(150, 150);
			ground->setModelMat(glm::translate(ground->modelMat(), glm::dvec3(-25, -25, -50)));
			t = new Texture();
			t->load("../bmps/baldosaC.bmp", 1);
			gTextures.push_back(t);
			ground->setTexture(gTextures[0]);
			gObjects.push_back(ground);

			box = new Box(100);
			t1 = new Texture();
			t1->load("../bmps/container.bmp", 1);
			gTextures.push_back(t1);
			t2 = new Texture();
			t2->load("../bmps/papelE.bmp", 1);
			gTextures.push_back(t2);

			box->setTexture(t1);
			box->setTopsTexture(t1);
			box->setSecundaryTexture(t2);
			gObjects.push_back(box);

			parapet = new GlassParapet(150);
			parapet->setModelMat(glm::translate(parapet->modelMat(), glm::dvec3(-25, -10, 25)));
			glm::dmat4 mc = glm::scale(parapet->modelMat(), dvec3(1, 0.5, 1));
			parapet->setModelMat(mc);
			t3 = new Texture();
			t3->load("../bmps/windowV.bmp", 100);
			gTextures.push_back(t3);
			parapet->setTexture(t3);
			gObjectsTrans.push_back(parapet);

			star = new Star3D(50, 8, 50);
			star->setModelMat(glm::translate(star->modelMat(), glm::dvec3(0, 200, 0)));
			t4 = new Texture();
			t4->load("../bmps/baldosaP.bmp", 1);
			gTextures.push_back(t4);
			star->setTexture(t4);
			gObjects.push_back(star);

			grass = new Grass();
			t5 = new Texture();
			t5->load("../bmps/grass.bmp", glm::u8vec3(0, 0, 0), 0.0);
			gTextures.push_back(t5);
			grass->setTexture(t5);
			gObjects.push_back(grass);

			photo = new Photo(100, 100);
			t6 = new Texture();
			t6->loadColorBuffer(200, 100);
			photo->setTexture(t6);
			gTextures.push_back(t6);
			gObjects.push_back(photo);
			break;
		default:
				break;
	}
	ejesRGB = new EjesRGB(400.0);
	gObjects.push_back(ejesRGB);
}

void Scene::takePhoto()
{
	Texture* t = new Texture();
	t->loadColorBuffer(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	t->saveData("../bmps/Pachoclo.bmp");
	delete t;
}
