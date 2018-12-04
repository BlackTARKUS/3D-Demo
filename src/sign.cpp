#include "glFuncs.h"
#include "sign.h"

// Renders a string at specified xyz coords
void renderStrokeFontString(char *string) {
	char *c;
	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
}
