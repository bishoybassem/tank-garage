#include "glut.h"

namespace Tank3
{
	void drawHead(GLUquadricObj*, float, float, int);
	void drawMask(GLUquadricObj* qobj);
	void drawRear(GLUquadricObj*, float);
	void drawRearRightSide(GLUquadricObj*);
	void drawRearLeftSide(GLUquadricObj*);
	void drawRearCenter(GLUquadricObj*);
	void drawFront(GLUquadricObj*, float);
	void drawFrontCenter(GLUquadricObj*);
	void drawFrontSides(GLUquadricObj*, float);
	void drawFrontWheelCover(GLUquadricObj*, bool);
	void drawWheel(GLUquadricObj*, int);
}