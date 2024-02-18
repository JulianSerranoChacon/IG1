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


class Scene
{
private:
	RGBTriangle* triangleRGB = nullptr;
	RGBRectange* rectangle = nullptr;
	RegularPolygon* circle = nullptr;
	RGBCube* cubeRGB = nullptr;
	EjesRGB* ejesRGB = nullptr;
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

	void setScene(int);

protected:
	void free();
	void setGL();
	void resetGL();

	std::vector<Abs_Entity*> gObjects; // Entities (graphic objects) of the scene

	int mId;
};

#endif //_H_Scene_H_
