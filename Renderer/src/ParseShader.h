#pragma once

struct ShaderString
{
	std::string VS;
	std::string FS;

};

ShaderString ParseShader(const std::string& filePath) {

	std::ifstream stream(filePath);
	
	enum class State
	{
		None = -1,
		Vertex = 0,
		Fragment = 1

	};
	State state = State::None;

	std::stringstream SS[2];

	std::string Line;
	while (getline(stream, Line))
	{
		if (Line.find("#shader") != std::string::npos) {

			if (Line.find("vertex") != std::string::npos)
				state = State::Vertex;

			if (Line.find("fragment") != std::string::npos)
				state = State::Fragment;

		}
		else {

			if (state != State::None)
				SS[(int)state] << Line << '\n';
			std::cout << (int)state;

		}


	}

	return { SS[0].str(), SS[1].str() };

}