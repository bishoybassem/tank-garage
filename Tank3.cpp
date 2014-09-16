#include "stdafx.h"
#include "Tank3.h"
#include "glut.h"
#include "math.h"
#include "TankParts.h"

# define PI	3.14159265358979323846

namespace Tank3
{

	const float n2 = 1.0 / sqrt(2.0);
	const float n3 = 1.0 / sqrt(3.0);

	const float zShear1[] = { 
		1, 0, -0.4, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float zShear2[] = { 
		1, 0, 0.4, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float xShear1[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		1.0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float xShear2[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		-1.0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float xShear3[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		0.3, 0, 1, 0,
		0, 0, 0, 1
	};

	const float xShear4[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		-0.3, 0, 1, 0,
		0, 0, 0, 1
	};

	const float yShear1[] = { 
		1, 0, 0, 0,
		-0.35, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float yShear2[] = { 
		1, 0.4, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	const float yShear3[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, -0.4, 1, 0,
		0, 0, 0, 1
	};

	const float yShear5[] = { 
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0.4, 1, 0,
		0, 0, 0, 1
	};

	const float yShear4[] = { 
		1, 0.3, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	void drawHead(GLUquadricObj* qobj, float headAngle, float weaponOrientation, int weapon) 
	{
		float angle;
		
		const float s1[] = { 
			1, 0, 0, 0,
			0.5, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s2[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			0.7, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s3[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			-0.7, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s4[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			1, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s5[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			-1, 0, 1, 0,
			0, 0, 0, 1
		};

		glPushMatrix();
		glRotatef(headAngle, 0, 1, 0);
		
		drawMask(qobj);

		glTranslatef(0.05, 0.7, 0);
		glScalef(1, 1.125, 1.125);

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(-0.825, -0.05, 0);
		glMultMatrixf(s1);
		glScalef(0.35, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.83, 0, 0.2);
		glMultMatrixf(s1);
		glScalef(0.35, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.83, 0, -0.2);
		glMultMatrixf(s1);
		glScalef(0.35, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.65, 0.05, 0.35);
		glMultMatrixf(s1);
		glScalef(0.4, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.65, 0.05, -0.35);
		glMultMatrixf(s1);
		glScalef(0.4, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.375, 0.1, 0.5);
		glMultMatrixf(s1);
		glScalef(0.65, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.375, 0.1, -0.5);
		glMultMatrixf(s1);
		glScalef(0.65, 0.7, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glMultMatrixf(s1);
		glMultMatrixf(s2);
		glTranslatef(-0.63, 0.2, 0.2);
		glScalef(0.1, 0.5, 0.4);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s1);
		glMultMatrixf(s3);
		glTranslatef(-0.63, 0.2, -0.2);
		glScalef(0.1, 0.5, 0.4);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1, 0, 0);
		glMultMatrixf(s1);
		glScalef(1.5, 0.4, 0.6);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.1, 0, 0);
		glScalef(1.5, 0.4, 0.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0.1, 0.1, -0.375);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75 / 1.2, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75 / 1.5, -0.3, -0.05);
		for(int i = 0; i <= 20; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75 / 1.2, sin(angle) * 0.75 / 1.2, 0.05);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, -0.05);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75 / 1.5, -0.3, -0.05);
		for(int i = 0; i <= 20; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, -0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75 / 1.5, -0.3, -0.05);
		glEnd();
		glBegin(GL_QUADS);
		angle = 20 * 2 * PI / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.2, sin(angle) * 0.75 / 1.2, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.2, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.5, -0.3, -0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, -0.05);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1, 0.1, 0.375);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.75 / 1.2, -0.3, -0.05);
		glNormal3f(-1, 0, 0);
		glVertex3f(0.75 / 1.5, -0.3, 0.05);
		for(int i = 0; i <= 20; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 0.75 / 1.2, sin(angle) * 0.75 / 1.2, -0.05);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, 0.05);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75 / 1.5, -0.3, 0.05);
		for(int i = 0; i <= 20; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, 0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75 / 1.5, -0.3, 0.05);
		glEnd();
		glBegin(GL_QUADS);
		angle = 20 * 2 * PI / 72;
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.2, sin(angle) * 0.75 / 1.2, -0.05);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.2, -0.3, -0.05);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.5, -0.3, 0.05);
		glNormal3f(-1, 0, 0);
		glVertex3f(cos(angle) * 0.75 / 1.5, sin(angle) * 0.75 / 1.5, 0.05);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1, 0.7, 0);
		glRotatef(-90, 0, 1, 0);
		gluCylinder(qobj, 0.2, 0.2, 0.15, 30, 1);
		gluCylinder(qobj, 0.26, 0.26, 0.15, 30, 1);
		glTranslatef(0, 0, 0.15);
		gluDisk(qobj, 0.2, 0.26, 30, 1);
		glPopMatrix();

		if (weapon != 0) 
		{
			glColor3f(0.3, 0.3, 0.3);
			glPushMatrix();
			glTranslatef(0, 0.7, 0);
			glRotatef(-90, 0, 1, 0);
			gluCylinder(qobj, 0.13, 0.13, 1.0, 30, 1);
			glPopMatrix();

			if (weapon == 1)
				glColor3f(0.41, 0.22, 0.22);
			else if (weapon == 2)
				glColor3f(0, 0.5, 0);
			else
				glColor3f(0.06, 0.41, 0.53);

			glPushMatrix();
			glTranslatef(-0.9, 0.7, 0);
			for(int i = 0; i < 8; i++) 
			{
				glTranslatef(0.1f, 0, 0);
				for (int j = 0; j < 5; j++)
				{
					glPushMatrix();
					glRotatef(72 * j, 1, 0, 0);
					glScalef(0.05, 0.32, 0.05);
					glutSolidCube(1.0);
					glPopMatrix();
				}
			}
			glPopMatrix();

			if (weapon == 1) 
			{
				glPushMatrix();
				glTranslatef(-2, 0.9, 0);
				glScalef(0.18, 0.18, 0.18);
				TankParts::drawLaserRifle(qobj);
				glPopMatrix();
			}
			if (weapon == 2) 
			{
				glPushMatrix();
				glTranslatef(-2, 0.7, 0);
				glScalef(0.09, 0.09, 0.09);
				TankParts::drawPlasmaRifle(qobj);
				glPopMatrix();
			}
			if (weapon == 3) 
			{
				glPushMatrix();
				glTranslatef(-1.8, 0.875, 0);
				glScalef(0.12, 0.12, 0.12);
				TankParts::drawIonRifle(qobj);
				glPopMatrix();
			}
		}

		glPopMatrix();
	}

	void drawMask(GLUquadricObj* qobj) 
	{
		float angle;

		const float s1[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			1, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s2[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			-1, 0, 1, 0,
			0, 0, 0, 1
		};

		glPushMatrix();
		glTranslatef(0.05, 0.7, 0);
		glScalef(1, 1.125, 1.125);

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(0.425, 0.825, 0.265);
		glMultMatrixf(s1);
		glScalef(0.6, 0.22, 0.22);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.425, 0.825, -0.265);
		glMultMatrixf(s2);
		glScalef(0.6, 0.22, 0.22);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.025, 0.325, -0.2);
		gluCylinder(qobj, 0.2, 0.2, 0.4, 6, 1);
		gluDisk(qobj, 0, 0.2, 6, 1);
		glTranslatef(0, 0, 0.4);
		gluDisk(qobj, 0, 0.2, 6, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.05, 0.3, -0.1);
		gluCylinder(qobj, 0.26, 0.26, 0.2, 6, 1);
		gluDisk(qobj, 0, 0.26, 6, 1);
		glTranslatef(0, 0, 0.2);
		gluDisk(qobj, 0, 0.26, 6, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, 0, 0);
		glScalef(0.8, 0.41, 0.61);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(-0.8, 0, 0.35);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s2);
		glTranslatef(-0.8, 0, -0.35);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.1, 0);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.3, 0.25);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.3, -0.25);
		for(int i = 0; i <= 18; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, 0.25);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, -0.25);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9, -0.3, 0.25);
		for(int i = 0; i <= 18; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, 0.25);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.9, -0.3, 0.25);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9, -0.3, -0.25);
		for(int i = 0; i <= 18; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, -0.25);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.9, -0.3, -0.25);
		glEnd();
		glBegin(GL_QUADS);
		angle = 18 * 2 * PI / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, 0.25);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.9, -0.3, 0.25);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.9, -0.3, -0.25);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.9, sin(angle) * 0.9, -0.25);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.1, 0.3);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75, -0.3, -0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75, -0.3, 0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75, -0.3, 0.05);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75, -0.3, -0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75, -0.3, -0.05);
		glEnd();
		glBegin(GL_QUADS);
		angle = 19 * 2 * PI / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, -0.3, -0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.1, -0.3);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(0.75, -0.3, -0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75, -0.3, 0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75, -0.3, 0.05);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.75, -0.3, -0.05);
		for(int i = 0; i <= 19; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(cos(angle) * 0.75, -0.3, -0.05);
		glEnd();
		glBegin(GL_QUADS);
		angle = 19 * 2 * PI / 72;
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, -0.3, 0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, -0.3, -0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(cos(angle) * 0.75, sin(angle) * 0.75, -0.05);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1, 0.7, 0);
		glRotatef(-90, 0, 1, 0);
		gluCylinder(qobj, 0.175, 0.175, 0.2, 30, 1);
		glTranslatef(0, 0, 0.2);
		gluDisk(qobj, 0, 0.175, 30, 1);
		glPopMatrix();

		glPopMatrix();
	}

	void drawRear(GLUquadricObj* qobj, float wheelAngle) 
	{
		drawRearRightSide(qobj);
		drawRearLeftSide(qobj);
		drawRearCenter(qobj);

		glPushMatrix();
		glTranslatef(2.9, 0.375, 0.775);
		glScalef(1.4, 1.4, 1.0);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.9, 0.375, 1.8);
		glScalef(1.4, 1.4, 1.0);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.9, 0.375, -0.775);
		glScalef(1.4, 1.4, 1.0);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.9, 0.375, -1.8);
		glScalef(1.4, 1.4, 1.0);
		glRotatef(wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();
	}

	void drawRearRightSide(GLUquadricObj* qobj) 
	{
		float angle;

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(2.9, 0.3, 0.65);
		for(int i = 30; i < 38; i += 2) 
		{
			glPushMatrix();
			angle = i * 2 * PI / 72  - 0.08;
			glTranslatef(cos(angle) * 1.325, sin(angle) * 1.325, 0);			
			gluCylinder(qobj, 0.07, 0.07, 0.25, 10, 1);
			glPopMatrix();
		}
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(2.9, 0.3, 0.03);
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.4);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, 0.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.65);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.4);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.45, -0.4, 0.65);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.3 / 1.1, -0.4, 0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3 / 1.2, -0.4, 0.2);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, 0.65);
		glEnd();
		glBegin(GL_POLYGON);
		angle = 28 * 2 * PI / 72;
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.9, 0.3, 2.5);
		glBegin(GL_QUAD_STRIP);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, -0.6);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, -1.2);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.35 / 1.2, -0.4, -0.6);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.35 / 1.2, -0.4, -1.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, -0.6);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, -1.2);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.28 / 1.2, -0.4, -0.6);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.28 / 1.2, -0.4, -1.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		angle = 33 * 2 * PI / 72;
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, -1.2);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, -1.2);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, -0.6);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, -0.6);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.35 / 1.2, -0.4, -0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.28 / 1.2, -0.4, -0.6);
		glEnd();
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(2.9, 0.3, 1.52);
		glBegin(GL_QUAD_STRIP);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.4);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, -0.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.65);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.4);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.45, -0.4, -0.65);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.3 / 1.1, -0.4, -0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.2, -0.4, -0.2);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, -0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.2, -0.4, -0.2);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.1, -0.4, -0.2);
		glEnd();
		glBegin(GL_POLYGON);
		angle = 20 * 2 * PI / 72;
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
		glEnd();
		glBegin(GL_TRIANGLES);
		angle = 18 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, -0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, -0.4);
		glEnd();
		glBegin(GL_QUADS);
		angle = 18 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, -0.4);
		angle = 20 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, 1.1, -0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		glEnd();
		glPopMatrix();
	}

	void drawRearLeftSide(GLUquadricObj* qobj) 
	{
		float angle;

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(2.9, 0.3, -0.9);
		for(int i = 30; i < 38; i += 2) 
		{
			glPushMatrix();
			angle = i * 2 * PI / 72 - 0.08;
			glTranslatef(cos(angle) * 1.325, sin(angle) * 1.325, 0);			
			gluCylinder(qobj, 0.07, 0.07, 0.25, 10, 1);
			glPopMatrix();
		}
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(2.9, 0.3, -0.03);
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.4);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, -0.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.65);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.45, -0.4, -0.4);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.45, -0.4, -0.65);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.3 / 1.1, -0.4, -0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 28; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.2, -0.4, -0.2);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, -0.65);
		glEnd();
		glBegin(GL_POLYGON);
		angle = 28 * 2 * PI / 72;
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.4);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, -0.65);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.65);
		glNormal3f(0, -1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, -0.2);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.9, 0.3, -2.5);
		glBegin(GL_QUAD_STRIP);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, 0.6);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, 1.2);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.35 / 1.2, -0.4, 0.6);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.35 / 1.2, -0.4, 1.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, 0.6);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, 1.2);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.28 / 1.2, -0.4, 0.6);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.28 / 1.2, -0.4, 1.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		angle = 33 * 2 * PI / 72;
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, 1.2);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, 1.2);
		for(int i = 33; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.35 / 1.2, sin(angle) * 1.35 / 1.2, 0.6);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.28 / 1.2, sin(angle) * 1.28 / 1.2, 0.6);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.35 / 1.2, -0.4, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.28 / 1.2, -0.4, 0.6);
		glEnd();
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(2.9, 0.3, -1.52);
		glBegin(GL_QUAD_STRIP);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.4);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, 0.2);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.65);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.45, -0.4, 0.4);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
			glNormal3f(0, 0, -1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		}
		glNormal3f(0, 0, -1);
		glVertex3f(-1.45, -0.4, 0.65);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.3 / 1.1, -0.4, 0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 20; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.2, -0.4, 0.2);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, 0.65);
		glEnd();
		glBegin(GL_QUAD_STRIP);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.2, -0.4, 0.2);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.1, -0.4, 0.2);
		glEnd();
		glBegin(GL_POLYGON);
		angle = 20 * 2 * PI / 72;
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.65);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.65);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
		glEnd();
		glBegin(GL_TRIANGLES);
		angle = 18 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, 0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.2, sin(angle) * 1.3 / 1.2, 0.2);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		glNormal3f(0, 1, 0);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, 0.4);
		glEnd();
		glBegin(GL_QUADS);
		angle = 18 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.3 / 1.1 + 0.3, sin(angle) * 1.3 / 1.1, 0.4);
		angle = 20 * 2 * PI / 72;
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, 1.1, 0.4);
		glNormal3f(0, 0, -1);
		glVertex3f(cos(angle) * 1.45, sin(angle) * 1.45, 0.4);
		glEnd();
		glPopMatrix();
	}

	void drawRearCenter(GLUquadricObj* qobj) 
	{
		float angle;

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(2.9, 0.3, 0.03);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, -1, 0);
		glVertex3f(1.15, 1.3, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, 0.2);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3, sin(angle) * 1.3, 0);
			glNormal3f(-cos(angle), -sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		}
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3, -0.4, 0);
		glNormal3f(-cos(angle), -sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, 0.2);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(1.15, 1.3, 0);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3, sin(angle) * 1.3, 0);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3, -0.55, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.3, -0.55, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, 0.2);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, 0.2);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.1, -0.55, 0.2);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.3, -0.55, 0.2);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.15, 1.3, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, 0.2);
		glNormal3f(n2, n2, 0);
		glVertex3f(-0.3, -0.55, 0.2);
		glNormal3f(n2, n2, 0);
		glVertex3f(-0.3, -0.55, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.9, 0.3, -0.03);
		glBegin(GL_QUAD_STRIP);
		glNormal3f(0, 1, 0);
		glVertex3f(1.15, 1.3, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, -0.2);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3, sin(angle) * 1.3, 0);
			glNormal3f(cos(angle), sin(angle), 0);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		}
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3, -0.4, 0);
		glNormal3f(cos(angle), sin(angle), 0);
		glVertex3f(-1.3 / 1.1, -0.4, -0.2);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(1.15, 1.3, 0);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3, sin(angle) * 1.3, 0);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3, -0.55, 0);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.3, -0.55, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, -0.2);
		for(int i = 18; i < 38; i++) 
		{
			angle = i * 2 * PI / 72;
			glNormal3f(0, 0, 1);
			glVertex3f(cos(angle) * 1.3 / 1.1, sin(angle) * 1.3 / 1.1, -0.2);
		}
		glNormal3f(0, 0, 1);
		glVertex3f(-1.3 / 1.1, -0.55, -0.2);
		glNormal3f(0, 0, 1);
		glVertex3f(-0.3, -0.55, -0.2);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.15, 1.3, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.9 / 1.1, 1.3 / 1.1, -0.2);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-0.3, -0.55, -0.2);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-0.3, -0.55, 0);
		glEnd();
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(2.9, 0.375, -0.3);
		gluCylinder(qobj, 0.55, 0.55, 0.6, 30, 1);
		gluDisk(qobj, 0, 0.55, 30, 1);
		glTranslatef(0, 0, 0.6);
		gluDisk(qobj, 0, 0.55, 30, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(2.9, 0.3, -0.05);
		for(int i = 38; i >= 18; i -= 2) 
		{
			glPushMatrix();
			angle = i * 2 * PI / 72;
			glTranslatef(cos(angle) * 1.18, sin(angle) * 1.18, 0);			
			gluCylinder(qobj, 0.07, 0.07, 0.1, 10, 1);
			glPopMatrix();
		}
		for(int i = 1; i < 5; i++) 
		{
			glPushMatrix();
			glTranslatef(cos(angle) * 1.18  + i * 0.2, sin(angle) * 1.18, 0);			
			gluCylinder(qobj, 0.07, 0.07, 0.1, 10, 1);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.9, 0.375, -1.5);
		gluCylinder(qobj, 0.25, 0.25, 2.9, 30, 1);
		glPopMatrix();
	}

	void drawFront(GLUquadricObj* qobj, float wheelAngle)
	{
		glPushMatrix();
		glTranslatef(-3.25, 0.2, 0);
		glRotatef(180, 0, 1, 0);

		drawFrontCenter(qobj);
		drawFrontSides(qobj, wheelAngle);

		glColor3f(0.66, 0.5, 0.26);

		float s6[] = { 
			1, 0.2, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		float s7[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			1.5, 0, 1, 0,
			0, 0, 0, 1
		};

		float s8[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, -0.6, 1, 0,
			0, 0, 0, 1
		};

		float s9[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			-1.5, 0, 1, 0,
			0, 0, 0, 1
		};

		float s10[] = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0.6, 1, 0,
			0, 0, 0, 1
		};

		glPushMatrix();
		glMultMatrixf(s6);
		glMultMatrixf(s7);
		glMultMatrixf(s8);
		glTranslatef(-1.05, 0.675, 0.35);
		glScalef(1.55, 0.05, 0.45);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s6);
		glMultMatrixf(s9);
		glMultMatrixf(s10);
		glTranslatef(-1.05, 0.675, -0.35);
		glScalef(1.55, 0.05, 0.45);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glMultMatrixf(s6);
		glMultMatrixf(s8);
		glTranslatef(-0.45, 0.675, 0.35);
		glScalef(1.3, 0.05, 0.45);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s6);
		glMultMatrixf(s10);
		glTranslatef(-0.45, 0.675, -0.35);
		glScalef(1.3, 0.05, 0.45);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glBegin(GL_TRIANGLES);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-2.2, 0.05 * 1.3 + 0.15, 0.05 * 1.05);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04 + 0.05, -0.1 * 1.3 + 0.15, 0.7* 1.05);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.27 + 0.05, 0, 1.5);

		glNormal3f(n2, n2, 0);
		glVertex3f(-2.2, 0.05 * 1.3 + 0.15, 0.05 * -1.05);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04 + 0.05, -0.1 * 1.3 + 0.15, 0.7* -1.05);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.27 + 0.05, 0, -1.5);
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-2.2, 0.05 * 1.3 + 0.15, 0.05 * 1.05);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.27 + 0.05, 0, 1.5);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.27 + 0.05, -0.4, 1.5);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-2.2, -0.4, 0.05 * 1.05);

		glNormal3f(n2, n2, 0);
		glVertex3f(-2.2, 0.05 * 1.3 + 0.15, 0.05 * -1.05);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.27 + 0.05, 0, -1.5);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.27 + 0.05, -0.4, -1.5);
		glNormal3f(n2, n2, 0);
		glVertex3f(-2.2, -0.4, 0.05 * -1.05);
		glEnd();

		glPopMatrix();
	}

	void drawFrontCenter(GLUquadricObj* qobj) {
		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0, 0.15, 0);

		glPushMatrix();
		glTranslatef(0.8, -0.08, 0.175);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear2);
		glMultMatrixf(yShear3);
		glScalef(0.5, 1.07, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.72, -0.1, 0.325);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear4);
		glMultMatrixf(yShear3);
		glScalef(0.5, 0.97, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.6, -0.115, 0.475);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear4);
		glMultMatrixf(yShear3);
		glScalef(0.5, 0.8, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, -0.08, -0.175);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear2);
		glMultMatrixf(yShear5);
		glScalef(0.5, 1.07, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.72, -0.1, -0.325);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear4);
		glMultMatrixf(yShear5);
		glScalef(0.5, 0.97, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.6, -0.115, -0.475);
		glMultMatrixf(yShear1);
		glMultMatrixf(yShear4);
		glMultMatrixf(yShear5);
		glScalef(0.5, 0.8, 0.05);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glScalef(1.0, 1.3, 1.05);

		glBegin(GL_QUADS);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.0, -0.31, 0.73);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.0, -0.31, 0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.65, 0.21, 0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.65, 0.21, 0.77);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.0, -0.31, -0.73);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.0, -0.31, -0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.65, 0.21, -0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.65, 0.21, -0.77);
		glEnd();

		//center quads right
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glVertex3f(1.0, -0.31, 0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(1.3, -0.41, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, 0.6);
		glNormal3f(0, 0, 1);
		glVertex3f(1.3, -0.41, 0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(0.95, 0.5, 0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, 0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(0.95, 0.5, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(0.65, 0.21, 0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, 0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, 0.05);
		glNormal3f(0, 0, -1);
		glVertex3f(0.65, 0.21, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(1.0, -0.31, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, 0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, 0.05);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, 0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, 0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, 0.05);
		glEnd();

		//center quads left
		glBegin(GL_QUADS);
		glNormal3f(0, -1, 0);
		glVertex3f(1.0, -0.31, -0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(1.3, -0.41, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, -0.6);
		glNormal3f(0, 0, 1);
		glVertex3f(1.3, -0.41, -0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(0.95, 0.5, -0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, -0.05);
		glNormal3f(0, 0, 1);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(0.95, 0.5, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(0.65, 0.21, -0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, -0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, -0.05);
		glNormal3f(0, 0, -1);
		glVertex3f(0.65, 0.21, -0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(1.0, -0.31, -0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, -0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, -0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3 / 1.5, -0.41 / 1.5, -0.05);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.0 / 1.5, -0.31 / 1.5, -0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.65 / 1.5, 0.21 / 1.5, -0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.95 / 1.5, 0.5 / 1.5, -0.05);
		glEnd();

		//down strip
		glBegin(GL_QUAD_STRIP);
		glNormal3f(1, 0, 0);
		glVertex3f(1.0, -0.31, 0.73);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.5, 0.73);
		glNormal3f(1, 0, 0);
		glVertex3f(1.0, -0.31, 0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.5, 0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3, -0.41, 0.05);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3 - 0.1, -0.6, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(1.35, -0.41, 0.);
		glNormal3f(0, 1, 0);
		glVertex3f(1.35 - 0.1, -0.6, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3, -0.41, -0.05);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3 - 0.1, -0.6, -0.05);
		glNormal3f(1, 0, 0);
		glVertex3f(1.0, -0.31, -0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.5, -0.6);
		glNormal3f(1, 0, 0);
		glVertex3f(1.0, -0.31, -0.73);
		glNormal3f(1, 0, 0);
		glVertex3f(0.9, -0.5, -0.73);
		glEnd();

		//center strip
		glBegin(GL_QUAD_STRIP);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.95, 0.5, 0.05);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3, -0.41, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(1.0, 0.6, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(1.35, -0.41, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.95, 0.5, -0.05);
		glNormal3f(n2, n2, 0);
		glVertex3f(1.3, -0.41, -0.05);
		glEnd();

		glBegin(GL_QUAD_STRIP);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.95, 0.5, 0.05);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-2.2, 0.05, 0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(1.0, 0.6, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(-2.2, 0.15, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.95, 0.5, -0.05);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-2.2, 0.05, -0.05);
		glEnd();
		
		glBegin(GL_QUADS);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.95, 0.5, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(-2.2, 0.05, 0.05);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04, -0.1, 0.7);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.65, 0.21, 0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.95, 0.5, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(-2.2, 0.05, -0.05);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04, -0.1, -0.7);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.65, 0.21, -0.6);
		glEnd();

		//sides
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(1.0, -0.31, 0.73);
		glNormal3f(0, 0, 1);
		glVertex3f(0.65, 0.21, 0.77);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.04, -0.1, 0.7);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9, -0.5, 0.73);
		glNormal3f(0, 0, 1);
		glVertex3f(1.0, -0.31, -0.73);
		glNormal3f(0, 0, 1);
		glVertex3f(0.65, 0.21, -0.77);
		glNormal3f(0, 0, 1);
		glVertex3f(-1.04, -0.1, -0.7);
		glNormal3f(0, 0, 1);
		glVertex3f(0.9, -0.5, -0.73);
		glEnd();

		//sides
		glBegin(GL_TRIANGLES);
		glNormal3f(0, -1, 0);
		glVertex3f(0.65, 0.21, 0.77);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04, -0.1, 0.7);
		glNormal3f(0, -1, 0);
		glVertex3f(0.65, 0.21, 0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(0.65, 0.21, -0.77);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04, -0.1, -0.7);
		glNormal3f(0, 1, 0);
		glVertex3f(0.65, 0.21, -0.6);
		glEnd();

		glPopMatrix();
	}

	void drawFrontSides(GLUquadricObj* qobj, float wheelAngle) 
	{

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(0, 0, -2.13);
		gluCylinder(qobj, 0.42, 0.6, 0.12, 30, 1);
		gluDisk(qobj, 0, 0.42, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.12);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 2.13 - 0.12);
		gluCylinder(qobj, 0.6, 0.42, 0.12, 30, 1);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.12);
		gluDisk(qobj, 0, 0.42, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.5, -0.2, -1.4);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.5, -0.2, 1.4);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear4);
		glutSolidCube(1.0);
		glPopMatrix();
		
		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(-0.8, 0, -2.1);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.8, 0, 2.1);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear4);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -2.05);
		gluCylinder(qobj, 0.4, 0.4, 0.5, 30, 1);
		gluDisk(qobj, 0, 0.4, 30, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 1.55);
		gluCylinder(qobj, 0.4, 0.4, 0.5, 30, 1);
		glTranslatef(0, 0, 0.5);
		gluDisk(qobj, 0, 0.4, 30, 1);
		glPopMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(-0.65, -0.1, -1.75);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.65, -0.1, 1.75);
		glScalef(1.7, 0.55, 0.15);
		glMultMatrixf(xShear4);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.02, 0, -2.13);
		glScalef(0.52, 0.74, 0.2);
		glMultMatrixf(xShear1);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.02, 0, 2.13);
		glScalef(0.52, 0.74, 0.2);
		glMultMatrixf(xShear2);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 1.4);
		drawFrontWheelCover(qobj, true);
		glScalef(1.15, 1.15, 1.15);
		glRotatef(-wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, -1.4);
		drawFrontWheelCover(qobj, false);
		glScalef(1.15, 1.15, 1.15);
		glRotatef(-wheelAngle, 0, 0, 1);
		drawWheel(qobj, 50);
		glPopMatrix();
	}

	void drawFrontWheelCover(GLUquadricObj* qobj, bool right) {
		glPushMatrix();

		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(-0.1, 0.98, 0.175);
		glRotatef(20, 1, 0, 0);
		glScalef(0.5, 0.05, 0.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, 0.98, -0.175);
		glRotatef(-20, 1, 0, 0);
		glScalef(0.5, 0.05, 0.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		if (right)
			glVertex3f(0.51, 0, 0.67);
		else
			glVertex3f(0.99, -0.3, 0.67);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.04, 0, 0.67);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.46, 0.81, 0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(0.23, 0.81, 0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(0.23, 0.81, 0.6);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.46, 0.81, 0.6);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(-0.46, 1.04, 0);
		glNormal3f(-n2, -n2, 0);
		glVertex3f(0.23, 1.04, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04, 0, 0.67);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.46, 0.81, 0.6);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-0.46, 1.04, 0);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-1.27, 0, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04, 0, 0.67);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04, -0.4, 0.67);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.27, -0.4, 0);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.27, 0, 0);
		if (right) 
		{
			glNormal3f(0, 0, 1);
			glVertex3f(-1.04, 0, 0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-1.04, -0.4, 0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-0.1, -0.4, 0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-0.1, 0, 0.67);
		}
		glEnd();

		glBegin(GL_QUADS);
		glNormal3f(0, 0, -1);
		if (right)
			glVertex3f(0.99, -0.3, -0.67);
		else
			glVertex3f(0.51, 0, -0.67);
		glNormal3f(0, 0, -1);
		glVertex3f(-1.04, 0, -0.67);
		glNormal3f(0, 0, -1);
		glVertex3f(-0.46, 0.81, -0.6);
		glNormal3f(0, 0, -1);
		glVertex3f(0.23, 0.81, -0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(0.23, 0.81, -0.6);
		glNormal3f(0, 1, 0);
		glVertex3f(-0.46, 0.81, -0.6);
		glNormal3f(n2, n2, 0);
		glVertex3f(-0.46, 1.04, 0);
		glNormal3f(n2, n2, 0);
		glVertex3f(0.23, 1.04, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(-1.04, 0, -0.67);
		glNormal3f(0, -1, 0);
		glVertex3f(-0.46, 0.81, -0.6);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-0.46, 1.04, 0);
		glNormal3f(n2, -n2, 0);
		glVertex3f(-1.27, 0, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04, 0, -0.67);
		glNormal3f(0, 1, 0);
		glVertex3f(-1.04, -0.4, -0.67);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-1.27, -0.4, 0);
		glNormal3f(-n2, n2, 0);
		glVertex3f(-1.27, 0, 0);
		if (!right) 
		{
			glNormal3f(0, 0, 1);
			glVertex3f(-1.04, 0, -0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-1.04, -0.4, -0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-0.1, -0.4, -0.67);
			glNormal3f(0, 0, 1);
			glVertex3f(-0.1, 0, -0.67);
		}
		glEnd();

		glPopMatrix();
	}

	void drawWheel(GLUquadricObj* qobj, int steps) 
	{
		float side = sin(3.14159 / steps);

		glColor3f(0.1, 0.1, 0.1);

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.5);
		gluCylinder(qobj, 0.5, 0.5, 1.0, steps, 1);
		gluCylinder(qobj, 0.5, 0.725, 0.15, steps, 1);
		glTranslatef(0.0f, 0.0f, 0.15);
		gluDisk(qobj, 0.5, 0.725, steps, 1);
		gluCylinder(qobj, 0.65, 0.65, 0.7, steps, 1);
		glTranslatef(0.0f, 0.0f, 0.7);
		gluDisk(qobj, 0.5, 0.725, steps, 1);
		gluCylinder(qobj, 0.725, 0.5, 0.15, steps, 1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(22.5, 0.0, 0.0, 1);
		glTranslatef(0.0f, 0.0f, -0.3);
		gluDisk(qobj, 0, 0.3, 8, 1);
		glTranslatef(0.0f, 0.0f, 0.6);
		gluDisk(qobj, 0, 0.3, 8, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glRotatef(22.5, 0.0, 0.0, 1);
		glutSolidSphere(0.34, 8, 20);
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		for (int i = 0; i < 8; i++) 
		{
			glPushMatrix();
			glRotatef(i * 360 / 8, 0.0, 0.0, 1.0);
			glMultMatrixf(zShear2);
			glTranslatef(0.26, 0.0, 0.15);
			glScalef(0.52, 0.4, 0.12);
			glutSolidCube(1.0);
			glPopMatrix();
		}

		for (int i = 0; i < 8; i++) 
		{
			glPushMatrix();
			glRotatef(i * 360 / 8, 0.0, 0.0, 1.0);
			glMultMatrixf(zShear1);
			glTranslatef(0.26, 0.0, -0.15);
			glScalef(0.52, 0.4, 0.12);
			glutSolidCube(1.0);
			glPopMatrix();
		}

		for(int i = 0; i < steps / 2; i++) 
		{
			glPushMatrix();
			glRotatef(2 * i * 360.0 / steps, 0.0, 0.0, 1.0);
			glTranslatef(0.6f, 0, -0.26f);
			for (int j = 0; j < 5; j++)
			{
				glPushMatrix();
				glTranslatef(0, 0, j * 0.13);
				glScalef(0.25, 0.1, 0.1);
				glutSolidCube(1.0);
				glPopMatrix();
			}
			glPopMatrix();
		}
	}
}