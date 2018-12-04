#include "glFuncs.h"
#include "sign.h"

// Renders a string at specified xyz coords
void renderStrokeFontString( float x, float y, float z, char *string) {
	char *c;
	glTranslatef(x,y,z);

	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}

}
