#include "pch.h"
#include "OpenGLFramework.h"

#include <Core/Debugging/Debug.h>
#include <GL/glew.h>

void OpenGLFramework::Init()
{
	

	GLenum result = glewInit();
	if (result != GLEW_OK) {
		std::string error_text = "Glew init failed with error code: ";
		error_text += result;
		LP_CORE_ERROR(error_text);
	}
}

void OpenGLFramework::Tick()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLFramework::SwapWindow(SDL_Window* window)
{
	SDL_GL_SwapWindow(window);
}

void OpenGLFramework::Cleanup()
{
}
