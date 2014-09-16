#include "stdafx.h"
#include "Tank2.h"
#include "glut.h"
#include "math.h"
#include "TankParts.h"

namespace Tank2
{

	const float n2 = 1.0 / sqrt(2.0);
	const float n3 = 1.0 / sqrt(3.0);

	const float yShear1[] = { 
		1, 0, 0, 0,
		0, 1, -0.5, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float yShear2[] = { 
		1, 0, 0, 0,
		0, 1, 0.5, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float yShear3[] = { 
		1, 0, 0, 0,
		0, 1, -0.1, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float zShear[] = { 
		1, 0, 0, 0,
		0.3, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	void drawHead(GLUquadricObj* qobj, float headAngle, float weaponOrientation, int weapon) 
	{
		int i;
		
		glPushMatrix();
		glRotatef(headAngle, 0, 1, 0);
		drawMask(qobj);
		glTranslatef(0.7, 0.55, 0);

		glPushMatrix();
		glTranslatef(0, 0.3, 0);
		glRotatef(-90, 0, 1, 0);

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0, 0, 0.3);
		glMultMatrixf(yShear3);
		glScalef(0.05, 1.7, 0.5);
		glutSolidCube(1.0);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -0.09);
		gluCylinder(qobj, 0.55, 0.55, 0.2, 8, 1);
		gluDisk(qobj, 0, 0.55, 8, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.05, 0.26);
		glRotatef(5, 1, 0, 0);
		gluCylinder(qobj, 0.77 - 1.5 * 0.05, 0.77 - 2 * 0.05, 0.26, 7, 1);
		glTranslatef(0, 0, 0.26);
		for (i = 2; i < 15; i++) 
		{
			gluCylinder(qobj, 0.77 - i * 0.05, 0.77 - (i + 1) * 0.05, 0.52 / i, 7, 1);
			glTranslatef(0, 0, 0.52 / i);
		}
		gluDisk(qobj, 0, 0.77 - i * 0.05, 7, 1);
		glPopMatrix();

		glPopMatrix();

		if (weapon != 0) 
		{
			glColor3f(0.5, 0.5, 0.5);

			glPushMatrix();
			glRotatef(-90, 0, 1, 0);
	
			glPushMatrix();
			glScalef(1.05, 1.05, 1.05);
			glTranslatef(0.7f, 1.075f, -0.18);
			glPushMatrix();
			glTranslatef(0.1, 0, 0.22);
			glScalef(0.5, 0.2, 0.55);
			glutSolidCube(1.0);
			glPopMatrix();
			glColor3f(0.35, 0.35, 0.35);
			glPushMatrix();
			glMultMatrixf(yShear1);
			glTranslatef(0, 0.21, 0.25);
			glScalef(0.07, 0.3, 0.4);
			glutSolidCube(1.0);
			glPopMatrix();
			if (weapon < 3) 
			{
				glPushMatrix();
				glRotatef(weaponOrientation, 0, 0, 1);
				gluCylinder(qobj, 0.215, 0.215, 0.64f, 20, 1);
				glTranslatef(0.0f, 0, 0.64f);
				gluDisk(qobj, 0.0f, 0.215, 20, 1);
				glPopMatrix();
			}
			gluCylinder(qobj, 0.25, 0.25, 0.6f, 20, 1);
			gluDisk(qobj, 0.0f, 0.25, 20, 1);
			glTranslatef(0.0f, 0, 0.6f);
			gluDisk(qobj, 0.0f, 0.25, 20, 1);
			glPopMatrix();

			glColor3f(0.5, 0.5, 0.5);

			glPushMatrix();
			glScalef(1.05, 1.05, 1.05);
			glTranslatef(-0.7f, 1.075f, -0.18);
			glPushMatrix();
			glTranslatef(-0.1, 0, 0.22);
			glScalef(0.5, 0.2, 0.55);
			glutSolidCube(1.0);
			glPopMatrix();
			glColor3f(0.35, 0.35, 0.35);
			glPushMatrix();
			glMultMatrixf(yShear1);
			glTranslatef(0, 0.21, 0.25);
			glScalef(0.07, 0.3, 0.4);
			glutSolidCube(1.0);
			glPopMatrix();
			if (weapon < 3) 
			{
				glPushMatrix();
				glRotatef(weaponOrientation, 0, 0, 1);
				gluCylinder(qobj, 0.215, 0.215, 0.64f, 20, 1);
				glTranslatef(0.0f, 0, 0.64f);
				gluDisk(qobj, 0.0f, 0.215, 20, 1);
				glPopMatrix();
			}
			gluCylinder(qobj, 0.25, 0.25, 0.6f, 20, 1);
			gluDisk(qobj, 0.0f, 0.25, 20, 1);
			glTranslatef(0.0f, 0, 0.6f);
			gluDisk(qobj, 0.0f, 0.25, 20, 1);
			glPopMatrix();

			glPushMatrix();
			glRotatef(30, 0, 0, 1);
			glTranslatef(0, 0.75, 0.16);
			glScalef(0.1, 1.5, 0.3);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix();
			glRotatef(-30, 0, 0, 1);
			glTranslatef(0, 0.75, 0.16);
			glScalef(0.1, 1.5, 0.3);
			glutSolidCube(1.0);
			glPopMatrix();

			glPopMatrix();

			if (weapon == 1) 
			{
				glPushMatrix();
				glRotatef(-90, 0, 1, 0);

				glPushMatrix();
				glScalef(1.05, 1.05, 1.05);
				glTranslatef(0.7f, 1.075f, -0.03);
				glRotatef(weaponOrientation, 0, 0, 1);
				glScalef(0.4, 0.4, 0.4);
				TankParts::drawGatlingGun(qobj);
				glPopMatrix();

				glPushMatrix();
				glScalef(1.05, 1.05, 1.05);
				glTranslatef(-0.7f, 1.075f, -0.03);
				glRotatef(-weaponOrientation, 0, 0, 1);
				glScalef(0.4, 0.4, 0.4);
				TankParts::drawGatlingGun(qobj);
				glPopMatrix();
				glPopMatrix();
			}

			if (weapon == 2) 
			{
				glPushMatrix();
				glTranslatef(-1.425, 1.3f, 0.74f);
				glScalef(0.15, 0.15, 0.15);
				TankParts::drawLaserRifle(qobj);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.425, 1.3f, -0.74f);
				glScalef(0.15, 0.15, 0.15);
				TankParts::drawLaserRifle(qobj);
				glPopMatrix();
			}

			if (weapon == 3) 
			{
				glPushMatrix();
				glTranslatef(-1.475, 1.125f, 0.74f);
				glScalef(0.085, 0.085, 0.085);
				TankParts::drawPlasmaRifle(qobj);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.475, 1.125f, -0.74f);
				glScalef(0.085, 0.085, 0.085);
				TankParts::drawPlasmaRifle(qobj);
				glPopMatrix();
			}
		}

		glPopMatrix();
	}

