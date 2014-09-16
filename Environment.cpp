#include "stdafx.h"
#include "Tank1.h"
#include "glut.h"
#include "math.h"
#include "Tank1.h"
#include "Tank2.h"
#include "Tank3.h"
#include "TankParts.h"
#include "EnvironmentItems.h"

namespace Environment
{
	void drawBase(GLUquadricObj* qobj, GLuint* tex) 
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glTranslatef(0, -0.6, 0);
		glRotatef(90, 1, 0, 0);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glBindTexture(GL_TEXTURE_2D, tex[0]);
		gluDisk(qobj, 0.0, 4.57, 100, 1);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glScalef(3, 1, 1);
		glMatrixMode(GL_MODELVIEW);
		glBindTexture(GL_TEXTURE_2D, tex[1]);
		gluCylinder(qobj, 4.5, 5.5, 2.0, 100, 1);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawFloor(GLuint* tex) 
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glBindTexture(GL_TEXTURE_2D, tex[2]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(0, 1, 0);
		glVertex3f(-21, -2.5, -30);
		glTexCoord2f(1, 1);
		glNormal3f(0, 1, 0);
		glVertex3f(-21, -2.5, 30);
		glTexCoord2f(1, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(21, -2.5, 30);
		glTexCoord2f(0, 0);
		glNormal3f(0, 1, 0);
		glVertex3f(21, -2.5, -30);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawCeiling(GLuint* tex) 
	{
		glPushMatrix();
		glTranslatef(0, 9.35, 0);
		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glBindTexture(GL_TEXTURE_2D, tex[2]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(0, -1, 0);
		glVertex3f(-21.0, -2.5, -30);
		glTexCoord2f(1, 1);
		glNormal3f(0, -1, 0);
		glVertex3f(-21.0, -2.5, 30);
		glTexCoord2f(1, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(21.0, -2.5, 30);
		glTexCoord2f(0, 0);
		glNormal3f(0, -1, 0);
		glVertex3f(21.0, -2.5, -30);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawWall1(GLUquadricObj* qobj, GLuint* tex) 
	{
		glPushMatrix();
		glTranslatef(0, 0, -27.5);
		glRotatef(90, 0, 1, 0);

		glPushMatrix();
		glColor3f(1, 1, 1);
		
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
		glTranslatef(2.45, 1.9, 0);
		glBindTexture(GL_TEXTURE_2D, tex[4]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, -4.5, -14.0);
		glTexCoord2f(1, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, -4.5, -7.0);
		glTexCoord2f(1, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, 5, -7.0);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, 5, -14.0);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, -4.5, 7);
		glTexCoord2f(1, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, -4.5, 14.0);
		glTexCoord2f(1, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, 5, 14.0);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(-0.05, 5, 7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, tex[3]);

		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, -21);
		glTexCoord2f(4, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, 21);
		glTexCoord2f(4, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, 21);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, -21);
		glEnd();

		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, tex[5]);
		glTranslatef(0, 0.65, 0);
		for (int i = -1; i < 2; i++) 
		{
			glPushMatrix();
			glTranslatef(0, -3.4, i * 3.5);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(qobj, 1.2, 1.2, 4.0, 30, 1);
			glTranslatef(0, 0, 4.0);
			gluDisk(qobj, 0.0f, 1.2f, 30, 1);
			glPopMatrix();
		}
		glDisable(GL_TEXTURE_2D);
		glTranslatef(0, 0, -3.5); 
		Tank1::drawMask(qobj);
		glTranslatef(0, 0, 3.5); 
		Tank2::drawMask(qobj);
		glTranslatef(0, 0, 3.5); 
		Tank3::drawMask(qobj);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPopMatrix();
	}

