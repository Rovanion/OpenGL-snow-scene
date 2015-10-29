#include <GL/gl.h>

#include "./libraries/GLUtilities.h"
#include "./libraries/LoadObject.h"
#include "./libraries/LoadTGA.h"
#include "./libraries/VectorUtils3.h"

#include "./utilities.h"

GLuint positionLocation = 0;
GLuint normalLocation   = 1;
GLuint textureLocation  = 2;

GLuint program;
GLuint texture;
Model *model;

void initializeGround(Model *_model, GLuint _program, GLuint _texture) {
	model = _model;
	program = _program;
	texture = _texture;
}

void drawGround(mat4 lookMatrix, mat4 m) {
	glUseProgram(program);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniformMatrix4fv(glGetUniformLocation(program, "viewMatrix"), 1, GL_TRUE, lookMatrix.m);
	drawModelWithLocations(model, positionLocation, normalLocation, textureLocation);
}