	void drawMask(GLUquadricObj* qobj) 
	{
		int i;
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.7, 0.55, 0);

		glPushMatrix();
		glTranslatef(0, 0.3, 0);
		glRotatef(-90, 0, 1, 0);

		glPushMatrix();
		glScalef(0.9, 1.0, 1.0);
		glMultMatrixf(yShear3);
		glRotatef(20, 0, 0, 1);
		gluCylinder(qobj, 0.82, 0.82, 0.4, 9, 1);
		gluDisk(qobj, 0, 0.82, 9, 1);
		glTranslatef(0, 0, 0.4);
		gluDisk(qobj, 0, 0.82, 9, 1);
		glPopMatrix();

		for (i = 0; i < 3; i++) 
		{
			if (i % 2 == 1)
				continue;
			glPushMatrix();
			glTranslatef((i - 1) * 0.1, 0, 0.3);
			glMultMatrixf(yShear3);
			glScalef(0.05, 1.75, 0.6);
			glutSolidCube(1.0);
			glMultMatrixf(yShear1);
			glMultMatrixf(yShear1);
			glutSolidCube(1.0);
			glPopMatrix();
		}

		glPushMatrix();
		glTranslatef(0.0, 0.3, 0);
		glMultMatrixf(yShear1);
		glTranslatef(0, 0.05, 0.26);
		glRotatef(20, 1, 0, 0);
		glTranslatef(0, 0, 1.0);
		gluDisk(qobj, 0, 0.77 - 7 * 0.05, 7, 1);
		for (i = 7; i < 15; i++) 
		{
			gluCylinder(qobj, 0.77 - i * 0.05, 0.77 - (i + 1) * 0.05, 0.52 / i, 7, 1);
			glTranslatef(0, 0, 0.52 / i);
		}
		gluDisk(qobj, 0, 0.77 - i * 0.05, 7, 1);
		glPopMatrix();

