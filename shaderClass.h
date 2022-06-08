#ifndef SHADERCLASS_H
#define SHADERCLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
	//checks if the shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
	public:
		GLuint ID;
		Shader(const char* vertexFile, const char* fragmentFile);
		Shader(const char* vertexFile, const char* fragmentFile, const char* geometryFile);

		void Activate();
		void Delete();
};

#endif