#include "stdafx.h"
#include "stb_image.c"
#include "glut.h"
#include "math.h"
#include "Tank1.h"
#include "Tank2.h"
#include "Tank3.h"
#include "TankParts.h"
#include "Environment.h"
#include "EnvironmentItems.h"

void loadImages(void);
void loadTexture(char*, int);
void axis(double);
void display(void);
void animate(int);
void keyboard(unsigned char, int, int);
void keyboardSpecial (int, int, int);
void mouse(int, int, int, int);
void mouseMovement(int, int);
void drawString(void*, float, float, char*);

const int screenWidth = 800;
const int screenHeight = 600;
bool imagesLoaded, showControls, fpsCamera, rotate = true;
int counters[5];
float xpos, zpos, xrot, yrot, camDelta;
float tankAngle, headAngle, cannonAngle = 25, weaponRotation = 50, wheelAngle;

const int historySize = 15;;
float history[historySize * 2];
float lastx, lasty;

GLuint tex[9];

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tank Garage");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutMotionFunc(mouseMovement); 
	glutMouseFunc(mouse);

	glutMouseFunc(mouse);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glViewport(0, 0, screenWidth, screenHeight);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, screenWidth / screenHeight, 1, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	loadImages();
	glutTimerFunc(35, animate, 1);

	glutMainLoop();
}

void loadImages(void) 
{
	if (imagesLoaded)
		return;
	imagesLoaded = true;
	glGenTextures(10, tex);

	loadTexture("metal1.jpg", 0);
	loadTexture("metal2.jpg", 1);
	loadTexture("floor.jpg", 2);
	loadTexture("wall1.jpg", 3);
	loadTexture("wall2.jpg", 4);
	loadTexture("metal3.jpg", 5);
	loadTexture("girl.jpg", 6);
	loadTexture("girl2.jpg", 7);
	loadTexture("girl3.jpg", 8);
}

void loadTexture(char* name, int index) 
{
	int x, y, n;
	glBindTexture(GL_TEXTURE_2D, tex[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	unsigned char* imageData = stbi_load(name, &x, &y, &n, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
}

void axis(double length)
{
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, length);
	glEnd();
	glTranslated(0, 0, length - 0.2);
	glutWireCone(0.04, 0.2, 12, 9);
	glPopMatrix();
}

void display(void)
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	GLUquadricObj* qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);  

	glPushMatrix();
	glEnable(GL_LIGHT0);

	if (fpsCamera) 
	{
		glRotatef(xrot, 1, 0, 0);
		glRotatef(yrot, 0, 1, 0);
		glTranslated(-xpos, -4.0f, -zpos);
	} 
	else 
		gluLookAt(-6 + camDelta * 2.6, 12 + camDelta, 0, camDelta * 1.6, 6.75 + camDelta * 0.75, 0, 0, 1, 0);
	
	glPushMatrix();
	glTranslatef(10, 0, 0);
	glRotatef(tankAngle, 0, 1, 0);
	Environment::drawBase(qobj, tex);
	glPushMatrix();
	glTranslatef(0.2, 0, 0);
	TankParts::drawCenter(qobj);
	switch (counters[0]) 
	{
		case 0 : Tank1::drawFront(qobj, wheelAngle); break;
		case 1 : Tank2::drawFront(qobj, wheelAngle); break;
		case 2 : Tank3::drawFront(qobj, wheelAngle); break;
	}
	switch (counters[1]) 
	{
		case 0 : Tank1::drawHead(qobj, headAngle, cannonAngle, weaponRotation, counters[3]); break;
		case 1 : Tank2::drawHead(qobj, headAngle, weaponRotation, counters[3]); break;
		case 2 : Tank3::drawHead(qobj, headAngle, weaponRotation, counters[3]); break;
	}
	switch (counters[2]) 
	{
		case 0 : Tank1::drawRear(qobj, wheelAngle); break;
		case 1 : Tank2::drawRear(qobj, wheelAngle); break;
		case 2 : Tank3::drawRear(qobj, wheelAngle); break;
	}
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7, 0, 10.5);
	Environment::drawToolCorner(qobj);
	glPopMatrix();

	glPushMatrix();
	Environment::drawFloor(tex);
	Environment::drawWall1(qobj, tex);
	Environment::drawWall2(tex);
	Environment::drawWall3(tex);
	Environment::drawWall4(tex);
	if (fpsCamera)
		Environment::drawCeiling(tex);
	glPushMatrix();
	glTranslatef(10.5, -0.45, 0);
	Environment::drawWeaponsBoard(qobj);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10.5, -0.45, 0);
	Environment::drawWeaponsBoard(qobj);
	glPopMatrix();

	glPopMatrix();

	glDisable(GL_LIGHT0);
	gluDeleteQuadric(qobj);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glColor3f(0.7, 0.7, 0.7);
	glRectf(20, 20, 180, 60);
	glRectf(screenWidth - 20, 20, screenWidth - 130, 60);
	glColor3f(0.75, 0.57, 0.3);
	glRectf(25, 25, 175, 55);
	glRectf(screenWidth - 25, 25, screenWidth - 125, 55);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, 33, 33, "Change View");
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, screenWidth - 117, 32, "Controls");

	if (showControls)
	{
		glPushMatrix();
		glTranslatef(0, 50, 0);
		glColor3f(0.7, 0.7, 0.7);
		glRectf(15, screenHeight - 65, fpsCamera? 410 : 480, screenHeight - (fpsCamera? 165 : 265));
		glColor3f(0.75, 0.57, 0.3);
		glRectf(20, screenHeight - 70, fpsCamera? 405 : 475, screenHeight - (fpsCamera? 160 : 260));
		glTranslatef(10, 25, 0);
		if (!fpsCamera) 
		{
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 125, "1..4");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 125, "Customize the tank");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 150, "R");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 150, "Toggle tank rotation");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 175, "Arrows");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 175, "Change viewing angle & rotate tank");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 200, "W, S");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 200, "Rotate the tank's wheels");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 225, "A, D");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 225, "Rotate the tank's head");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 250, "Q, E");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 250, "Adjust the tank's cannon");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 275, "F");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 275, "Fire");
		}
		else
		{
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 125, "LMB");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 125, "Change viewing angle (drag)");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 150, "W, S");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 20, screenHeight - 175, "A, D");
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, 105, screenHeight - 162.5, "Move the player");
		}
		glPopMatrix();
	}

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	glutSwapBuffers();
}