		glPopMatrix();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.1, 0, 0.73);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.1, 0.35, 0.73);
		glNormal3f(-n2, 0, n2);
		glVertex3f(-0.45, 0, 0.73);
		glNormal3f(-n2, 0, n2);
		glVertex3f(-0.45, 0.35, 0.73);
		glNormal3f(-n2, 0, n2);
		glVertex3f(-1.0, 0, 0.6);
		glNormal3f(-n2, 0, n2);
		glVertex3f(-1.0, 0.25, 0.6);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.5, 0, 0.3);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.5, 0.25, 0.3);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.5, 0, -0.3);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.5, 0.25, -0.3);
		glNormal3f(-n2, 0, -n2);
		glVertex3f(-1.0, 0, -0.6);
		glNormal3f(-n2, 0, -n2);
		glVertex3f(-1.0, 0.25, -0.6);
		glNormal3f(-n2, 0, -n2);
		glVertex3f(-0.45, 0, -0.73);
		glNormal3f(-n2, 0, -n2);
		glVertex3f(-0.45, 0.35, -0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0, -0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0.35, -0.73);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(-0.39, 0, 0.73);
		glNormal3f(1, 0, 0);
		glVertex3f(-0.39, 0, -0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.39, 0.35, 0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.39, 0.35, -0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.1, 0.35, 0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.1, 0.35, -0.73);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.15, 0, 0.73);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.15, 0, -0.73);
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0, 0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0.35, 0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(0.15, 0, 0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0, -0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.1, 0.35, -0.73);
		glNormal3f(0, 0, -1);
		glVertex3f(0.15, 0, -0.73);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.1, 0.25, 0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.45, 0.25, 0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.0, 0.25, 0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.5, 0.25, 0.3);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.5, 0.25, -0.3);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.0, 0.25, -0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.45, 0.25, -0.73);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.1, 0.25, -0.73);
		glEnd();

		glPopMatrix();
	}

	void drawFront(GLUquadricObj* qobj, float wheelAngle) {
		glPushMatrix();
		glTranslatef(-3.0, 0.08, 0);

		drawFrontRight(qobj, wheelAngle);
		drawFrontLeft(qobj, wheelAngle);

		glPushMatrix();
		glTranslatef(0, 0, 1.7);
		glScalef(1.25f, 1.25f, 1.25f);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 30);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -1.7);
		glScalef(1.25f, 1.25f, 1.25f);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 30);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(0.5, 0, 0);

		//1 top back
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.4, -0.25, 1.199);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.4, 0.47, 1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.4, 0.47, -1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.4, -0.25, -1.199);
		glNormal3f(0.762, -0.648, 0);
		glVertex3f(0.4, 0.47, 1.2);
		glNormal3f(0.762, -0.648, 0);
		glVertex3f(0, 0, 1.2);
		glNormal3f(0.762, -0.648, 0);
		glVertex3f(0, 0, -1.2);
		glNormal3f(0.762, -0.648, 0);
		glVertex3f(0.4, 0.47, -1.2);
		//2 top back
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, -0.25, 1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, 0.45, 1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, 0.45, -1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, -0.25, -1.2);
		glNormal3f(0.49, -0.872, 0);
		glVertex3f(0.8, 0.45, 1.2);
		glNormal3f(0.49, -0.872, 0);
		glVertex3f(0, 0, 1.2);
		glNormal3f(0.49, -0.872, 0);
		glVertex3f(0, 0, -1.2);
		glNormal3f(0.49, -0.872, 0);
		glVertex3f(0.8, 0.45, -1.2);
		//2 sides
		glNormal3f(1, 0, 0);
		glVertex3f(0, 0, 1.2);
		glNormal3f(1, 0, 0);
		glVertex3f(0, -0.25, 1.199);
		glNormal3f(1, 0, 0);
		glVertex3f(0.8, -0.25, 1.199);
		glNormal3f(1, 0, 0);
		glVertex3f(0.8, 0.45, 1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 0, -1.2);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -0.25, -1.199);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, -0.25, -1.199);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.8, 0.45, -1.2);
		//3 top back
		glNormal3f(-1, 0, 0);
		glVertex3f(1.4, -0.25, 0.95);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.4, 0.5, 0.95);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.4, 0.5, -0.95);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.4, -0.25, -0.95);
		glNormal3f(0.336, -0.942, 0);
		glVertex3f(1.4, 0.5, 0.95);
		glNormal3f(0.336, -0.942, 0);
		glVertex3f(0, 0, 1.2);
		glNormal3f(0.336, -0.942, 0);
		glVertex3f(0, 0, -1.2);
		glNormal3f(0.336, -0.942, 0);
		glVertex3f(1.4, 0.5, -0.95);
		//3 sides
		glNormal3f(0.985, 0, 0.176);
		glVertex3f(0, 0, 1.2);
		glNormal3f(0.985, 0, 0.176);
		glVertex3f(0, -0.25, 1.2);
		glNormal3f(0.985, 0, 0.176);
		glVertex3f(1.4, -0.25, 0.95);
		glNormal3f(0.985, 0, 0.176);
		glVertex3f(1.4, 0.5, 0.95);
		glNormal3f(-0.985, 0, 0.176);
		glVertex3f(0, 0, -1.2);
		glNormal3f(-0.985, 0, 0.176);
		glVertex3f(0, -0.25, -1.2);
		glNormal3f(-0.985, 0, 0.176);
		glVertex3f(1.4, -0.25, -0.95);
		glNormal3f(-0.985, 0, 0.176);
		glVertex3f(1.4, 0.5, -0.95);
		glEnd();
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);
		
		glTranslatef(0.35, 0.2, 0);
		glRotatef(-90, 0, 1, 0);
		for (int i = 0; i < 6; i++) 
		{
			glPushMatrix();
			glTranslatef(0, 0, 0.55);
			glMultMatrixf((i % 2 == 0)? yShear1 : yShear2);
			glRotatef(i * 360.0 / 6 + 30, 0, 0, 1);
			glScalef(0.425 * 2, 0.05, 0.8);
			glutSolidCube(1.0);
			glPopMatrix();
		}

		glPushMatrix();
		glTranslatef(0, 0, -1.5);
		gluCylinder(qobj, 0.275, 0.5, 1.5, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(30, 0, 0, 1);
		gluCylinder(qobj, 0.12, 0.12, 1.1, 6, 1);
		gluCylinder(qobj, 0.5, 0.5, 1.2, 30, 1);
		gluCylinder(qobj, 0.425, 0.425, 1.2, 30, 1);
		glTranslatef(0, 0, 1.1);
		gluCylinder(qobj, 0.12, 0, 0.35, 6, 1);
		glTranslatef(0, 0, 0.1);
		gluDisk(qobj, 0.425, 0.5, 30, 1);
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glMultMatrixf(yShear1);
		gluCylinder(qobj, 0.55, 0.7, 1.2, 30, 1);
		gluCylinder(qobj, 0.5, 0.5, 1.2, 30, 1);
		gluDisk(qobj, 0.5, 0.55, 30, 1);
		glTranslatef(0, 0, 1.2);
		gluDisk(qobj, 0.5, 0.7, 30, 1);
		
		glPopMatrix();
	}

	void drawFrontRight(GLUquadricObj* qobj, float wheelAngle) 
	{
		float angle;

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(0, 0, 1.2);
		
		//face 0
		glBegin(GL_POLYGON);
		angle = 20 * 2 * 3.141592653589793238462 / 72;
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, -0.3, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 21; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(1, 0, 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
			glNormal3f(1, 0, 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0);
		}
		glNormal3f(1, 0, 0);
		glVertex3f(-1.25, -0.3, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0);
		glEnd();

		//face 0.5
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-1, 0, 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0.5);
			glNormal3f(-1, 0, 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0.5);
		}
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.25, -0.3, 0.5);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0.5);
		glEnd();
		
		//0 - 0.5
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, -1, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(2.0, 1.25, 0.5);
		for(int i = 20; i < 24; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0.5);
		}
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0.5);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25 / 1.5, 0.5);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25 / 1.5, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 24; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0.5);
		}
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0.5);
		glEnd();
		
		//-0.7 - 0
		glBegin(GL_QUAD_STRIP);
		angle = 20 * 2 * 3.141592653589793238462 / 72;
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 2, -0.3, -0.72);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, -0.3, 0);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 2, sin(angle) * 1.25 / 2, -0.72);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25 / 2, -0.3, -0.72);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25, -0.3, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 25; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 2, sin(angle) * 1.25 / 2, -0.77);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0);
		}
		glEnd();
		
		//0.5 - 0.75
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, -n2, -n2);
		glVertex3f(2.0, 1.25, 0.5);
		glNormal3f(0, -n2, -n2);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0.75);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0.5);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0.75);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25, -0.3, 0.5);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, 0.75);
		glEnd();
		
		//0.75 - 0
		glBegin(GL_QUAD_STRIP);
		glNormal3f(n2, n2, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0.75);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0.75);
		for(int i = 0; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0.75);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, 0);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, 0.75);
		glEnd();
		
		//new face
		glBegin(GL_QUAD_STRIP);
		for(int i = 19; i >= 0; i--) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.25 / 1.5, 1.25 / 1.5, 0.75);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0.75);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 1.25 / 1.5, 0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0.75);
		glEnd();
		
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0.75);
		glNormal3f(-1, 0, 0);
		glVertex3f(2.0, 1.25, 0.5);
		glEnd();
		
		glColor3f(0.5, 0.5, 0.5);

		for(int i = 26; i < 38; i += 2) 
		{
			glPushMatrix();
			angle = i * 2 * 3.141592653589793238462 / 72 - 0.07;
			glTranslatef(cos(angle) * 1.12, sin(angle) * 1.12, 0);			
			gluCylinder(qobj, 0.07, 0.07, 0.5, 10, 1);
			glPopMatrix();
		}
		glPushMatrix();
		glTranslatef(cos(angle) * 1.12, -0.15, 0);			
		gluCylinder(qobj, 0.07, 0.07, 0.5, 10, 1);
		glPopMatrix();
		
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.9, 1.25, 0.5 / 2);
		glScalef(1.75, 0.05, 0.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.13, 0.4, 0.375);
		glRotatef(64.27, 0, 0, 1);
		glScalef(0.6, 0.05, 0.55);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

	void drawFrontLeft(GLUquadricObj* qobj, float wheelAngle) 
	{
		float angle;

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(0, 0, -1.2);
		
		//face 0
		glBegin(GL_POLYGON);
		angle = 20 * 2 * 3.141592653589793238462 / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, -0.3, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 21; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(-1, 0, 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
			glNormal3f(-1, 0, 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0);
		}
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.25, -0.3, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0);
		glEnd();

		//face 0.5
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(1, 0, 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, -0.5);
			glNormal3f(1, 0, 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, -0.5);
		}
		glNormal3f(1, 0, 0);
		glVertex3f(-1.25, -0.3, -0.5);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, -0.5);
		glEnd();
		
		//0 - 0.5
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 1, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(2.0, 1.25, -0.5);
		for(int i = 20; i < 24; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, -0.5);
		}
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, -0.5);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25 / 1.5, -0.5);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25 / 1.5, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 24; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.3, sin(angle) * 1.25 / 1.3, -0.5);
		}
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 1.3, -0.3, -0.5);
		glEnd();
		
		//-0.7 - 0
		glBegin(GL_QUAD_STRIP);
		angle = 20 * 2 * 3.141592653589793238462 / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25 / 2, -0.3, 0.72);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 1.25, -0.3, 0);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 2, sin(angle) * 1.25 / 2, 0.72);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, 0);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25 / 2, -0.3, 0.72);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25, -0.3, 0);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 0; i < 25; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 2, sin(angle) * 1.25 / 2, 0.77);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0);
		}
		glEnd();
		
		//0.5 - 0.75
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, n2, -n2);
		glVertex3f(2.0, 1.25, -0.5);
		glNormal3f(0, n2, -n2);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, -0.75);
		for(int i = 20; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25, sin(angle) * 1.25, -0.5);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, -0.75);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25, -0.3, -0.5);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, -0.75);
		glEnd();
		
		//0.75 - 0
		glBegin(GL_QUAD_STRIP);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, -0.75);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.25 / 1.5 + 0.1, 0, -0.75);
		for(int i = 0; i < 35; i++) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, -0.75);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, 0);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.25 / 1.5, -0.3, -0.75);
		glEnd();
		
		//new face
		glBegin(GL_QUAD_STRIP);
		for(int i = 19; i >= 0; i--) 
		{
			angle = i * 2 * 3.141592653589793238462 / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.25 / 1.5, 1.25 / 1.5, -0.75);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.25 / 1.5, sin(angle) * 1.25 / 1.5, -0.75);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 1.25 / 1.5, -0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 0, -0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, -0.75);
		glNormal3f(0, 0, 1);
		glVertex3f(1.25 / 1.5 + 0.1, 0, -0.75);
		glEnd();
		
		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0, 1.25, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0 / 1.5, 1.25 / 1.5, -0.75);
		glNormal3f(1, 0, 0);
		glVertex3f(2.0, 1.25, -0.5);
		glEnd();
		
		glColor3f(0.5, 0.5, 0.5);

		for(int i = 26; i < 38; i += 2) 
		{
			glPushMatrix();
			angle = i * 2 * 3.141592653589793238462 / 72 - 0.07;
			glTranslatef(cos(angle) * 1.12, sin(angle) * 1.12, -0.5);			
			gluCylinder(qobj, 0.07, 0.07, 0.5, 10, 1);
			glPopMatrix();
		}
		glPushMatrix();
		glTranslatef(cos(angle) * 1.12, -0.15, -0.5);			
		gluCylinder(qobj, 0.07, 0.07, 0.5, 10, 1);
		glPopMatrix();
		
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.9, 1.25, -0.5/2);
		glScalef(1.75, 0.05, 0.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.13, 0.4, -0.375);
		glRotatef(64.27, 0, 0, 1);
		glScalef(0.6, 0.05, 0.55);
		glutSolidCube(1.0);
		glPopMatrix();
		
		glPopMatrix();
	}

	void drawRear(GLUquadricObj* qobj, float wheelAngle) 
	{
		glPushMatrix();
		glTranslatef(3.15, 0.72, 0);
		drawBackCover(qobj);
		glScalef(2.5, 2.5, 2.5);
		glRotatef(wheelAngle / 2, 0, 0, 1);
		drawWheel(qobj, 40);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(1.1, 0.125, 0.675);
		for (int i = 0; i < 5; i++) {
			if (i == 0 || i == 4)
				glColor3f(0.66, 0.5, 0.26);
			else
				glColor3f(0.5, 0.5, 0.5);
			glPushMatrix();
			glTranslatef((i == 0 || i == 4)? 0.75 : 0.7, 0, 0.6 - i * 0.1);
			glScalef(0.75, (i == 0 || i == 4)? 0.4 : 0.3, 0.05);
			glMultMatrixf(zShear);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1, 0.125, -0.675);
		for (int i = 0; i < 5; i++) {
			if (i == 0 || i == 4)
				glColor3f(0.66, 0.5, 0.26);
			else
				glColor3f(0.5, 0.5, 0.5);
			glPushMatrix();
			glTranslatef((i == 0 || i == 4)? 0.75 : 0.7, 0, - 0.6 + i * 0.1);
			glScalef(0.75, (i == 0 || i == 4)? 0.4 : 0.3, 0.05);
			glMultMatrixf(zShear);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(1.15, 0.15, 0.65);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, -1, 0);
		glVertex3f(0, 0.9, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0, 0.9, 0.3);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0.6, 0.9, 0.3);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0, 0.2, 0.75);
		glNormal3f(0, -n2, -n2);
		glVertex3f(0.6, 0.2, 0.75);
		glNormal3f(0, 0, -1);
		glVertex3f(0, -0.35, 0.75);
		glNormal3f(0, 0, -1);
		glVertex3f(0.6, -0.35, 0.75);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(0, -0.35, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.6, -0.35, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0, 0.9, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(0, -0.35, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0, 0.9, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0, 0.9, 0.3);
		glNormal3f(1, 0, 0);
		glVertex3f(0, 0.2, 0.75);
		glNormal3f(1, 0, 0);
		glVertex3f(0, -0.35, 0.75);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(0.6, -0.35, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(1, 0, 0);
		glVertex3f(0.6, 0.9, 0.3);
		glNormal3f(1, 0, 0);
		glVertex3f(0.6, 0.2, 0.75);
		glNormal3f(1, 0, 0);
		glVertex3f(0.6, -0.35, 0.75);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.15, 0.15, -0.65);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 1, 0);
		glVertex3f(0, 0.9, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(0, n2, -n2);
		glVertex3f(0, 0.9, -0.3);
		glNormal3f(0, n2, -n2);
		glVertex3f(0.6, 0.9, -0.3);
		glNormal3f(0, n2, -n2);
		glVertex3f(0, 0.2, -0.75);
		glNormal3f(0, n2, -n2);
		glVertex3f(0.6, 0.2, -0.75);
		glNormal3f(0, 0, -1);
		glVertex3f(0, -0.35, -0.75);
		glNormal3f(0, 0, -1);
		glVertex3f(0.6, -0.35, -0.75);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(0, -0.35, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.6, -0.35, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(0, 0.9, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -0.35, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 0.9, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 0.9, -0.3);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 0.2, -0.75);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -0.35, -0.75);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.6, -0.35, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.6, 0.9, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.6, 0.9, -0.3);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.6, 0.2, -0.75);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.6, -0.35, -0.75);
		glEnd();
		glPopMatrix();
	}

	void drawBackCover(GLUquadricObj* qobj) 
	{
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.63);
		gluCylinder(qobj, 0.7, 0.7, 0.17, 30, 1);
		gluDisk(qobj, 0.0f, 0.7, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.17);
		gluDisk(qobj, 0.0f, 0.7, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.63 - 0.17);
		gluCylinder(qobj, 0.7, 0.7, 0.17, 30, 1);
		gluDisk(qobj, 0.0f, 0.7, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.17);
		gluDisk(qobj, 0.0f, 0.7, 30, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(-0.95 - 0.8 / 2, 0.0f, 0.82);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.06, 0.06, 0.8, 30, 1);
		gluDisk(qobj, 0.0f, 0.06f, 30, 1);
		glTranslatef(0, 0, 0.8f);
		gluDisk(qobj, 0.0f, 0.06f, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.95 - 0.8 / 2, 0.0f, -0.82);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.06, 0.06, 0.8, 30, 1);
		gluDisk(qobj, 0.0f, 0.06f, 30, 1);
		glTranslatef(0, 0, 0.8f);
		gluDisk(qobj, 0.0f, 0.06f, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.86);
		gluCylinder(qobj, 0.5, 0.5, 1.72, 30, 1);
		gluDisk(qobj, 0, 0.5, 30, 1);
		glTranslatef(0.0f, 0.0f, 1.72);
		gluDisk(qobj, 0, 0.5, 30, 1);
		glPopMatrix();

		for(int i = 0; i < 12; i++) 
		{
			glPushMatrix();
			glRotatef(i * 360.0 / 12, 0.0, 0.0, 1.0);
			glTranslatef(0.59f, 0.0, 0.74);
			glutSolidSphere(0.08, 40, 40);
			glTranslatef(0, 0.0, -0.74 * 2);
			glutSolidSphere(0.08, 40, 40);
			glPopMatrix();
		}

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(-1.0, 0.0f, 0.78);
		glScalef(3.5, 0.8, 0.2);
		glutSolidCube(0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.0, 0.0f, -0.78);
		glScalef(3.5, 0.8, 0.2);
		glutSolidCube(0.5);
		glPopMatrix();
	}

	void drawWheel(GLUquadricObj* qobj, int steps) 
	{
		float side = sin(3.14159 / steps);

		glColor3f(0.1, 0.1, 0.1);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -3 * side);
		gluCylinder(qobj, 0.5, 0.5, 6 * side, steps, 1);
		gluCylinder(qobj, 0.25, 0.25, 6 * side, steps, 1);
		gluDisk(qobj, 0.25f, 0.5, steps, 1);
		glTranslatef(0.0f, 0.0f, 6 * side);
		gluDisk(qobj, 0.25f, 0.5, steps, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -2.25 * side);
		gluDisk(qobj, 0.0f, 0.3, steps, 1);
		glTranslatef(0.0f, 0.0f, 4.5 * side);
		gluDisk(qobj, 0.0f, 0.3, steps, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -3 * side);
		gluCylinder(qobj, 0.25, 0.25, 6 * side, steps, 1);
		gluCylinder(qobj, 0.2, 0.2, 6 * side, steps, 1);
		gluDisk(qobj, 0.19f, 0.25, steps, 1);
		glTranslatef(0.0f, 0.0f, 6 * side);
		gluDisk(qobj, 0.19f, 0.25, steps, 1);
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -2.3 * side);
		gluCylinder(qobj, 0.53, 0.53, 4.6 * side, steps, 1);
		gluDisk(qobj, 0.25f, 0.53, steps, 1);
		glTranslatef(0.0f, 0.0f, 4.6 * side);
		gluDisk(qobj, 0.25f, 0.53, steps, 1);
		glPopMatrix();

		for(int i = 0; i < steps / 2; i++) 
		{
			glPushMatrix();
			glRotatef(2 * i * 360.0 / steps, 0.0, 0.0, 1.0);
			glTranslatef(0.45f, 0.0, 0);
			glScalef(2.5, 1.0, 7.0);
			glutSolidCube(side);
			glPopMatrix();
		}
	}

}