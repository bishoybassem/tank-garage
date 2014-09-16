#include "stdafx.h"
#include "glut.h"
#include "math.h"

namespace TankParts
{

	const float n2 = 1.0 / sqrt(2.0);
	const float n3 = 1.0 / sqrt(3.0);

	void drawGrenadeLauncher(GLUquadricObj* qobj)
	{
		glColor3f(0.3, 0.3, 0.3);

		const float s1[] = { 
			1, 0, 0, 0,
			0.75, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		glPushMatrix();
		glTranslatef(0.03, 0, 0);
		glScalef(5.06, 0.4, 0.7);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-6, -0.7, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.45, 0.45, 1.6, 30, 1);
		gluCylinder(qobj, 0.65, 0.65, 1.6, 30, 1);
		gluDisk(qobj, 0.45, 0.65, 30, 1);
		glTranslatef(0, 0, 1.6);
		gluDisk(qobj, 0.45, 0.65, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.5, -0.7, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.7, 0.7, 5.06, 30, 1);
		gluDisk(qobj, 0, 0.7, 30, 1);
		glTranslatef(0, 0, 5.06);
		gluDisk(qobj, 0, 0.7, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(-0.55, 0.15, 0);
		glScalef(6, 0.6, 0.35);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.35, 0.35, 0.35);

		for (int i = 0; i < 13; i++) 
		{
			glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, -0.7, i * 0.4 - 2.375);
			glutSolidTorus(0.125, 0.7, 30, 30);
			glPopMatrix();
		}

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(-5.3, -0.7, 0);
		for(int i = 0; i < 16; i++) 
		{
			glPushMatrix();
			glRotatef(22.5 * i, 1, 0, 0);
			glTranslatef(0, 0.7, 0);
			glScalef(1.2, 0.2, 0.125);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.5, -0.7, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0.5, 0.5, 5.06, 30, 1);
		gluCylinder(qobj, 0.6, 0.6, 5.06, 30, 1);
		gluDisk(qobj, 0.5, 0.6, 30, 1);
		glTranslatef(0, 0, 5.06);
		gluDisk(qobj, 0.5, 0.6, 30, 1);
		glPopMatrix();
	}

	void drawIonRifle(GLUquadricObj* qobj)
	{
		const float s1[] = { 
			1, 0, 0, 0,
			0.5, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s2[] = { 
			1, 0, 0, 0,
			-0.5, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s3[] = { 
			1, 0, 0, 0,
			0, 1, 0.6, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s4[] = { 
			1, 0, 0, 0,
			0, 1, -0.6, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		glColor3f(0.3, 0.3, 0.3);

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(2.5, 0, 0);
		glPushMatrix();
		glTranslatef(0, 1.0, 0);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glScalef(9.5, 0.7, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s3);
		glTranslatef(0, 1.0, -1.2);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s4);
		glTranslatef(0, 1.0, 1.2);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.6, 0);
		glScalef(4.85, 0.5, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.2, -2.34, 0);
		glScalef(4.85, 0.5, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glMultMatrixf(s2);
		glTranslatef(1.23, -3.17, 0);
		glScalef(9.5, 1.2, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glMultMatrixf(s1);
		glScalef(0.7, 0.7, 0.7);
		glTranslatef(1.2, 0.5, 0);
		glPushMatrix();
		glTranslatef(0, 1.0, 0);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s3);
		glTranslatef(0, 1.0, -1.2);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s4);
		glTranslatef(0, 1.0, 1.2);
		glScalef(9.5, 2.0, 1.8);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.0, -1.5, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 1.0, 1.0, 5.0, 30, 1);
		gluCylinder(qobj, 1.2, 1.2, 5.0, 30, 1);
		gluDisk(qobj, 1.0, 1.2, 30, 1);
		glTranslatef(0, 0, 5.0);
		gluDisk(qobj, 1.0, 1.2, 30, 1);
		glPopMatrix();

		glColor3f(0.08, 0.55, 0.71);

		glPushMatrix();
		glTranslatef(-2.5, 0, 0);
		for(int i = 0; i < 5; i++)
		{
			glTranslatef(1.75, 0, 0);
			for(int j = 0; j < 3; j++)
			{
				glPushMatrix();
				glRotatef(-20, 0, 0, 1);
				glRotatef(-140 + 50 * j, 1, 0, 0);
				gluCylinder(qobj, 0.4, 0.4, (j == 1)? 2.85 : 2.45, 30, 1);
				glTranslatef(0, 0, (j == 1)? 2.85 : 2.45);
				gluDisk(qobj, 0, 0.4, 30, 1);
				glPopMatrix();
			}
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.4, -1.5, 0);
		for(int i = 0; i < 10; i++) 
		{
			glTranslatef(0.5, 0, 0);
			glPushMatrix();
			glRotatef(90, 0, 1, 0);
			gluCylinder(qobj, 2.0, 2.0, 0.3, 30, 1);
			gluDisk(qobj, 0, 2.0, 30, 1);
			glTranslatef(0, 0, 0.3);
			gluDisk(qobj, 0, 2.0, 30, 1);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5.5, -1.5, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0, 0.6, 3.0, 6, 1);
		glTranslatef(0, 0, 3.0);
		gluCylinder(qobj, 0.6, 0.6, 3.0, 6, 1);
		glPopMatrix();

		glColor3f(0.1, 0.7, 0.89);

		glPushMatrix();
		glTranslatef(1.8, -1.5, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 1.8, 1.8, 5.0, 30, 1);
		gluDisk(qobj, 0, 1.8, 30, 1);
		glTranslatef(0, 0, 5.0);
		gluDisk(qobj, 0, 1.8, 30, 1);
		glColor3f(0.3, 0.3, 0.3);
		gluCylinder(qobj, 1.375, 1.375, 1.0, 30, 1);
		glTranslatef(0, 0, 1.0);
		gluDisk(qobj, 0, 1.375, 30, 1);
		glPopMatrix();
	}

	void drawPlasmaRifle(GLUquadricObj* qobj)
	{
		const float s1[] = { 
			1, 0, 0, 0,
			1, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s2[] = { 
			1, 0, 0, 0,
			-0.8, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		glColor3f(0.5, 0.5, 0.5);

		for (int i = 0; i < 4; i++) 
		{
			glPushMatrix();
			glRotatef(90 * i, 1, 0, 0);
			glTranslatef(0, 2.5, 0);
			glPushMatrix();
			glMultMatrixf(s1);
			glTranslatef(2.0, 1.5, 0);
			glScalef(4.0, 3.0, 0.5);
			glutSolidCube(1.0);
			glPopMatrix();
			glPushMatrix();
			glMultMatrixf(s2);
			glTranslatef(8.0, 0.75, 0);
			glScalef(8.0, 1.5, 0.5);
			glutSolidCube(1.0);
			glPopMatrix();
			glPushMatrix();
			glMultMatrixf(s1);
			glTranslatef(1.0, -0.75, 0);
			glScalef(2.0, 1.5, 0.5);
			glutSolidCube(1.0);
			glPopMatrix();
			glPopMatrix();
		}

		glColor3f(0.3, 0.3, 0.3);

		glPushMatrix();
		glTranslatef(3.0, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 3.5, 3.5, 0.5, 30, 1);
		gluDisk(qobj, 0, 3.5, 30, 1);
		glTranslatef(0, 0, 0.5);
		gluDisk(qobj, 0, 3.5, 30, 1);
		glColor3f(0, 1, 0);
		gluCylinder(qobj, 3.0, 3.0, 6.0, 30, 1);
		glTranslatef(0, 0, 6.0);
		glColor3f(0.3, 0.3, 0.3);
		gluCylinder(qobj, 3.5, 3.5, 0.5, 30, 1);
		gluDisk(qobj, 0, 3.5, 30, 1);
		glTranslatef(0, 0, 0.5);
		gluDisk(qobj, 0, 3.5, 30, 1);
		glColor3f(0.5, 0.5, 0.5);
		gluCylinder(qobj, 3.0, 3.0, 1.0, 30, 1);
		glTranslatef(0, 0, 1.0);
		gluDisk(qobj, 0, 3.0, 30, 1);
		glColor3f(0.3, 0.3, 0.3);
		gluCylinder(qobj, 2.6, 2.6, 1.75, 30, 1);
		glTranslatef(0, 0, 1.75);
		gluDisk(qobj, 0, 2.6, 30, 1);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(6.5, 0, 0);
		for(int i = 0; i < 8; i++) 
		{
			glPushMatrix();
			glRotatef(22.5 * i, 1, 0, 0);
			glScalef(6.5, 6.7, 0.3);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.5, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 1.0, 1.0, 3.0, 30, 1);
		gluDisk(qobj, 0, 1.0, 30, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(2.5, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 2.3, 2.3, 1.0, 30, 1);
		gluCylinder(qobj, 2.75, 2.75, 1.0, 30, 1);
		gluDisk(qobj, 2.3, 2.75, 30, 1);
		glPopMatrix();

		glColor3f(0, 1, 0);

		glPushMatrix();
		glTranslatef(-0.75, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0, 0.9, 4.0, 6, 1);
		glPopMatrix();
	}

	void drawLaserRifle(GLUquadricObj* qobj)
	{
		const float s1[] = { 
			1, 0, 0, 0,
			0.8, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s2[] = { 
			1, 0, 0, 0,
			-0.8, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s3[] = { 
			1, 0, 0, 0,
			-0.2, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s4[] = { 
			1, 0, 0, 0,
			-1.2, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float s5[] = { 
			1, 0, 0, 0,
			0.5, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		
		glColor3f(0.41, 0.22, 0.22);

		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(2.0, 0.5, 0);
		glScalef(8.0, 1.0, 1.0);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s3);
		glTranslatef(2.0, -0.4, 0);
		glScalef(8.0, 0.8, 1.0);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s3);
		glTranslatef(2.0, -2.05, 0);
		glScalef(8.0, 0.7, 0.7);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s4);
		glTranslatef(-0.4, -2.75, 0);
		glScalef(8.0, 0.7, 0.7);
		glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.53, 0.27, 0.27);

		glPushMatrix();
		glTranslatef(1.3, 0.375, 0);
		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(0, 0.6, 0);
		glScalef(2.5, 1.2, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, -0.35, 0);
		glScalef(2.5, 0.7, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s2);
		glTranslatef(2.5, 0.6, 0);
		glScalef(3.0, 1.2, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(0.6, -0.35, 0);
		glScalef(2.5, 0.7, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		glPushMatrix();
		glMultMatrixf(s5);
		glTranslatef(3.75, -2.7, 0);
		glScalef(6.0, 0.9, 1.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.5, 0.6, 0);
		glScalef(0.7, 0.7, 1.3);
		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(0, 0.5, 0);
		glScalef(2.5, 1.0, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, -0.35, 0);
		glScalef(2.5, 0.7, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s2);
		glTranslatef(2.5, 0.5, 0);
		glScalef(3.0, 1.0, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(0.6, -0.35, 0);
		glScalef(2.5, 0.7, 1.3);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(2.6, -1.15, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 1.0, 1.0, 3.75, 30, 1);
		gluDisk(qobj, 0, 1.0, 30, 1);
		glTranslatef(0, 0, 3.75);
		gluDisk(qobj, 0, 1.0, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.6, 0, -0.6);
		gluCylinder(qobj, 0.15, 0.15, 1.2, 30, 1);
		gluDisk(qobj, 0, 0.15, 30, 1);
		glTranslatef(0, 0, 1.2);
		gluDisk(qobj, 0, 0.15, 30, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1.2, 0.5, -0.6);
		gluCylinder(qobj, 0.15, 0.15, 1.2, 30, 1);
		gluDisk(qobj, 0, 0.15, 30, 1);
		glTranslatef(0, 0, 1.2);
		gluDisk(qobj, 0, 0.15, 30, 1);
		glPopMatrix();

		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(2.8, -1.15, 0);
		glRotatef(90, 0, 1, 0);
		for (int i = 0; i < 6; i++) 
		{
			gluCylinder(qobj, 1.8, 1.8, 0.2, 30, 1);
			gluDisk(qobj, 0, 1.8, 30, 1);
			glTranslatef(0, 0, 0.2);
			gluDisk(qobj, 0, 1.8, 30, 1);
			glTranslatef(0, 0, 0.2);
		}
		glPopMatrix();

		glColor3f(0.91, 0.04, 0.08);

		glPushMatrix();
		glTranslatef(-1.8, -1.25, 0);
		glRotatef(30, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		gluCylinder(qobj, 0, 0.35, 1.5, 6, 1);
		glTranslatef(0, 0, 1.5);
		gluCylinder(qobj, 0.35, 0.35, 4.0, 6, 1);
		glPopMatrix();

	}

	void drawGatlingGun(GLUquadricObj* qobj) 
	{
		glPushMatrix();
		float angle;

		glColor3f(0.5, 0.5, 0.5);

		for (int i = 0; i < 6; i++) 
		{
			glPushMatrix();
			angle = i * 2 * 3.141592653589793238462 / 6;
			glTranslatef(cos(angle) * 0.35, sin(angle) * 0.35, 0);		
			gluCylinder(qobj, 0.13, 0.13, 2.5, 10, 1);
			glTranslatef(0, 0, 2.5);
			gluCylinder(qobj, 0.12, 0.12, 0.3, 10, 1);
			glTranslatef(0, 0, 0.3);
			gluDisk(qobj, 0.0f, 0.12, 20, 1);
			gluCylinder(qobj, 0.1, 0.1, 2.0, 10, 1);
			glTranslatef(0, 0, 1.9);
			gluCylinder(qobj, 0.11, 0.11, 0.12, 10, 1);
			gluCylinder(qobj, 0.06, 0.06, 0.12, 10, 1);
			glTranslatef(0, 0, 0.12);
			gluDisk(qobj, 0.06f, 0.11f, 10, 1);
			glPopMatrix();
		}

		glColor3f(0.45, 0.45, 0.45);

		glPushMatrix();
		glTranslatef(0, 0, 2.35);
		gluCylinder(qobj, 0.53, 0.53, 0.3, 20, 1);
		gluDisk(qobj, 0.0f, 0.53, 20, 1);
		glTranslatef(0, 0, 0.3);
		gluDisk(qobj, 0.0f, 0.53, 20, 1);
		gluCylinder(qobj, 0.2, 0.2, 2.07, 20, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 3.6);
		gluCylinder(qobj, 0.53, 0.53, 0.07, 20, 1);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glTranslatef(0, 0, 0.07);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glTranslatef(0, 0, 0.6);
		gluCylinder(qobj, 0.53, 0.53, 0.07, 20, 1);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glTranslatef(0, 0, 0.07);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glTranslatef(0, 0, 0.3);
		gluCylinder(qobj, 0.53, 0.53, 0.07, 20, 1);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glTranslatef(0, 0, 0.07);
		gluDisk(qobj, 0.2, 0.53, 20, 1);
		glPopMatrix();

		glPopMatrix();
	}

	void drawCannon(GLUquadricObj* qobj) 
	{	
		glColor3f(0.5, 0.5, 0.5);

		glPushMatrix();
		glTranslatef(0, 0, 1.7f);
		gluDisk(qobj, 0, 0.23, 20, 1);
		gluCylinder(qobj, 0.23, 0.23, 2.5, 20, 1);
		glColor3f(0.45, 0.45, 0.45);
		glTranslatef(0, 0, 1.95f);
		glutSolidTorus(0.07, 0.27, 20, 20);
		glTranslatef(0, 0, 0.2f);
		glutSolidTorus(0.07, 0.27, 20, 20);
		glTranslatef(0, 0, 0.2f);
		glutSolidTorus(0.07, 0.27, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 4.2f);
		gluCylinder(qobj, 0.4, 0.4, 0.8, 8, 1);
		gluCylinder(qobj, 0.33, 0.33, 0.8, 8, 1);
		gluDisk(qobj, 0.23, 0.4, 8, 1);
		glTranslatef(0.0f, 0.0f, 0.8);
		gluDisk(qobj, 0.33, 0.4, 8, 1);
		glPopMatrix();
	}

	void drawCenter(GLUquadricObj* qobj) {
		glColor3f(0.66, 0.5, 0.26);

		glPushMatrix();
		glTranslatef(-3.15, 0, 0);

		glPushMatrix();
		glTranslatef(3.15, -0.16, 0);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(qobj, 1.9, 1.7, 0.55, 12, 1);
		gluDisk(qobj, 0.0f, 1.9, 12, 1);
		glTranslatef(0.0f, 0.0f, 0.55);
		gluDisk(qobj, 0.0f, 1.7, 12, 1);
		glPopMatrix();

		glColor3f(0.61, 0.57, 0.42);

		glPushMatrix();
		glTranslatef(3.15, 0.3, 0);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(qobj, 1.5, 1.3, 0.3, 10, 1);
		gluDisk(qobj, 0.0f, 1.5, 10, 1);
		glTranslatef(0.0f, 0.0f, 0.3);
		gluDisk(qobj, 0.0f, 1.3, 10, 1);
		glPopMatrix();

		glPopMatrix();
	}

}