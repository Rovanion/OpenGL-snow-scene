#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glext.h>

#include "./libraries/GLUtilities.h"
#include "./libraries/LoadObject.h"
#include "./libraries/LoadTGA.h"
#include "./libraries/VectorUtils3.h"

#include "./utilities.h"

GLuint positionLocation = 0;
GLuint normalLocation   = 1;
GLuint textureLocation  = 2;
GLuint matrixLocation   = 3;

GLuint program;
GLuint texture;

void initializeGround(Model *_model, GLuint _program, GLuint _texture) {
	model = _model;
	program = _program;
	texture = _texture;
}

void drawGround(GLFloat *lookMatrix) {
	glUseProgram(program);
	glBindTexture(GL_TEXTURE_2D, texture);

	glUniformMatrix4fv(glGetUniformLocation(program, "lookMatrix"), 1, GL_TRUE, lookMatrix);
	drawModelWithLocations(model, positionLocation, normalLocation, textureLocation);
}