#ifndef GAW_ENGINE_MAIN 
#define GAW_ENGINE_MAIN 1

#include "GL/OOGL.hpp"
//#include "BufferStreamReadinator.hpp"

#include <iostream>
#include <array>
#include <fstream>
#include <filesystem> 

namespace GAWEngine
{
	void load_configs() 
	{

	};
	void initialize()
	{
		GL::Window window(800, 800, "OpenGL Window", GL::WindowStyle::Close);
		GL::Context& gl = window.GetContext();
		std::ifstream vertex_file;
		std::ifstream frag_file;


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

		return ;
	}

}
#endif