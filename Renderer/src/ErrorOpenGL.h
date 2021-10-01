#pragma once

static void GLCleatError() {

	while (glGetError() != GL_NO_ERROR);
}

static bool GLLocCall() {
	bool ThereWasError = true;
	while (GLenum error = glGetError())
	{
		std::cout << "[Open Gl Errror] : " << error << std::endl;
		ThereWasError = false;
	}

	return true;
}