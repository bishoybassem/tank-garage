#include "glut.h"

namespace Tank1
{
	void drawFront(GLUquadricObj*, float);
	void drawMask(GLUquadricObj* qobj);
	void drawRear(GLUquadricObj*, float);
	void drawHead(GLUquadricObj*, float, float, float, int);
	void drawWheel(GLUquadricObj*, int, bool);
	void drawFrontCover(GLUquadricObj*);
	void drawBackCover(GLUquadricObj*);
}