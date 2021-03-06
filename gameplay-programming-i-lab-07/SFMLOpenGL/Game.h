#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix.h"
#include "Vector.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void updatePos();
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	Matrix newmat;
	Vector frontFace[4];
	Vector backFace[4];
	Vector topFace[4];
	Vector bottomFace[4];
	Vector lSide[4];
	Vector rSide[4];
	GLuint index;
	Clock clock;
	Time elapsed;
	bool translate = false;
	bool rotate = false;
	bool scale = false;
	int scaleint = 0;
	float rotationAngle = 0.0f;
};