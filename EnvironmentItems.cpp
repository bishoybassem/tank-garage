#include "stdafx.h"
#include "Tank1.h"
#include "glut.h"
#include "math.h"

namespace EnvironmentItems
{

	GLfloat t[8][3], bottomBench[8][3], aboveBottom [8][3];
	GLfloat top[8][3],aboveTop[8][3],side [8][3];
	GLint faces[6][4] = {  
	  {0, 1, 3, 2}, {4, 5, 7, 6},
	  {0, 4, 6, 2}, {1, 3, 7, 5},
	  {0, 1, 5, 4}, {2, 3, 7, 6},
	};
	GLfloat n[6][3] = {
		{0,0,1}, {0,0,1},
		{-1,0,0}, {1,0,0},
		{0,1,0}, {0,-1,0}
	};
	
	void drawLeg()
	{
		for (int i=0;i<8;i++)
		{
			t[i][0] = (i & 1)*0.2;
			t[i][1] = (i>>1 & 1)*3;
			t[i][2] = (i>>2 & 1)*0.2;
		}	

		glPushMatrix();
		for (int i = 0; i < 6; i++)
		{
			glBegin(GL_QUADS);
			for (int j = 0; j < 4; j++) 
			{
				glNormal3fv(n[i]);
				glVertex3fv(t[faces[i][j]]);
			}
			glEnd();
		}
		glPopMatrix();
	}

	void drawLowerBench()
	{
		glColor3d(0.9, 0.5, 0.1);
		glColor3d(0.9 / 2,0.5 / 2,0.1 / 2);
		glTranslatef(-0.2, 1.5, -5.3);
		for (int i=0;i<8;i++) 
		{
			bottomBench[i][0] = (i & 1) * 2.7;
			bottomBench[i][1] = (i>>1 & 1) * 0.3 ;
			bottomBench[i][2] = (i>>2 & 1) * 5.7;
		}	

		glPushMatrix();
		for (int i = 0; i < 6; i++)
		{
			glBegin(GL_QUADS);
			for (int j = 0; j < 4; j++) 
			{
				glNormal3fv(n[i]);
				glVertex3fv(bottomBench[faces[i][j]]);
			}
			glEnd();
		}
		glPopMatrix();
	}

	void drawAboveLower()
	{
		glColor3d(0.084314 / 1.5,0.509804 / 1.5,0.409804 / 1.5);
		glTranslatef(0.12, 0.3, 0.1);
		for (int i = 0; i < 8; i++) 
		{
			aboveBottom[i][0] = (i & 1) * 2.4;
			aboveBottom[i][1] = (i>>1 & 1) * 0.001;
			aboveBottom[i][2] = (i>>2 & 1) * 5.5;
		}	

		glPushMatrix();
		for (int i = 0; i < 6; i++)
		{
			glBegin(GL_QUADS);
			for (int j=0;j<4;j++) 
			{
				glNormal3fv(n[i]);	
				glVertex3fv(aboveBottom[faces[i][j]]);
			}
			glEnd();
		}
		glPopMatrix();
	}

	void drawTop()
	{
		glColor3d(0.9, 0.5, 0.1);
		glColor3d(0.9 / 2,0.5 / 2,0.1 / 2);
		glTranslatef(0, 1.2, 0);
		for (int i=0; i<8; i++) 
		{
			top[i][0] = (i & 1) * 2.4;
			top[i][1] = (i>>1 & 1) * 0.2;
			top[i][2] = (i>>2 & 1) * 5.5;
		}	

		glPushMatrix();

		for (int i = 0; i < 6; i++)
		{
			glBegin(GL_QUADS);
			for (int j = 0; j < 4; j++)
			{
				glNormal3fv(n[i]);
				glVertex3fv(top[faces[i][j]]);
			}
			glEnd();
		}
		glPopMatrix();
	}

	void drawAboveTop()
	{
		glColor3d(0.084314 / 1.5,0.509804  / 1.5,0.409804  / 1.5);
		glTranslatef(0,1.7,0);
		for (int i=0;i<8;i++) 
		{
			bottomBench[i][0] = (i & 1)*2.7;
			bottomBench[i][1] = (i>>1 & 1)*0.12 ;
			bottomBench[i][2] = (i>>2 & 1)*5.7;
		}	

		glPushMatrix();
		for (int i = 0; i < 6; i++)
		{
			glBegin(GL_QUADS);
			for (int j=0;j<4;j++) 
			{
				glNormal3fv(n[i]);
				glVertex3fv(bottomBench[faces[i][j]]);
			}
			glEnd();
		}
		glPopMatrix();
	}

