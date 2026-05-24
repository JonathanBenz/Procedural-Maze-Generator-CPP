#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
public:
	unsigned int ID;

	Shader() = default;
	~Shader();

	inline void use() { glUseProgram(ID); }

	void SetupShader(const char* vertexPath, const char* fragmentPath);
	inline void setFloat(const std::string& name, float value) const { glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }

};