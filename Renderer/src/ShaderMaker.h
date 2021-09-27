#pragma once

unsigned int CreateShader(int ShaderType, const std::string& ShaderPrgram) {
	unsigned int ShaderID = glCreateShader(ShaderType);
	const char* InitialShaderChar = ShaderPrgram.c_str();

	glShaderSource(ShaderID, 1, &InitialShaderChar, nullptr);
	glCompileShader(ShaderID);

	//ErrrorHandle
	int Result;
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Result);
	if (Result == GL_FALSE) {
		int Lenght;
		glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &Lenght);
		char* message = (char*)alloca(sizeof(char) * Lenght);

		glGetShaderInfoLog(ShaderID, Lenght, &Lenght, message);
		std::cout << ((ShaderType == GL_VERTEX_SHADER) ? "Vertex Shader error : \n " : "Fragment Shader error : \n ") << message << std::endl;

	}

	std::cout << ((ShaderType == GL_VERTEX_SHADER) ? "Vertex Shader : \n " : "Fragment Shader : \n ");
	std::cout << ShaderPrgram << std::endl;

	return ShaderID;

}

unsigned int CreateProgram(const std::string& ShaderPath) {

	ShaderString SS = ParseShader(ShaderPath);

	unsigned int Program = glCreateProgram();
	unsigned int VS = CreateShader(GL_VERTEX_SHADER, SS.VS);
	unsigned int FS = CreateShader(GL_FRAGMENT_SHADER, SS.FS);

	glAttachShader(Program, VS);
	glAttachShader(Program, FS);

	glLinkProgram(Program);
	glValidateProgram(Program);

	glDeleteShader(VS);
	glDeleteShader(FS);

	glUseProgram(Program);

	return Program;

}