	void drawSide()
	{
		glPushMatrix();
		glTranslatef(2.5,0.3,0.15);
		glRotatef(90,1,0,0);
		glScalef(1,1.8,1);
		drawLeg();
		glPopMatrix();
	}

	void drawTable(GLUquadricObj* qobj)
	{
		glPushMatrix();
		glTranslatef(0, -1.6, 0);

		glColor3d(0.9 / 3,0.5 / 3,0.1 / 3);

		glPushMatrix();
		glTranslatef(-6,-1,2);
		drawLeg();
		glPushMatrix();
		glTranslatef(2,0,0);
		drawLeg();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,0,-2.5);
		drawLeg();
		glTranslatef(2,0,0);
		drawLeg();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,0,-5.0);
		drawLeg();
		glTranslatef(2,0,0);
		drawLeg();
		glPopMatrix();
		glPushMatrix();
		drawLowerBench();
		glPushMatrix();
		drawAboveLower();
		drawTop();
		glPopMatrix();
		drawAboveTop();
		drawSide();
		glPopMatrix();
		glPopMatrix();

		glColor3d(0.3, 0.3, 0.3);
		glPushMatrix();
		glTranslatef(-5.6, 1.575, -1.5);

		glRotatef(90,0,1,0);
		glPushMatrix();
		glTranslatef(1,0.8,0.15);
		glRotatef(90,1,0,0);
		glScalef(1.0,0.4,0.4);
		drawLeg();
		glTranslatef(0,0,-2.8);
		glRotatef(90,1,0,0);
		drawLeg();
		glTranslatef(0,0,-2.8);
		glRotatef(90,1,0,0);
		drawLeg();
		glTranslatef(0,0,-2.8);
		glRotatef(90,1,0,0);
		drawLeg();
		glPopMatrix();
      
		glColor3d(0, 0, 1);
		glTranslatef(1,1,0.4);
		glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(1,0.2,1);
		drawLeg();
		glPopMatrix();
		glColor3d(0.3, 0.3, 0.3);
		glPushMatrix();
		glTranslatef(0.1,1.5,0.3);
		glRotatef(90,1,0,0);
		gluCylinder(qobj, 0.05, 0.05,1, 10, 1);
		glPopMatrix();

		glColor3d(0, 0, 1);
		glTranslatef(0,0.6,0);
		glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(1,0.2,1);
		drawLeg();
		glPopMatrix();

		glColor3d(0.752941,0.752941,0.752941);

		glPushMatrix();
		glTranslatef(0.1,0.9,-0.2);
		gluCylinder(qobj, 0.05, 0.05, 1, 10, 1);
		gluDisk(qobj, 0, 0.05, 10, 1);
		glTranslatef(0, 0, 1);
		gluDisk(qobj, 0, 0.05, 10, 1);
		glPopMatrix();

		glColor3d( 0,  0, 1);
		glTranslatef(0,1,0.15);
		glPushMatrix();
		glRotatef(90,1,0,0);
		glScalef(1,0.1,1);
		drawLeg();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}

	void drawBullet3(GLUquadricObj* qobj) {
		glColor3f(0, 0.5, 0);

		glPushMatrix();
		glTranslatef(0, 0, -1.2);
		glutSolidSphere(1.0, 6, 5);
		glTranslatef(0, 0, 2.4);
		glutSolidSphere(1.0, 6, 5);
		glPopMatrix();

		glColor3f(0, 1, 0);

		glPushMatrix();
		glTranslatef(0, 0, -1.7);
		glutSolidSphere(0.6, 20, 20);
		glTranslatef(0, 0, 3.4);
		glutSolidSphere(0.6, 20, 20);
		glPopMatrix();

		glColor3f(0.4, 0.4, 0.4);

		glPushMatrix();
		glTranslatef(0, 0, -0.6);
		gluCylinder(qobj, 0.5, 0.5, 1.2, 30, 1);
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		glPushMatrix();
		glTranslatef(0, 0, -2.1);
		gluCylinder(qobj, 0.6, 0.6, 1.8, 30, 1);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glTranslatef(0, 0, 1.8);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 2.1 - 1.8);
		gluCylinder(qobj, 0.6, 0.6, 1.8, 30, 1);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glTranslatef(0, 0, 1.8);
		gluDisk(qobj, 0, 0.6, 30, 1);
		glPopMatrix();
	}

	void drawBullet2(GLUquadricObj* qobj) {
		glPushMatrix();
		glRotatef(-90,1,0,0);
		gluQuadricDrawStyle(qobj, GLU_FILL);
		glColor3d(0.3, 0.3, 0.3);
		gluCylinder(qobj, 0.3, 0.3, 0.15, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.15);
		gluDisk(qobj, 0.0f, 0.3, 30, 1);
		glColor3d(0.1, 0.1, 0.1);
		gluCylinder(qobj, 0.26, 0.26, 0.15, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.15);
		gluDisk(qobj, 0.0f, 0.26, 30, 1);
		glColor3d(0.7, 0.7, 0.7);
		gluCylinder(qobj, 0.24, 0.24, 0.1, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.1);
		gluCylinder(qobj, 0.24, 0.24, 1.5, 30, 1);
		glTranslatef(0.0f, 0.0f, 1.5);
		glColor3d(0.6, 0.6, 0.6);
		gluCylinder(qobj, 0.24, 0.2, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.2);
		glColor3d(1, 1, 1);
		gluCylinder(qobj, 0.2, 0.2, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.2);
		gluDisk(qobj, 0.0f, 0.2, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0.2,0.3, 0.2);
		glTranslatef(0, 2.25f, 0);
		glRotatef(-90,1,0,0);
		glScalef(0.45,0.45,0.7);
		for (int i = 1; i < 30; i++) 
		{
			gluCylinder(qobj, 0.5 - i * 0.05, 0.5 - i * 0.05 - 0.05, 0.7f / i, 30, 1);
			glTranslatef(0.0f, 0.0f, 0.7f / i);
		} 
		glPopMatrix();
	}

	void drawBullet(GLUquadricObj* qobj) {
		glPushMatrix();
		glRotatef(-90,1,0,0);
		gluQuadricDrawStyle(qobj, GLU_FILL);
		
		glColor3f(0.66, 0.5, 0.26);

		gluDisk(qobj, 0.0f, 0.35, 30, 1);
		gluCylinder(qobj, 0.35, 0.35, 0.15, 20, 1);
		glTranslatef(0.0f, 0.0f, 0.15);
		gluDisk(qobj, 0.0f, 0.35, 30, 1);
		gluCylinder(qobj, 0.25, 0.25, 0.1, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.1);
		gluCylinder(qobj, 0.25, 0.3, 0.1, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.1);
		gluCylinder(qobj, 0.3, 0.3, 1.5, 30, 1);
		glTranslatef(0.0f, 0.0f, 1.5);
		glColor3f(0.66 / 1.5, 0.5 / 1.5, 0.26 / 1.5);
		gluCylinder(qobj, 0.3, 0.25, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.2);
		gluCylinder(qobj, 0.25, 0.25, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.2);
		gluDisk(qobj, 0.0f, 0.25, 30, 1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.82 * 0.9, 0.705 * 0.9, 0.65 * 0.9);
		glTranslatef(0, 2.25f, 0);
		glRotatef(-90,1,0,0);
		glScalef(0.55,0.55,0.55);
		for (int i = 1; i < 30; i++) 
		{
			gluCylinder(qobj, 0.5 - i * 0.05, 0.5 - i * 0.05 - 0.05, 0.7f / i, 30, 1);
			glTranslatef(0.0f, 0.0f, 0.7f / i);
		} 
		glPopMatrix();
	}

	void drawWheelTool(GLUquadricObj* qobj) {
		glPushMatrix();
		glScalef(0.65, 0.65, 0.65);
		glColor3d(0.6,0.6,0.6);
		glRotatef(45,0,1,0);
		gluCylinder(qobj, 0.15, 0.15,5, 30, 1);
		gluDisk(qobj, 0.0f, 0.25, 30, 1);
		glColor3d(0.6,0.6,0.6);
		gluCylinder(qobj, 0.25, 0.15,0.2, 30, 1);
		glColor3d(0.6,0.6,0.6);
		glPushMatrix();
		glTranslatef(0,0,-0.2);
		gluCylinder(qobj, 0.25, 0.25,0.2, 30, 1);
		gluCylinder(qobj, 0.1, 0.1,0.2, 30, 1);
		gluDisk(qobj, 0.1f, 0.25, 30, 1);
		glPopMatrix();
		glTranslatef(2.5,0 ,2.5);
		glRotatef(-90,0,1,0);
		gluCylinder(qobj, 0.15, 0.15,5, 30, 1);
		glColor3d(0.6,0.6,0.6);
		gluDisk(qobj, 0.0f, 0.25, 30, 1);
		gluCylinder(qobj, 0.25, 0.15,0.2, 30, 1);
		glColor3d(0.6,0.6,0.6);
		glPushMatrix();
		glTranslatef(0,0,-0.2);
		gluCylinder(qobj, 0.25, 0.25,0.2, 30, 1);
		gluCylinder(qobj, 0.1, 0.1,0.2, 30, 1);
		gluDisk(qobj, 0.1f, 0.25, 30, 1);
		glPopMatrix();
		glColor3d(0.6,0.6,0.6);
		glTranslatef(2.5,0 ,2.5);	   
		glRotatef(-90,0,1,0);
		gluDisk(qobj, 0.0f, 0.25, 30, 1);
		gluCylinder(qobj, 0.25, 0.15,0.2, 30, 1);
		glColor3d(0.6,0.6,0.6);
		glPushMatrix();
		glTranslatef(0,0,-0.2);
		gluCylinder(qobj, 0.25, 0.25,0.2, 30, 1);
		gluCylinder(qobj, 0.1, 0.1,0.2, 30, 1);
		gluDisk(qobj, 0.1f, 0.25, 30, 1);
		glPopMatrix();
		glColor3d(0.6,0.6,0.6);
		glTranslatef(2.5,0 ,2.5);
		glRotatef(-90,0,1,0);
		gluDisk(qobj, 0.0f, 0.25, 30, 1);
		gluCylinder(qobj, 0.25, 0.15,0.2, 30, 1);
		glColor3d(0.6,0.6,0.6);
		glPushMatrix();
		glTranslatef(0,0,-0.2);
		gluCylinder(qobj, 0.25, 0.25,0.2, 30, 1);
		gluCylinder(qobj, 0.1, 0.1,0.2, 30, 1);
		gluDisk(qobj, 0.1f, 0.25, 30, 1);
		glPopMatrix();
		glPopMatrix();
	}

	void drawGear(GLUquadricObj* qobj, int sides, float height, bool cylinder, int scale, float position)
	{
		glPushMatrix();
		float side = sin(3.14159 / sides);

		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();
		gluCylinder(qobj, 0.2, 0.2, height, 30, 1);
		gluDisk(qobj, 0.0f, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f,  height);
		gluDisk(qobj, 0.0f, 0.2, 30, 1);
		if(cylinder)
		{
			glTranslatef(0,0,-1);
			gluDisk(qobj, 0.0f, 0.1, 30, 1);
			gluCylinder(qobj, 0.1, 0.1, 1.25, 30, 1);
			glTranslatef(0,0,1.25);
			gluDisk(qobj, 0.0f, 0.1, 30, 1);
		}
		glPopMatrix();

		glColor3f(0.2, 0.2, 0.2);

		glTranslatef(0, 0, position);
		for(int i = 0; i < sides / 2; i++) 
		{
			float d = ((sides % 4 == 0)? (360.0f / sides / 2) : 0);
			glPushMatrix();
			glScalef(1,1,scale);
			glRotatef(2 * i * 360 / sides + d, 0.0, 0.0, 1.0);
			glTranslatef(0.2f + side / 2.0f, 0.0,side/1.5);
			glutSolidCube(side);
			glPopMatrix();
		}
		glPopMatrix();
	}

	void drawGear2(GLUquadricObj* qobj, int sides)
	{
		glPushMatrix();
		float side = sin(3.14159 / sides);

		glColor3f(0.7, 0.7, 0.7);

		glPushMatrix();
		gluCylinder(qobj, 0.2, 0.3, 0.6, 30, 1);
		gluDisk(qobj, 0.0f, 0.2, 30, 1);
		glTranslatef(0.0f, 0.0f, 0.6);
		gluDisk(qobj, 0.0f, 0.3, 30, 1);
		glPopMatrix();

		glColor3f(0.3, 0.3, 0.3);

		for(int i = 0; i < sides / 2; i++) 
		{
			float d = ((sides % 4 == 0)? (360.0f / sides / 2) : 0);
			glPushMatrix();
			glScalef(1,1,1);
			glRotatef(2 * i * 360 / sides + d, 0.0, 0.0, 1.0);
			glTranslatef(0.2f + side / 2.0f, 0.0,side/1.5);
			glutSolidCube(side);
			glPopMatrix();
		}

		glTranslatef(0.0f, 0.0f, 0.42);

		for(int i = 0; i < sides / 2; i++)
		{
			float d = ((sides % 4 == 0)? (360.0f / sides / 2) : 0);
			glPushMatrix();
			glScalef(1.2,1.2,1.2);
			glRotatef(2 * i * 360 / sides + d, 0.0, 0.0, 1.0);
			glTranslatef(0.2f + side / 2.0f, 0.0,side/1.5);
			glutSolidCube(side);
			glPopMatrix();
		}

		glPopMatrix();
	}

}