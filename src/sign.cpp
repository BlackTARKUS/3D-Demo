#include "glFuncs.h"
#include "sign.h"

// Renders a string at specified xyz coords
void renderStrokeFontString( float x, float y, float z, char *string) {
	char *c;
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.008,0.008,1.0);
	glRotatef(0.0,0.25,0.0,0.25);

	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}

	glPopMatrix();
}