void animate(int value)
{
	if (rotate) 
	{
		glutTimerFunc(35, animate, 1);
		tankAngle += 0.5f;
	}	
	glutPostRedisplay();
}

bool checkCollision(float x, float z) 
{
	return x < 20 && x > -20 && z < 29 && z > -29;
}

void keyboard(unsigned char key, int x, int y) 
{  
	if (fpsCamera) 
	{ 
		if (key=='w' || key=='a' || key=='s' || key=='d') 
		{
			float yrotrad = (yrot / 180 * 3.141592654f);
			float nx = 0, nz = 0;
			if (key=='w') 
			{
				nx = xpos + sin(yrotrad) / 2.0;
				nz = zpos - cos(yrotrad) / 2.0;
			} 
			if (key=='s') 
			{
				nx = xpos - sin(yrotrad) / 2.0;
				nz = zpos + cos(yrotrad) / 2.0;
			}
			if (key=='d') 
			{
				nx = xpos + cos(yrotrad) / 3.0;
				nz = zpos + sin(yrotrad) / 3.0;
			} 
			if (key=='a') 
			{
				nx = xpos - cos(yrotrad) / 3.0;
				nz = zpos - sin(yrotrad) / 3.0;
			}
			if (checkCollision(nx, nz)) 
			{
				xpos = nx;
				zpos = nz;
			}
		}	
	} 
	else 
	{
		if (key=='r') 
		{
			rotate = !rotate;
			if (rotate)
				glutTimerFunc(0, animate, 1);
		}
		if (key >= '1' && key <= '3')
			counters[key - 49] = (counters[key - 49] + 1) % 3;
		if (key == '4')
			counters[3] = (counters[3] + 1) % 4;
		if (key == 'e' && cannonAngle < 55)
			cannonAngle += 0.5;
		if (key == 'd' && headAngle > -25)
			headAngle -= 0.5;
		if (key == 'a' && headAngle < 25)
			headAngle += 0.5;
		if (key == 'q' && cannonAngle > 25)
			cannonAngle -= 0.5;
		if (key == 's')
			wheelAngle -= 3;
		if (key == 'w')
			wheelAngle += 3;
		if (key == 'f')
			weaponRotation += 8;
	}
	glutPostRedisplay();
}

void keyboardSpecial (int key, int x, int y) 
{
	if (fpsCamera) 
		return;

	if (key == GLUT_KEY_UP && camDelta < 5.5)
		camDelta += 0.1;
	if (key == GLUT_KEY_DOWN && camDelta > 0)
		camDelta -= 0.1;

	if (rotate)
		return;

	if (key == GLUT_KEY_RIGHT)
		tankAngle += 1;
	if (key == GLUT_KEY_LEFT)
		tankAngle -= 1;

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;

	if (x > screenWidth - 125 && x < screenWidth - 25 && screenHeight - y > 25 && screenHeight - y < 55) 
	{
		showControls = !showControls;
		glutPostRedisplay();
		return;
	}

	if (x > 25 && x < 175 && screenHeight - y > 25 && screenHeight - y < 55) 
	{
		rotate = fpsCamera;
		if (fpsCamera) 
			glutTimerFunc(35, animate, 1);
		xpos = -5;
		zpos = 13.5;
		xrot = 12;
		yrot = 48;
		tankAngle = 0;
		fpsCamera = !fpsCamera;
		glutPostRedisplay();
		return;
	}

	lastx = x;
	lasty = y;
	glutPostRedisplay();
}

void mouseMovement(int x, int y) 
{
	if (!fpsCamera)
		return;

	int diffx = x - lastx;
    int diffy = y - lasty;
	for (int i = historySize - 1; i > 0; --i)
    {
        history[i * 2] = history[(i - 1) * 2];
        history[i * 2 + 1] = history[(i - 1) * 2 + 1];
    }
    history[0] = diffx;
    history[1] = diffy;

    float averageX = 0.0f;
    float averageY = 0.0f;
    float averageTotal = 0.0f;
    float currentWeight = 1.0f;

    for (int i = 0; i < historySize; ++i)
    {
        averageX += history[i * 2] * currentWeight;
        averageY += history[i * 2 + 1] * currentWeight;
        averageTotal += 1.0f * currentWeight;
        currentWeight *= 0.85;
    }

    diffx = averageX / averageTotal;
	diffy = averageY / averageTotal;

    lastx = x;
	lasty = y;

    xrot += (float) diffy / 9.0;
    yrot += (float) diffx / 9.0;

	if (xrot >= 60)
		xrot = 60;

	if (xrot <= 0)
		xrot = 0;

	glutPostRedisplay();
}

void drawString(void *font, float x, float y, char* string)
{
	glColor3f(1, 1, 1);
	glRasterPos3f(x, y, 0);
	for(char* c = string; *c != '\0'; c++)
		glutBitmapCharacter(font, *c);
}