
/*
	this file must be compiled.
	cmakebuild target OOGL_EXE is assumed to exist in all src sub dirs, not too sure about include it probably doesn't even need shit

*/


#include "GL/OOGL.hpp"
#include <iostream>
#include <array>
#include <fstream>
#include <filesystem> 


int main()
{
	GL::Window window(800, 800, "OpenGL Window", GL::WindowStyle::Close);
	GL::Context& gl = window.GetContext();
	std::ifstream vertex_file;
	std::ifstream frag_file;
	
	using recursive_directory_iterator = std::filesystem::directory_iterator;
	using std::filesystem::path;

	GL::Shader vert;
	GL::Shader frag;
	std::filesystem::path script_path(SCRIPTS);
	vert = GL::Shader(GL::ShaderType::Vertex, script_path / "demo_vertex.glsl");

	frag = GL::Shader(GL::ShaderType::Fragment, script_path / "demo_frag.glsl");





	GL::Program program(vert, frag);

	float vx = .01, vy = .01;

	GL::Event ev;
	while (window.IsOpen())
	{
		while (window.GetEvent(ev))
		{
			if (1)
			{
				if (ev.Key.Code == GL::Key::W) {
				}
				if (ev.Key.Code == GL::Key::S) {

				}
			}
		};

		gl.Clear();
		
		window.Present();
	}

	return 0;
}
