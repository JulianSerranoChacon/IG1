#pragma once
#include "IndexMesh.h"

class MbR: public IndexMesh
{
public:
	MbR(int n, glm::dvec3* perfil, int m);
	virtual ~MbR();
	static MbR* generaIndexMbR(int mm, int nn, glm::dvec3* perfil);

	static MbR* generaIndexMbRIncompleto(int mm, int nn, glm::dvec3* perfil);

protected:
	int n_; //para el número de muestras que se toman al girar el pefil alrededor del eje y
	glm::dvec3* perfil_; //para el array de vértices que define el perfil que va a hacerse girar alrededor del eje y
	int m_;  //para el número de puntos del perfil
};

