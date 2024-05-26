#pragma once
#include "Mesh.h"
class IndexMesh: public Mesh
{
protected:
	GLuint* vIndices = nullptr; // tabla de �ndices
	GLuint mNumIndices = 0;
	void buildNormalVectors(IndexMesh* mesh, std::vector<GLuint> C);

public:
	IndexMesh():Mesh() { mPrimitive = GL_TRIANGLES; }
	~IndexMesh() { delete[] vIndices; }
	virtual void render() const;
	virtual void draw() const;
	static IndexMesh* generateIndexedBox(GLdouble l);
	static IndexMesh* generateIndexedOctogone(GLdouble l, GLdouble h);
	static IndexMesh* generateIndexedPyramid(GLdouble l);
	static IndexMesh* generateIndexedPyramidTex(GLdouble l);
};

