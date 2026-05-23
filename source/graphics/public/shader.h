#pragma once
#include <glad/glad.h>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	inline void use() { glUseProgram(ID); }
};