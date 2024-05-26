#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class Light
{
protected:
	static GLuint cont; // Atributo para poder generar un nuevo id cada vez
	GLuint id = GL_LIGHT0 + GL_MAX_LIGHTS; // Primer id no v�lido

	// Atributos lum�nicos y geom�trico de la fuente de luz
	glm::fvec4 ambient = { 0.1 , 0.1 , 0.1 , 1 };
	glm::fvec4 diffuse = { 0.5 , 0.5 , 0.5 , 1 };
	glm::fvec4 specular = { 0.5 , 0.5 , 0.5 , 1 };
	glm::fvec4 posDir = { 0 , 0 , 1 , 0 };
	// A�ade setters para cambiar el valor de los atributos lum�nicos
public:
	Light();
	virtual ~Light() { disable(); }
	virtual void uploadL() const;
	// M�todo abstracto
	virtual void upload(glm::dmat4 const& modelViewMat) const = 0;
	void disable() { if (id < GL_LIGHT0 + GL_MAX_LIGHTS) glDisable(id); };
	void enable() { if (id < GL_LIGHT0 + GL_MAX_LIGHTS) glEnable(id); };
	void setAmb(glm::fvec4 amb) {
		ambient = amb; //uploadL();
	};
	void setDif(glm::fvec4 dif) {
		diffuse = dif; //uploadL();
	};
	void setSpec(glm::fvec4 spec) {
		specular = spec; //uploadL();
	};
};