	void drawWall2(GLuint* tex) 
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(21.0, 1.9, 0);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex[3]);
		glMatrixMode(GL_MODELVIEW);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, -30);
		glTexCoord2f(5, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, 30);
		glTexCoord2f(5, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, 30);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, -30);
		glEnd();

		glTranslatef(-0.05, 0.435, -30);
		for (int i = 6; i < 9; i++)
		{
			glTranslatef(0, 0, 15);
			glBindTexture(GL_TEXTURE_2D, tex[i]);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 1);
			glNormal3f(-1, 0, 0);
			glVertex3f(0, -2.175, -2.9);
			glTexCoord2f(1, 1);
			glNormal3f(-1, 0, 0);
			glVertex3f(0, -2.175, 2.9);
			glTexCoord2f(1, 0);
			glNormal3f(-1, 0, 0);
			glVertex3f(0, 2.175, 2.9);
			glTexCoord2f(0, 0);
			glNormal3f(-1, 0, 0);
			glVertex3f(0, 2.175, -2.9);
			glEnd();
		}

		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	
	void drawWall3(GLuint* tex) 
	{
		glPushMatrix();
		glTranslatef(0, 0, 27.5);
		glRotatef(-90, 0, 1, 0);
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(2.45, 1.9, 0);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glBindTexture(GL_TEXTURE_2D, tex[3]);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, -21);
		glTexCoord2f(4, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, 21);
		glTexCoord2f(4, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, 21);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, -21);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPopMatrix();
	}

	void drawWall4(GLuint* tex) 
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(180, 0, 1, 0);
		glTranslatef(21, 1.9, 0);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, tex[3]);
		glMatrixMode(GL_MODELVIEW);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, -30);
		glTexCoord2f(5, 1);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, -4.5, 30);
		glTexCoord2f(5, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, 30);
		glTexCoord2f(0, 0);
		glNormal3f(-1, 0, 0);
		glVertex3f(0, 5, -30);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	}
	
	void drawWeaponsBoard(GLUquadricObj* qobj) 
	{
		const float s1[] = { 
			1, 0, 0, 0,
			0, 1, -0.5, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		glPushMatrix();
		glTranslatef(0, 0, -27.5);
		glRotatef(90, 0, 1, 0);
		glTranslatef(2.25 + 0.15, 1.5, -0.7);

		glPushMatrix();
		glTranslatef(0, 0, 3.0);
		glRotatef(180, 0, 1, 0);
		TankParts::drawCannon(qobj);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0.2, 2.25);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.18, 0.18, 0.18);
		TankParts::drawLaserRifle(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 1.15, 0);
		glPushMatrix();
		glTranslatef(0, 0.225, 0.475);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.32, 0.32, 0.32);
		TankParts::drawGrenadeLauncher(qobj);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 2.25);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.09, 0.09, 0.09);
		TankParts::drawPlasmaRifle(qobj);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 2.1, 0);
		glPushMatrix();
		glColor3f(0.35, 0.35, 0.35);
		glTranslatef(0, 0, 1.1);
		glRotatef(-180, 0, 1, 0);
		glPushMatrix();
		glScalef(1.05, 1.05, 1.05);
		glTranslatef(0, 0, -0.18);
		glPushMatrix();
		gluCylinder(qobj, 0.215, 0.215, 0.64f, 20, 1);
		glTranslatef(0.0f, 0, 0.64f);
		gluDisk(qobj, 0.0f, 0.215, 20, 1);
		glPopMatrix();
		glPushMatrix();
		glMultMatrixf(s1);
		glTranslatef(0, 0.21, 0.25);
		glScalef(0.07, 0.3, 0.4);
		glutSolidCube(1.0);
		glPopMatrix();
		gluCylinder(qobj, 0.25, 0.25, 0.6f, 20, 1);
		gluDisk(qobj, 0.0f, 0.25, 20, 1);
		glTranslatef(0.0f, 0, 0.6f);
		gluDisk(qobj, 0.0f, 0.25, 20, 1);
		glPopMatrix();
		glPushMatrix();
		glScalef(0.42, 0.42, 0.42);
		TankParts::drawGatlingGun(qobj);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0.175, 2.47);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.12, 0.12, 0.12);
		TankParts::drawIonRifle(qobj);	
		glPopMatrix();
		glPopMatrix();
		
		glPopMatrix();
	}

	void drawToolCorner(GLUquadricObj* qobj)
	{
		glPushMatrix();
		glTranslatef(9.0, -2.4, 13.5);
		glRotatef(-90, 1, 0, 0);
		glScalef(1.75, 1.75, 1.5);
		Tank1::drawWheel(qobj, 30, true);
		glTranslatef(1, 1.35, 0);
		Tank1::drawWheel(qobj, 30, true);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(12.5, -1.2, 8.5);
		glRotatef(90, 0, 1, 0);
		glScalef(2.5, 2.5, 2.5);
		Tank2::drawWheel(qobj, 40);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, -1.8, 8.5);
		glRotatef(-90, 1, 0, 0);
		glScalef(1.4, 1.4, 1.4);
		Tank3::drawWheel(qobj, 50);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(7.5, -1.5, 10.2);
		glScalef(1.4, 1.4, 1.0);
		glRotatef(-45, 1, 0, 0);
		Tank3::drawWheel(qobj, 50);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(10, 0, 22.75);
		glRotatef(-90, 0, 1, 0);
		EnvironmentItems::drawTable(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(12.175, -2.3, 13);
		glRotatef(45, 0, 0, 1);
		EnvironmentItems::drawWheelTool(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.5, -1.8, 17.5);
		glScalef(2.0, 2.0, 2.0);
		EnvironmentItems::drawGear(qobj, 26, 0.8, false, 3, 0.15);
		glTranslatef(-1.0, 0, -0.2);
		EnvironmentItems::drawGear(qobj, 20, 0.8, true, 3, 0.1);
		glTranslatef(-1.0, 0, 0.3);
		EnvironmentItems::drawGear2(qobj, 22);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(6.5, -2.5, 18.75);
		EnvironmentItems::drawBullet2(qobj);
		glTranslatef(0, 0, -1.0);
		EnvironmentItems::drawBullet2(qobj);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(5.25, -2.5, 18.75);
		EnvironmentItems::drawBullet2(qobj);
		glTranslatef(0, 0, -1.0);
		EnvironmentItems::drawBullet2(qobj);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(4, -2.5, 18.75);
		EnvironmentItems::drawBullet2(qobj);
		glTranslatef(0, 0, -1.0);
		EnvironmentItems::drawBullet2(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(12, 0.71, 18.5);
		glScalef(0.15, 0.25, 0.15);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(-1, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(-1, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(0, 0, -1);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(1, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(1, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(11.75, 0.82, 18.0);
		glScalef(0.15, 0.15, 0.25);
		glRotatef(-90, 1, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glTranslatef(1.5, 0, 0);
		EnvironmentItems::drawBullet(qobj);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.75, 0.89, -0.75);
		glPushMatrix();
		glTranslatef(11.75, 0, 18.0);
		glScalef(0.225, 0.225, 0.225);
		EnvironmentItems::drawBullet3(qobj);
		glRotatef(-30, 0, 1, 0);
		glTranslatef(5.0, 0, 2.0);
		EnvironmentItems::drawBullet3(qobj);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(10.5, 0, 19.0);
		glScalef(0.225, 0.225, 0.225);
		glRotatef(90, 0, 1, 0);
		EnvironmentItems::drawBullet3(qobj);
		glPopMatrix();
		glPopMatrix();
	}
}