#include "DirLight.h"

void DirLight::upload(glm::dmat4 const& modelViewMat) const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));
	glLightfv(id, GL_POSITION, value_ptr(posDir));
	uploadL();
}

void DirLight::setPosDir(glm::fvec3 dir)
{
	posDir = glm::fvec4(dir, 0.0);

}
