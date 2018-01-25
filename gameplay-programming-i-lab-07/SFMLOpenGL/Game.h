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
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	Vector frontFace[4];
	Vector backFace[4];
	Vector topFace[4];
	Vector bottomFace[4];
	Vector lSide[4];
	Vector rSide[4];
	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};