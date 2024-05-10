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
#include "Sphere.h"
#include "Cylinder.h"
#include "Disk.h"
#include "PartialDisk.h"
#include "AdvancedTIE.h"
#include "IndexedBox.h"
#include "NodeRGBTriangle.h"
#include "Tatooine.h"
#include "SphereBR.h"
#include "Toroid.h"
#include "Material.h"

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
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_NORMALIZE);
}

void
Scene::render(Camera const& cam) const
{
	sceneDirLight(cam);
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

void Scene::orbit()
{
	if (tatooine != nullptr)
		tatooine->orbit();
}

void Scene::rotate()
{
	if (tatooine != nullptr)
		tatooine->rotate();
}



void Scene::setScene(int id) {
	free();
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)
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

		case 8:
			sphere = new Sphere(200, 50, 50);
			sphere->setColor(glm::dvec4(1.0, 0.4, 0.0, 1.0));
			gObjects.push_back(sphere);
			partialDisk = new PartialDisk(150, 170, 50, 50, 90, 180);
			partialDisk->setColor(glm::dvec4(0.0, 1.0, 0.0, 1.0));
			glm::dmat4 me = glm::translate(dmat4(1.0), dvec3(0, 30, 150));
			partialDisk->setModelMat(me);
			gObjects.push_back(partialDisk);
			disk = new Disk(120, 170, 50, 50);
			disk->setColor(glm::dvec4(1.0, 0.0, 0.0, 0.0));
			me = glm::rotate(dmat4(1.0), radians(-90.0), dvec3(1.0, 0.0, 0));
			me = glm::translate(me, dvec3(0, 0, 150));
			disk->setModelMat(me);
			gObjects.push_back(disk);
			cylinder = new Cylinder(0.0, 20.0, 20.0, 50, 10);
			cylinder->setColor(glm::dvec4(0.0, 0.0, 1.0, 0.0));
			me = glm::rotate(dmat4(1.0), radians(-90.0), dvec3(0.0, 0.0, 1.0));
			me = glm::translate(me, dvec3(0, 30, 200));
			cylinder->setModelMat(me);
			gObjects.push_back(cylinder);
			cylinder = new Cylinder(0.0, 20.0, 20.0, 50, 10);
			cylinder->setColor(glm::dvec4(0.5, 0.5, 1.0, 0.0));
			me = glm::rotate(dmat4(1.0), radians(-90.0), dvec3(0.0, 0.0, 1.0));
			me = glm::translate(me, dvec3(0, -30, 200));
			cylinder->setModelMat(me);
			gObjects.push_back(cylinder);
			break;
		case 9:

			glClearColor(0.0, 0.0, 0.0, 1.0); // background color (alpha=1 -> opaque)
			tie = new AdvancedTIE(); 
			t2 = new Texture();
			t2->load("../bmps/noche.bmp",100);
			tie->setWingsTexture(t2);
			gTextures.push_back(t2);
			gObjectsTrans.push_back(tie);
			break;
		case 10:
			indexBox = new IndexedBox(100);
			indexBox->setMColor(glm::dvec4(0.0, 1.0, 0.0, 0.0));
			gObjectsTrans.push_back(indexBox);
			break;
		case 11:
			nodeTrianle = new NodeRGBTriangle(40);
			gObjects.push_back(nodeTrianle);
			break;
		case 12:
			glClearColor(0.0, 0.0, 0.0, 1.0); // background color (alpha=1 -> opaque)
			tatooine = new Tatooine();
			t2 = new Texture();
			t2->load("../bmps/noche.bmp", 100);
			tatooine->setWingsTexture(t2);
			gTextures.push_back(t2);
			gObjects.push_back(tatooine);
			break;
		case 13:
			spherebr = new SphereBR(200,60,60);
			spherebr->setMColor(glm::dvec4(0, 0, 1,1));
			gObjects.push_back(spherebr);
			break;
		case 14:
			toroid = new Toroid(100, 200, 60, 60);
			toroid->setMColor(glm::dvec4(0, 1, 0, 1));
			gObjects.push_back(toroid);
			break;
		case 15:
			spherebr = new SphereBR(100, 60, 60);
			spherebr->setMColor(glm::dvec4(1, 0.9, 0, 1));
			material = new Material();
			material->setGold();
			spherebr->setMaterial(material);
			spherebr->setModelMat(glm::translate(spherebr->modelMat(), glm::dvec3(200, 0, 0)));
			gObjects.push_back(spherebr);
			spherebr = new SphereBR(100, 60, 60);
			spherebr->setMColor(glm::dvec4(1, 0.9, 0, 1));
			spherebr->setModelMat(glm::translate(spherebr->modelMat(), glm::dvec3(0, 0, 200)));
			gObjects.push_back(spherebr);
			break;
		case 16:
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

void Scene::sceneDirLight(Camera const& cam) const {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glm::fvec4 posDir = { 1, 1, 1, 0 };
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(cam.viewMat()));
	glLightfv(GL_LIGHT0, GL_POSITION, value_ptr(posDir));
	glm::fvec4 ambient = { 0, 0, 0, 1 };
	glm::fvec4 diffuse = { 1, 1, 1, 1 };
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, value_ptr(ambient));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, value_ptr(diffuse));
	glLightfv(GL_LIGHT0, GL_SPECULAR, value_ptr(specular));
}
