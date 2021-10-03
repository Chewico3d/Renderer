#pragma once

void SetUniform4f(const char* name, unsigned int ShaderID, float r,float g, float b) {
	int Location = glGetUniformLocation(ShaderID, name);
	glUniform4f(Location, r, g, b, 1);

}