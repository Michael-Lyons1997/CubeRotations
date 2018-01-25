#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	frontFace[0].setX(1.0f);
	frontFace[0].setY(1.0f);
	frontFace[0].setZ(-5.0f);

	frontFace[1].setX(-1.0f);
	frontFace[1].setY(1.0f);
	frontFace[1].setZ(-5.0f);

	frontFace[2].setX(-1.0f);
	frontFace[2].setY(-1.0f);
	frontFace[2].setZ(-5.0f);

	frontFace[3].setX(1.0f);
	frontFace[3].setY(-1.0f);
	frontFace[3].setZ(-5.0f);


	backFace[0].setX(1.0f);
	backFace[0].setY(1.0f);
	backFace[0].setZ(-10.0f);

	backFace[1].setX(-1.0f);
	backFace[1].setY(1.0f);
	backFace[1].setZ(-10.0f);

	backFace[2].setX(-1.0f);
	backFace[2].setY(-1.0f);
	backFace[2].setZ(-10.0f);

	backFace[3].setX(1.0f);
	backFace[3].setY(-1.0f);
	backFace[3].setZ(-10.0f);

	lSide[0].setX(-1.0f);
	lSide[0].setY(1.0f);
	lSide[0].setZ(-10.0f);

	lSide[1].setX(1.0f);
	lSide[1].setY(1.0f);
	lSide[1].setZ(-5.0f);

	lSide[2].setX(1.0f);
	lSide[2].setY(-1.0f);
	lSide[2].setZ(-5.0f);

	lSide[3].setX(1.0f);
	lSide[3].setY(-1.0f);
	lSide[3].setZ(-10.0f);

	rSide[0].setX(-1.0f);
	rSide[0].setY(1.0f);
	rSide[0].setZ(-10.0f);

	rSide[1].setX(-1.0f);
	rSide[1].setY(1.0f);
	rSide[1].setZ(-5.0f);

	rSide[2].setX(-1.0f);
	rSide[2].setY(-1.0f);
	rSide[2].setZ(-5.0f);

	rSide[3].setX(-1.0f);
	rSide[3].setY(-1.0f);
	rSide[3].setZ(-10.0f);

	topFace[0].setX(-1.0f);
	topFace[0].setY(1.0f);
	topFace[0].setZ(-5.0f);

	topFace[1].setX(1.0f);
	topFace[1].setY(1.0f);
	topFace[1].setZ(-5.0f);

	topFace[2].setX(-1.0f);
	topFace[2].setY(-1.0f);
	topFace[2].setZ(-10.0f);

	topFace[3].setX(-1.0f);
	topFace[3].setY(1.0f);
	topFace[3].setZ(-10.0f);

	bottomFace[0].setX(-1.0f);
	bottomFace[0].setY(-1.0f);
	bottomFace[0].setZ(-5.0f);

	bottomFace[1].setX(1.0f);
	bottomFace[1].setY(-1.0f);
	bottomFace[1].setZ(-5.0f);

	bottomFace[2].setX(1.0f);
	bottomFace[2].setY(-1.0f);
	bottomFace[2].setZ(-10.0f);

	bottomFace[3].setX(-1.0f);
	bottomFace[3].setY(-1.0f);
	bottomFace[3].setZ(-10.0f);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(frontFace[0].getX(), frontFace[0].getY(), frontFace[0].getZ());
		glVertex3f(frontFace[1].getX(), frontFace[1].getY(), frontFace[1].getZ());
		glVertex3f(frontFace[2].getX(), frontFace[2].getY(), frontFace[2].getZ());
		glVertex3f(frontFace[3].getX(), frontFace[3].getY(), frontFace[3].getZ());

		//left Side Face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(lSide[0].getX(), lSide[0].getY(), lSide[0].getZ());
		glVertex3f(lSide[1].getX(), lSide[1].getY(), lSide[1].getZ());
		glVertex3f(lSide[2].getX(), lSide[2].getY(), lSide[2].getZ());
		glVertex3f(lSide[3].getX(), lSide[3].getY(), lSide[3].getZ());

		//right Side Face
		glColor3f(0.0f, 0.5f, 1.0f);
		glVertex3f(rSide[0].getX(), rSide[0].getY(), rSide[0].getZ());
		glVertex3f(rSide[1].getX(), rSide[1].getY(), rSide[1].getZ());
		glVertex3f(rSide[2].getX(), rSide[2].getY(), rSide[2].getZ());
		glVertex3f(rSide[3].getX(), rSide[3].getY(), rSide[3].getZ());

		//Top Face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(topFace[0].getX(), topFace[0].getY(), topFace[0].getZ());
		glVertex3f(topFace[1].getX(), topFace[1].getY(), topFace[1].getZ());
		glVertex3f(topFace[2].getX(), topFace[2].getY(), topFace[2].getZ());
		glVertex3f(topFace[3].getX(), topFace[3].getY(), topFace[3].getZ());

		//Bottom Face
		glColor3f(1.0f, 0.5f, 0.5f);
		glVertex3f(bottomFace[0].getX(), bottomFace[0].getY(), bottomFace[0].getZ());
		glVertex3f(bottomFace[1].getX(), bottomFace[1].getY(), bottomFace[1].getZ());
		glVertex3f(bottomFace[2].getX(), bottomFace[2].getY(), bottomFace[2].getZ());
		glVertex3f(bottomFace[3].getX(), bottomFace[3].getY(), bottomFace[3].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(backFace[0].getX(), backFace[0].getY(), backFace[0].getZ());
		glVertex3f(backFace[1].getX(), backFace[1].getY(), backFace[1].getZ());
		glVertex3f(backFace[2].getX(), backFace[2].getY(), backFace[2].getZ());
		glVertex3f(backFace[3].getX(), backFace[3].getY(), backFace[3].getZ());

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

	}
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

