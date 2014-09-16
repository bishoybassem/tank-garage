#include "glut.h"

namespace Tank2
{
	void drawHead(GLUquadricObj*, float, float, int);
	void drawMask(GLUquadricObj* qobj);
	void drawFront(GLUquadricObj*, float);
	void drawFrontRight(GLUquadricObj*, float);
	void drawFrontLeft(GLUquadricObj*, float);
	void drawRear(GLUquadricObj*, float);
	void drawWheel(GLUquadricObj*, int);
	void drawBackCover(GLUquadricObj*);
}