#include "IG1App.h"
#include "CheckML.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

// static single instance (singleton pattern)

IG1App IG1App::s_ig1app; // default constructor (constructor with no parameters)

void
IG1App::close()
{
	if (!mStop) { // if main loop has not stopped
		cout << "Closing glut...\n";
		glutLeaveMainLoop(); // stops main loop and destroy the OpenGL context
		mStop = true;        // main loop stopped
	}
	free();
}

void
IG1App::run() // enters the main event processing loop
{
	if (mWinId == 0) {      // if not initialized
		init();         // initialize the application
		glutMainLoop(); // enters the main event processing loop
		mStop = true;   // main loop has stopped
	}
}

void
IG1App::init()
{
	// create an OpenGL Context
	iniWinOpenGL();

	// create the scene after creating the context
	// allocate memory and resources
	mViewPort =
	  new Viewport(mWinW, mWinH); // glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)
	mCamera = new Camera(mViewPort);
	mCamera2 = new Camera(mViewPort);
	mScene = new Scene;
	mScene2 = new Scene;

	mCamera->set2D();
	mCamera2->set2D();
	mScene->init();
	mScene2->init();
}

void
IG1App::iniWinOpenGL()
{ // Initialization
	cout << "Starting glut...\n";
	int argc = 0;
	glutInit(&argc, nullptr);

	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); // GLUT_CORE_PROFILE
	glutInitContextFlags(GLUT_DEBUG);                   // GLUT_FORWARD_COMPATIBLE

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitWindowSize(mWinW, mWinH); // window size
	// glutInitWindowPosition (140, 140);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |
	                    GLUT_DEPTH /*| GLUT_STENCIL*/); // RGBA colors, double buffer, depth
	                                                    // buffer and stencil buffer

	mWinId = glutCreateWindow(
	  "IG1App"); // with its associated OpenGL context, return window's identifier

	// Callback registration
	glutReshapeFunc(s_resize);

	glutIdleFunc(update);

	glutKeyboardFunc(s_key);
	glutSpecialFunc(s_specialKey);
	glutDisplayFunc(s_display);

	glutMouseFunc(s_mouse); 
	glutMotionFunc(s_motion);
	glutMouseWheelFunc(s_mouseWheel);

	cout << glGetString(GL_VERSION) << '\n';
	cout << glGetString(GL_VENDOR) << '\n';
}

void
IG1App::free()
{ // release memory and resources
	delete mScene;
	mScene = nullptr;
	delete mScene2;
	mScene2 = nullptr;
	delete mCamera;
	mCamera = nullptr;
	delete mCamera2;
	mCamera2 = nullptr;
	delete mViewPort;
	mViewPort = nullptr;
}

void
IG1App::display() const
{ // double buffering

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the back buffer
	if (m2Scenes)
		s_ig1app.display2VS();
	else if (m2Vistas)
		s_ig1app.display2V();
	else
		mScene->render(*mCamera); // uploads the viewport and camera to the GPU

	glutSwapBuffers(); // swaps the front and back buffer
}

void
IG1App::resize(int newWidth, int newHeight)
{
	mWinW = newWidth;
	mWinH = newHeight;

	// Resize Viewport to the new window size
	mViewPort->setSize(newWidth, newHeight);

	// Resize Scene Visible Area such that the scale is not modified
	mCamera->setSize(mViewPort->width(), mViewPort->height());
}

void
IG1App::key(unsigned char key, int x, int y)
{
	bool need_redisplay = true;

	Camera* cam = mCamera;
	if (m2Scenes && mMouseCoord.x > mWinW / 2)
		cam = mCamera2;
	
	Scene* s = mScene;
	if (m2Scenes && mMouseCoord.x > mWinW / 2)
		s = mScene2;

	switch (key) {
		case 27:                     // Escape key
			glutLeaveMainLoop(); // stops main loop and destroy the OpenGL context
			break;
		case '+':
			mCamera->setScale(+0.01); // zoom in  (increases the scale)
			break;
		case '-':
			mCamera->setScale(-0.01); // zoom out (decreases the scale)
			break;
		case 'l':
			mCamera->set3D();
			break;
		case 'o':
			mCamera->set2D();
			break;
		case '0':
			mScene->setScene(0);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->changeProjMat();
			mCamera->set2D();
			break;
		case '1':
			mScene->setScene(1);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '2':
			mScene->setScene(2);
			shouldUpdate = false;

			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '3':
			mScene->setScene(3);
			shouldUpdate = false;

			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '4':
			mScene->setScene(4);
			shouldUpdate = false;

			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '5':
			mScene->setScene(5);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '6':
			mScene->setScene(6);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '7':
			mScene->setScene(7);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '8':
			mScene->setScene(8);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case '9':
			mScene->setScene(9);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'=':
			mScene->setScene(10);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'!':
			mScene->setScene(11);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set2D();
			break;
		case'"':
			mScene->setScene(12);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'#':
			mScene->setScene(13);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'$':
			mScene->setScene(14);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'%':
			mScene->setScene(15);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case'&':
			mScene->setScene(16);
			shouldUpdate = false;
			mCamera->resetProjMat();
			mCamera->set3D();
			break;
		case 'p':

			cam->changePrj();
			break;
		case 'u':

			if (!s_ig1app.shouldUpdate)
				s->update();

			if(s->getScene() == 0)
				cam->update();
			break;
		case 'g':
			//if (!s_ig1app.shouldUpdate)
				//mCamera->orbit(10, 0);

			s->orbit();
			break;

		case 'k':
			m2Vistas = !m2Vistas;
			break;
		case 'K':
			if (!m2Scenes) {
				mScene->setScene(5);
				mScene2->setScene(0);
			}
			else {
				mScene2->freeScene();
			}
			m2Scenes = !m2Scenes;
			break;
		case 'f':
			s->rotate();
			break;
		case 'F':
			mScene->takePhoto();
			break;
		case 'U':
			if(!shouldUpdate)
				shouldUpdate = true;
			else
				shouldUpdate = false;
			break;
		case 'q':
			mScene->turnOnDirLight();
			break;
		case 'w':
			mScene->turnOffDirLight();
			break;
		case 'a':
			mScene->turnOnPosLight();
			break;
		case 's':
			mScene->turnOffPosLight();
			break;
		case 'z':
			mScene->turnOnSpotLight();
			break;
		case 'x':
			mScene->turnOffSpotLight();
			break;
		case 'v':
			mScene->turnOnSpotLightTie();
			break; 
		case 'b':
			mScene->turnOffSpotLightTie();
			break;
		default:
			need_redisplay = false;
			break;
	} // switch

	if (need_redisplay)
		glutPostRedisplay(); // marks the window as needing to be redisplayed -> calls to
		                     // display()
}

