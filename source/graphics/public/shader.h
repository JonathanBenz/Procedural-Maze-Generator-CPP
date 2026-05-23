#pragma once
#include <glad/glad.h>

class Shader
{
public:
	unsigned int ID;

	Shader() = default;
	~Shader();

	inline void use() { glUseProgram(ID); }

	void SetupShader(const char* vertexPath, const char* fragmentPath);
};