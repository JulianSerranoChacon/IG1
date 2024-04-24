#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Entity.h"

#include <vector>
class RGBTriangle;
class RGBRectange;
class RegularPolygon;
class RGBCube;
class Ground;
class BoxOutline;
class Star3D;
class GlassParapet;
class Photo;
class Box;
class Grass;
class Sphere;
class Cylinder;
class Disk;
class PartialDisk;
class WingAdvanceTIE;
class AdvancedTIE;
class IndexedBox;
class NodeRGBTriangle;
class Tatooine;

class Scene
{
private:
	RGBTriangle* triangleRGB = nullptr;
	RGBRectange* rectangle = nullptr;
	RegularPolygon* circle = nullptr;
	RGBCube* cubeRGB = nullptr;
	EjesRGB* ejesRGB = nullptr;
	Ground* ground = nullptr;
	BoxOutline* boxOutline = nullptr;
	Texture* t = nullptr;
	Texture* t1 = nullptr;
	Texture* t2 = nullptr;
	Texture* t3 = nullptr;
	Texture* t4 = nullptr;
	Texture* t5 = nullptr;
	Texture* t6 = nullptr;
	Star3D* star = nullptr;
	GlassParapet* parapet = nullptr;
	Photo* photo = nullptr;
	Box* box = nullptr;
	Grass* grass = nullptr;
	Sphere* sphere = nullptr;
	Cylinder* cylinder = nullptr;
	Disk* disk = nullptr;
	PartialDisk* partialDisk = nullptr;
	AdvancedTIE* tie = nullptr;
	IndexedBox* indexBox = nullptr;
	NodeRGBTriangle* nodeTrianle = nullptr;
	Tatooine* tatooine = nullptr;

	const int r= 200;

public:
	Scene() = default;
	~Scene()
	{
		free();
		resetGL();
	};

	Scene(const Scene& s) = delete;            // no copy constructor
	Scene& operator=(const Scene& s) = delete; // no copy assignment

	void init();

	void render(Camera const& cam) const;
	void update();
	void orbit();
	void rotate();

	void setScene(int);
	int getScene() const {return mId;};

	void takePhoto();
	void freeScene() { free(); };
	void sceneDirLight(Camera const& cam) const;
protected:
	void free();
	void setGL();
	void resetGL();

	std::vector<Abs_Entity*> gObjects; // Entities (graphic objects) of the scene
	std::vector<Abs_Entity*> gObjectsTrans; // Entities (graphic objects) of the scene transparentes
	std::vector <Texture* > gTextures; //Texturas de los objetos

	int mId;
};

#endif //_H_Scene_H_