void
IG1App::specialKey(int key, int x, int y)
{
	bool need_redisplay = true;
	int mdf = glutGetModifiers(); // returns the modifiers (Shift, Ctrl, Alt)

	switch (key) {
		case GLUT_KEY_RIGHT:
			if (mdf == GLUT_ACTIVE_CTRL)
				mCamera->pitch(-1); // rotates -1 on the X axis
				//mCamera->moveLR(-1);
				//mCamera->rollReal(1);
			else
				mCamera->pitch(1); // rotates 1 on the X axis
				//moveLR(1);
				//mCamera->rollReal(-1);
			break;
		case GLUT_KEY_LEFT:
			if (mdf == GLUT_ACTIVE_CTRL)
				mCamera->yaw(1); // rotates 1 on the Y axis
				//mCamera->moveUD(1);
				//mCamera->yawReal(1);
			else
				mCamera->yaw(-1); // rotate -1 on the Y axis
				//mCamera->moveUD(-1);
				//mCamera->yawReal(-1);
			break;
		case GLUT_KEY_UP:
			mCamera->roll(1); // rotates 1 on the Z axis
			//mCamera->moveFB(1);
			//mCamera->pitchReal(-1);
			break;
		case GLUT_KEY_DOWN:
			mCamera->roll(-1); // rotates -1 on the Z axis
			//mCamera->moveFB(-1);
			//mCamera->pitchReal(1);
			break;
		default:
			need_redisplay = false;
			break;
	} // switch

	if (need_redisplay)
		glutPostRedisplay(); // marks the window as needing to be redisplayed -> calls to
		                     // display()
}

void IG1App::display2V()
{
	Camera auxCam = *mCamera;
	Viewport auxVP = *mViewPort;
	mViewPort->setSize(mWinW / 2, mWinH);
	auxCam.setSize(mViewPort->width(), mViewPort->height());
	mScene->render(auxCam);
	mViewPort->setPos(mWinW / 2, 0);
	auxCam.setCenital();
	mScene->render(auxCam);

	*mViewPort = auxVP; // * restaurar el puerto de vista ( NOTA )
}

void IG1App::display2VS()
{
	Camera auxCam = *mCamera;
	Camera auxCam2 = *mCamera2;
	Viewport auxVP = *mViewPort;
	mViewPort->setSize(mWinW / 2, mWinH);
	auxCam.setSize(mViewPort->width(), mViewPort->height());
	mScene->render(auxCam);
	mViewPort->setPos(mWinW / 2, 0);
	auxCam2.setSize(mViewPort->width(), mViewPort->height());
	mScene2->render(auxCam2);

	*mViewPort = auxVP; // * restaurar el puerto de vista ( NOTA )
}

void IG1App::mouse(int button, int state, int x, int y)
{
	mMouseButton = button;
	mMouseCoord = glm::dvec2(x, y);
}

void IG1App::motion(int x, int y)
{
	Camera* Cam = mCamera;

	if (m2Scenes && x > mWinW / 2)
		Cam = mCamera2;

	if (mMouseButton == GLUT_RIGHT_BUTTON) {
		Cam->moveLR(mMouseCoord.x - x);
		Cam->moveUD(mMouseCoord.x - x);
	}
	else if (mMouseButton == GLUT_LEFT_BUTTON) {
		Cam->orbit((mMouseCoord.x - x) * 0.7, mMouseCoord.y - y);
	}


	mMouseCoord = glm::dvec2(x, y);
	glutPostRedisplay();
}

void IG1App::mouseWheel(int n, int d, int x, int y)
{
	Camera* Cam = mCamera;

	if (m2Scenes && x > mWinW / 2)
		Cam = mCamera2;

	int auxmodifiers = glutGetModifiers();

	if (auxmodifiers == GLUT_ACTIVE_CTRL) {
		Cam->setScale(d * 0.01);
	}
	else if (auxmodifiers == 0) {
		Cam->moveFB(d * 5 );
	}

	glutPostRedisplay();
}

void IG1App::update()
{
	Scene* s = s_ig1app.s_ig1app.mScene;
	if(s_ig1app.m2Scenes && s_ig1app.mMouseCoord.x > s_ig1app.mWinW/2)
		s = s_ig1app.s_ig1app.mScene2;

	if (s_ig1app.shouldUpdate) {
		//Como en cada procesador es distinto he comentado un delay del update para que en nuestros ordenadores no fuese demasiado rápido

		if (s_ig1app.delay <= s_ig1app.currentDelay) {
			s->update();
			glutPostRedisplay();
			s_ig1app.currentDelay = 0;
		}
		else
		s_ig1app.currentDelay++;
	}
}