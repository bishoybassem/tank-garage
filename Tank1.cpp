#include "stdafx.h"
#include "Tank1.h"
#include "glut.h"
#include "math.h"
#include "TankParts.h"

# define PI	3.14159265358979323846

namespace Tank1
{

	const float n2 = 1.0 / sqrt(2.0);
	const float n3 = 1.0 / sqrt(3.0);
	const float zShear[] = { 
		1, 0, 1, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float zShear2[] = { 
		1, 0, -0.2, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	void drawFront(GLUquadricObj* qobj, float wheelAngle) 
	{
		float angle;

		glPushMatrix();
		glScalef(1.0, 1.0, 0.95);
		glTranslatef(-3.15, 0, 0);

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(1.45 - 0.45 - 0.25 + 0.05, 0, 0);
		glScalef(1.6, 0.3, 3.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -0.25);
		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(n3, -n3, n3);
		glVertex3f(-1.25, -0.2, 1.5);
		glNormal3f(n3, -n3, n3);
		glVertex3f(-0.4, 0, 0.8);
		glNormal3f(n3, -n3, n3);
		glVertex3f(-0.4, 1.15, 1.5);
		glNormal3f(-n3, -n3, n3);
		glVertex3f(2.22, 0, 0.8);
		glNormal3f(-n3, -n3, n3);
		glVertex3f(2.22, 1.15, 1.5);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.35, -0.2, 1.5);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 0.25);
		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(-n3, n3, n3);
		glVertex3f(-1.25, -0.2, -1.5);
		glNormal3f(-n3, n3, n3);
		glVertex3f(-0.4, 0, -0.8);
		glNormal3f(-n3, n3, n3);
		glVertex3f(-0.4, 1.15, -1.5);
		glNormal3f(n3, n3, n3);
		glVertex3f(2.22, 0, -0.8);
		glNormal3f(n3, n3, n3);
		glVertex3f(2.22, 1.15, -1.5);
		glNormal3f(1, 0, 0);
		glVertex3f(2.35, -0.2, -1.5);
		glEnd();
		glPopMatrix();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		glVertex3f(0.0, 0.8, -1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(0.0, 1.15, -1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(1.75, 1.15, -1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(1.75, 0.8, -1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(0.0, 0.8, 1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(0.0, 1.15, 1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(1.75, 1.15, 1.25);
		glNormal3f(0, 0, -1);
		glVertex3f(1.75, 0.8, 1.25);
		glEnd();

		glColor3f(0.66, 0.5, 0.26);
	
		glPushMatrix();
		glTranslatef(-0.2, -0.25, -0.4);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(0.0, 0.0, 0.0);
		glNormal3f(0, 0, 1);
		glVertex3f(1.2, 0, 0);
		glNormal3f(n3, -n3, n3);
		glVertex3f(0.0, 0.5, 0);
		glNormal3f(n3, -n3, n3);
		glVertex3f(1.2, 1.1, 0);
		glNormal3f(n3, -n3, -n3);
		glVertex3f(0.0, 0.5, 0.8);
		glNormal3f(n3, -n3, -n3);
		glVertex3f(1.2, 1.1, 0.8);
		glNormal3f(0, 0, -1);
		glVertex3f(0.0, 0.0, 0.8);
		glNormal3f(0, 0, -1);
		glVertex3f(1.2, 0, 0.8);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 0.5, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 0.5, 0.8);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 0.0, 0.0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 0.0, 0.8);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.2, 0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.2, 0, 0.8);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.2, 1.1, 0.0);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.2, 1.1, 0.8);
		glEnd();
		glPopMatrix();
	
		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0.4, 0.55, 0);
		glRotatef(26.6, 0, 0, 1);
		glScalef(1.1, 0.05, 0.55);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.2, 0, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.35, 0.05, 0.55);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1, 0.6, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.35, 0.05, 0.55);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.16, 0, 0);
		glRotatef(-90, 0, 1, 0);
		glRotatef(30, 1, 0, 0);
		glTranslatef(-0.15, 0, 0);
		gluCylinder(qobj, 0.12, 0, 0.65, 12, 1);
		glTranslatef(0.3, 0, 0);
		gluCylinder(qobj, 0.12, 0, 0.65, 12, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.0, 0.6, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(-0.15, 0, 0);
		gluCylinder(qobj, 0.12, 0, 0.65, 12, 1);
		glTranslatef(0.3, 0, 0);
		gluCylinder(qobj, 0.12, 0, 0.65, 12, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 1.25);
		drawFrontCover(qobj);
		glPushMatrix();
		glTranslatef(0, 0, 0.15);
		glRotatef(wheelAngle, 0, 0, 1);
		glScalef(1.1, 1.1, 1.0);
		drawWheel(qobj, 26, true);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1.5, 0, 0.15);
		glRotatef(wheelAngle, 0, 0, 1);
		glScalef(1.1, 1.1, 1.0);
		drawWheel(qobj, 26, true);
		glPopMatrix();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(0, 0, -2.078);
		drawFrontCover(qobj);
		glPopMatrix();
		glPushMatrix();
		glRotatef(180, 0, 1, 0);
		glPushMatrix();
		glTranslatef(-1.5, 0, 1.4);
		glRotatef(wheelAngle, 0, 0, -1);
		glScalef(1.1, 1.1, 1.0);
		drawWheel(qobj, 26, true);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 1.4);
		glRotatef(wheelAngle, 0, 0, -1);
		glScalef(1.1, 1.1, 1.0);
		drawWheel(qobj, 26, true);
		glPopMatrix();
		glPopMatrix();
		
		glPopMatrix();
	}

	void drawRear(GLUquadricObj* qobj, float wheelAngle) 
	{
		float angle;

		glPushMatrix();
		glTranslatef(0.5, 0, 0);

		const float s1[] = { 
			1, 0.2, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(1.0, 0.47, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, 1.45);
		gluCylinder(qobj, 0.77, 0.6, 0.2, 30, 1);
		gluCylinder(qobj, 0.6, 0.6, 0.2, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.45, 0.475, 0);
		for(int i = 0; i < 16; i++) 
		{
			glPushMatrix();
			glRotatef(30 * i, 1, 0, 0);
			glTranslatef(0, 0.5, 0);
			glScalef(0.31, 0.2, 0.075);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(1.625, -0.03, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.4, 0.4, 1.0, 30, 1);
		gluCylinder(qobj, 0.275, 0.275, 0.85, 30, 1);
		gluDisk(qobj, 0, 0.275, 30, 1);
		glTranslatef(0, 0, 0.85);
		gluCylinder(qobj, 0.275, 0.4, 0.15, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.075, 0.5, 0.45);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.25, 0, 1.0, 30, 1);
		gluDisk(qobj, 0, 0.25, 30, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1.075, 0.5, -0.45);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.25, 0, 1.0, 30, 1);
		gluDisk(qobj, 0, 0.25, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.4, 0.5, 0.5);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.25, 0, 1.0, 30, 1);
		gluDisk(qobj, 0, 0.25, 30, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1.4, 0.5, -0.5);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.25, 0, 1.0, 30, 1);
		gluDisk(qobj, 0, 0.25, 30, 1);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(1.0, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.3, 0.75, 1.45, 30, 1);
		gluDisk(qobj, 0, 0.3, 30, 1);
		glTranslatef(0, 0, 1.45);
		glColor3f(0.35, 0.35, 0.35);
		gluDisk(qobj, 0.375, 0.75, 30, 1);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glScalef(0.95, 0.95, 0.9);
		glTranslatef(-3.15, 0, 0);

		glPushMatrix();
		glTranslatef(5.2, 0.24, 0.95);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.05, 0);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, -0.4, 0);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 0);
		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, -0.4, 0.12);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, 1.05, 0.12);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, 1.05, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.2, 0.24, -0.95);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.05, 0);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, -0.4, 0);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 0);
		}
		glEnd();
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.55, -0.4, -0.12);
		glNormal3f(1, 0, 0);
		glVertex3f(0.55, 1.05, -0.12);
		glNormal3f(1, 0, 0);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.55, 1.05, 0);
		glEnd();
		glPopMatrix();
	
		glColor3f(0.66, 0.5, 0.26);
	
		glPushMatrix();
		glTranslatef(5.2, 0.24, 0.95);
		drawBackCover(qobj);
		glTranslatef(0, 0, 0.15);
		glScalef(1.75, 1.75, 1.5);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 30, false);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.2, 0.24, -2.12);
		drawBackCover(qobj);
		glPopMatrix();
		glPushMatrix();
		glRotatef(180, 0, 1, 0);
		glTranslatef(-5.2, 0.24, 1.1);
		glScalef(1.75, 1.75, 1.5);
		glRotatef(wheelAngle, 0, 0, -1);
		drawWheel(qobj, 30, false);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);
		
		glPushMatrix();
		glTranslatef(5.2, 0.24, 0.95);
		glBegin(GL_QUAD_STRIP);
		angle = 18 * 2 * PI / 72;
		glNormal3f(1, 0, 1);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(1, 0, 1);
		glVertex3f(0.55 / 1.5, -0.4, -0.25);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.55, 1.35, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.55 / 1.5, 1.35 / 1.5, -0.25);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.5, sin(angle) * 1.35 / 1.5, -0.25);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.35, -0.4, 0);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.35 / 1.5, -0.4, -0.25);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55 / 1.5, -0.4, -0.25);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55 / 1.5, 1.35 / 1.5, -0.25);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.35 / 1.5, sin(angle) * 1.35 / 1.5, -0.25);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.35 / 1.5, -0.4, -0.25);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.2, 0.24, -0.95);
		glBegin(GL_QUAD_STRIP);
		angle = 18 * 2 * PI / 72;
		glNormal3f(-1, 0, -1);
		glVertex3f(0.55, -0.4, 0);
		glNormal3f(-1, 0, -1);
		glVertex3f(0.55 / 1.5, -0.4, 0.25);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.55, 1.35, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.55 / 1.5, 1.35 / 1.5, 0.25);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.5, sin(angle) * 1.35 / 1.5, 0.25);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.35, -0.4, 0);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.35 / 1.5, -0.4, 0.25);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55 / 1.5, -0.4, 0.25);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55 / 1.5, 1.35 / 1.5, 0.25);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.35 / 1.5, sin(angle) * 1.35 / 1.5, 0.25);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.35 / 1.5, -0.4, 0.25);
		glEnd();
		glPopMatrix();

		glPopMatrix();
		glPopMatrix();
	}

	void drawHead(GLUquadricObj* qobj, float headAngle, float weaponAngle, float cannonLength, int weapon) 
	{

		glPushMatrix();
		glRotatef(headAngle, 0, 1, 0);
		drawMask(qobj);

		glPushMatrix();
		glTranslatef(0.15, 0.6, 0);

		glPushMatrix();
		glScalef(0.93, 0.93, 0.93);

		glPushMatrix();
		glScalef(1.25, 1.25, 1.25);

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0, 0.8, 0.45);
		glRotatef(53.1, 1, 0, 0);
		glScalef(0.55, 0.05, 0.35);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.8, -0.45);
		glRotatef(-53.1, 1, 0, 0);
		glScalef(0.55, 0.05, 0.35);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix(); //pop head scale

		gluSphere(qobj, 0.835, 20, 20);

		glColor3f(0.35, 0.35, 0.35);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.3);
		gluCylinder(qobj, 0.9, 0.9, 0.6, 20, 1);
		gluDisk(qobj, 0.0f, 0.9, 20, 1);
		glTranslatef(0.0f, 0.0f, 0.6);
		gluDisk(qobj, 0.0f, 0.9, 20, 1);
		glPopMatrix();

		if (weapon != 0) 
		{
			glPushMatrix();
			glRotatef(90 - weaponAngle, 0, 0, 1);
			glRotatef(-90, 1, 0, 0);
	
			glPushMatrix();
			gluCylinder(qobj, 0.28, 0.28, 1.8, 20, 1);
			glTranslatef(0.0f, 0.0f, 1.8);
			gluDisk(qobj, 0.0f, 0.28, 20, 1);
			glPopMatrix();

			if (weapon == 1) 
			{
				glPushMatrix();
				glTranslatef(0, 0, (cannonLength <= 1.5)? -cannonLength : (cannonLength <= 3.0)? cannonLength - 3.0 : 0);
				TankParts::drawCannon(qobj);
				glPopMatrix();
			}

			if (weapon == 2) 
			{
				glPushMatrix();
				gluCylinder(qobj, 0.25, 0.25, 1.85, 20, 1);
				glTranslatef(0.0f, 0.0f, 1.85);
				gluDisk(qobj, 0.0f, 0.25, 20, 1);
				glPopMatrix();

				glRotatef(cannonLength, 0, 0, 1);
				glTranslatef(0, 0, 1.5);
				glScalef(0.48, 0.48, 0.48);
				TankParts::drawGatlingGun(qobj);
			}

			if (weapon == 3) 
			{
				glTranslatef(0.225, 0, 2.25);
				glScalef(0.32, 0.32, 0.32);
				glRotatef(90, 0, 1, 0);
				glRotatef(90, 1, 0, 0);
				TankParts::drawGrenadeLauncher(qobj);
			}
			glPopMatrix(); //pop weapon rotate
		}

		glPopMatrix(); //pop head scale
		glPopMatrix(); //pop head rotate
		glPopMatrix(); //pop head translate
	}

	void drawMask(GLUquadricObj* qobj) 
	{
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.15, 0.6, 0);
		glScalef(0.93, 0.93, 0.93);
		glScalef(1.25, 1.25, 1.25);

		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.35, 0, -0.6);
		glNormal3f(0, 0, 1);
		glVertex3f(0.35, 0, -0.6);
		glNormal3f(0, -n2, n2);
		glVertex3f(-0.35, 0.6, -0.6);
		glNormal3f(0, -n2, n2);
		glVertex3f(0.35, 0.6, -0.6);
		glNormal3f(0, -n2, n2);
		glVertex3f(-0.35, 1.0, -0.3);
		glNormal3f(0, -n2, n2);
		glVertex3f(0.35, 1.0, -0.3);
		glNormal3f(0, -n2, -n2);
		glVertex3f(-0.35, 1.0, 0.3);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0.35, 1.0, 0.3);
		glNormal3f(0, -n2, -n2);
		glVertex3f(-0.35, 0.6, 0.6);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0.35, 0.6, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.35, 0, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(0.35, 0, 0.6);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 0, -0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 0.6, -0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 1.0, -0.3);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 1.0, 0.3);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 0.6, 0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(0.35, 0, 0.6);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.35, 0, -0.6);
		glNormal3f(0, -n2, n2);
		glVertex3f(-0.35, 0.6, -0.6);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.0, 0, -0.3);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-0.35, 1.0, -0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.35, 0.0, -0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(0.35, 1.0, -0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(0.35, 0.0, -0.3);
		glNormal3f(0, -n2, n2);
		glVertex3f(1.5, 1.0, -0.3);
		glNormal3f(0, -n2, n2);
		glVertex3f(0.35, 0.6, -0.6);
		glNormal3f(0, -n2, n2);
		glVertex3f(0.35, 1.0, -0.3);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.35, 0, 0.6);
		glNormal3f(0, n2, n2);
		glVertex3f(-0.35, 0.6, 0.6);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-1.0, 0, 0.3);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-0.35, 1.0, 0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.35, 0.0, 0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(0.35, 1.0, 0.3);
		glNormal3f(0, 0, -1);
		glVertex3f(0.35, 0.0, 0.3);
		glNormal3f(0, n2, n2);
		glVertex3f(1.5, 1.0, 0.3);
		glNormal3f(0, n2, n2);
		glVertex3f(0.35, 0.6, 0.6);
		glNormal3f(0, n2, n2);
		glVertex3f(0.35, 1.0, 0.3);
		glEnd();

		glPopMatrix();
	}

	void drawWheel(GLUquadricObj* qobj, int steps, bool edges) 
	{
		float side = sin(3.14159 / steps);

		glColor3f(0.1, 0.1, 0.1);

		glPushMatrix();
		gluCylinder(qobj, 0.5, 0.5, 0.75, 22, 1);
		glTranslatef(0.0f, 0.0f, 0.01);
		gluDisk(qobj, 0.0f, 0.5, 22, 1);
		glTranslatef(0.0f, 0.0f, 0.74);
		gluDisk(qobj, 0.0f, 0.5, 22, 1);
		glPopMatrix();

		glPushMatrix();
		gluCylinder(qobj, 0.085, 0.085, 0.79, 22, 1);
		glTranslatef(0, 0.0, 0.79);
		gluDisk(qobj, 0.0f, 0.085, 22, 1);
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		for(int i = 0; i < steps / 2; i++) 
		{
			float d = ((steps % 4 == 0)? (360.0f / steps / 2) : 0);
			glPushMatrix();
			glScalef(1.0, 1.0, 0.8 / side);
			glRotatef(2 * i * 360 / steps + d, 0.0, 0.0, 1.0);
			glTranslatef(0.42f + side / 2.0f, 0.0, side / 2);
			glutSolidCube(side);
			glPopMatrix();
			if (edges) 
			{
				glPushMatrix();
				glRotatef(2 * i * 360 / steps + d, 0.0, 0.0, 1.0);
				glTranslatef(0.42f + side / 2.0f, 0.0, 0.8);
				glMultMatrixf(zShear);
				glutSolidCube(side);
				glPopMatrix();
			}
		}

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		gluCylinder(qobj, 0.25, 0.25, 0.8, 22, 1);
		glTranslatef(0, 0.0, 0.65);
		gluCylinder(qobj, 0.5, 0.25, 0.15, 22, 1);
		glTranslatef(0, 0.0, 0.12);
		glPopMatrix();

		for (int i = 0; i < 3; i++) 
		{
			glPushMatrix();
			glRotatef(i * 120, 0.0, 0.0, 1.0);
			glMultMatrixf(zShear2);
			glTranslatef(0.12, 0.0, 0.75);
			glScalef(0.18, 0.1, 0.1);
			glutSolidCube(1.0);
			glPopMatrix();
		}
	}

	void drawFrontCover(GLUquadricObj* qobj) 
	{
		float angle;

		glColor3f(0.61, 0.57, 0.42);
	
		glPushMatrix();
		glScalef(1.0, 1.0, 1.2);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.7, -0.2, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.7, -0.2, 0.69);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.7, sin(angle) * 0.7, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.7, sin(angle) * 0.7, 0.69);
		}
		glNormal3f(0, 1, 0);
		glVertex3f(0.7, -0.2, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0.7, -0.2, 0.69);
		glNormal3f(0, 1, 0);
		glVertex3f(0.8, -0.2, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0.8, -0.2, 0.69);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(1.5 + cos(angle) * 0.7, sin(angle) * 0.7, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(1.5 + cos(angle) * 0.7, sin(angle) * 0.7, 0.69);
		}
		glNormal3f(0, 1, 0);
		glVertex3f(2.2, -0.2, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(2.2, -0.2, 0.69);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.35, -0.2, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.35, -0.2, 0.69);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.22, 1.15, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.22, 1.15, 0.69);
		glNormal3f(n2, -n2, 0);
		glVertex3f(1.75, 1.15, 0);
		glNormal3f(n2, -n2, 0);
		glVertex3f(1.75, 1.15, 0.69);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.0, 1.15, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.0, 1.15, 0.69);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-0.4, 1.15, 0);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-0.4, 1.15, 0.69);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.25, -0.2, 0);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.25, -0.2, 0.69);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.7, -0.2, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.7, -0.2, 0.69);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.75, 1.15, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.75, 0.85, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.75, 0.85, 0.69);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.75, 1.15, 0.69);
		glNormal3f(0, 1, 0);
		glVertex3f(1.75, 0.85, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0.0, 0.85, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0, 0.85, 0.69);
		glNormal3f(0, 1, 0);
		glVertex3f(1.75, 0.85, 0.69);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 0.85, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 1.15, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.0, 1.15, 0.69);
		glNormal3f(1, 0, 0);
		glVertex3f(0, 0.85, 0.69);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.25, -0.2, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.7, -0.2, 0.69);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(0, 0, 1);
			if (i > 3) 
				glVertex3f(-0.4, 1.15, 0.69);
			else
				glVertex3f(cos(angle) * 0.7, 0.85, 0.69);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.7, sin(angle) * 0.7, 0.69);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(0.7, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(0.7, -0.2, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(0.8, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(0.8, -0.2, 0.69);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(0, 0, 1);
			glVertex3f(1.5 + cos(angle) * 0.7, 0.85, 0.69);
			glNormal3f(0, 0, 1);
			glVertex3f(1.5 + cos(angle) * 0.7, sin(angle) * 0.7, 0.69);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(2.21, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(2.2, -0.2, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(2.35, -0.2, 0.69);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.25, -0.2, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.7, -0.2, 0);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(0, 0, 1);
			if (i > 3) 
				glVertex3f(-0.4, 1.15, 0);
			else
				glVertex3f(cos(angle) * 0.7, 0.85, 0);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.7, sin(angle) * 0.7, 0);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(0.7, 0.85, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.7, -0.2, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.8, 0.85, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.8, -0.2, 0);
		for(int i = 5; i > -1; i--) 
		{
			angle = i * 2 * PI / 10;
			glNormal3f(0, 0, 1);
			glVertex3f(1.5 + cos(angle) * 0.7, 0.85, 0);
			glNormal3f(0, 0, 1);
			glVertex3f(1.5 + cos(angle) * 0.7, sin(angle) * 0.7, 0);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(2.21, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(2.2, -0.2, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(2.35, -0.2, 0);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(0.0, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(0.0, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.4, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.4, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(0.0, 0.85, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.0, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.4, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.4, 0.85, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(1.75, 1.15, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(1.75, 0.85, 0.69);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 0.85, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(2.22, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(1.75, 1.15, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(1.75, 0.85, 0);
		glEnd();
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef((0.69) * -0.6 - 0.15, 1.0, 0);
		gluCylinder(qobj, 0.11, 0.11, 2.3, 16, 1);
		glTranslatef(0, 0, 2.3);
		gluCylinder(qobj, 0.12, 0, 0.65, 16, 1);
		glTranslatef(0.3, 0, -2.3);
		gluCylinder(qobj, 0.11, 0.11, 2.3, 16, 1);
		glTranslatef(0, 0, 2.3);
		gluCylinder(qobj, 0.12, 0, 0.65, 16, 1);
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(-0.81, 0.51, 0.414);
		glRotatef(57.8, 0, 0, 1);
		glScalef(1.3, 0.05, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	void drawBackCover(GLUquadricObj* qobj) 
	{
		float angle;

		glColor3f(0.61, 0.57, 0.42);
		
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, -1, 0);
		glVertex3f(0.55, 1.05, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(0.55, 1.05, 1.17);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 1.17);
		}
		glNormal3f(1, 0, 0);
		glVertex3f(-1.05, -0.4, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(-1.05, -0.4, 1.17);
		glEnd();
		
		glBegin(GL_QUAD_STRIP);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, 1.05, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.55, 1.05, 1.17);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.55, 1.35, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.55, 1.35, 1.17);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 1.17);
		}
		glNormal3f(1, 0, 0);
		glVertex3f(-1.35, -0.4, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(-1.35, -0.4, 1.17);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.05, 1.17);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.35, 1.17);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 1.17);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 1.17);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.05, -0.4, 1.17);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.35, -0.4, 1.17);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.05, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.55, 1.35, 0);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.05, sin(angle) * 1.05, 0);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.35, sin(angle) * 1.35, 0);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.05, -0.4, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.35, -0.4, 0);
		glEnd();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.95, 1.2, 0.58);
		glScalef(0.4, 0.3, 1.17);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-0.6825, 1.2, 0);
		gluCylinder(qobj, 0.11, 0.11, 1.0, 12, 1);
		glTranslatef(0.3, 0, 0);
		gluCylinder(qobj, 0.11, 0.11, 1.0, 12, 1);
		glPopMatrix();
	}

}