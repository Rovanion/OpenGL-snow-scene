#version 150
#extension GL_ARB_explicit_attrib_location : enable

// "position" and "normal" are regular vertex attributes
layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;

// Color is a per-instance attribute
layout (location = 2) in vec2 textureCoordinates;
layout (location = 3) in vec4 test;

// model_matrix will be used as a per-instance transformation
// matrix. Note that a mat4 consumes 4 consecutive locations, so
// this will actually sit in locations, 3, 4, 5, and 6.
layout (location = 4) in mat4 model_matrix;
// The view matrix and the projection matrix are constant
// across a draw
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

// The output of the vertex shader (matched to thead// fragment shader)
out vec3 vertNormal;
out	vec2 vertTextureCoordinates;
out	vec4 vertTest;

void main(void)
{
	// Construct a model-view matrix from the uniform view matrix
	// and the per-instance model matrix.
	mat4 model_view_matrix = viewMatrix * model_matrix;

	// Transform position by the model-view matrix, then by thead
	// projection matrix.
	gl_Position = projectionMatrix * viewMatrix * position;
	// Transform the normal by the upper-left-3x3-submatrix of thead    // model-view matrix
	vertNormal =  normal;
	vertTest = test;
	// Pass the per-instance color through to the fragment shader.
	vertTextureCoordinates = textureCoordinates;


}