#include "BlockShader.h"

BlockShader::BlockShader(const char *vertex_path, const char *fragment_path) : StaticShader(vertex_path, fragment_path) {
	position = glGetAttribLocation(program, "position");
	tex = glGetAttribLocation(program, "texcoord");
}

void BlockShader::bind() {
	glUseProgram(program);

	int size = 5;

	glEnableVertexAttribArray(position);
	glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, size * sizeof(GLfloat), 0);

	glEnableVertexAttribArray(tex);
	glVertexAttribPointer(tex, 2, GL_FLOAT, GL_FALSE, size * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
}

void BlockShader::unbind() {
	glDisableVertexAttribArray(position);
	glDisableVertexAttribArray(tex);
}