#include "pch.h"
#include "OpenGLFramework.h"


#include <Core/Debugging/Debug.h>
#include <GL/glew.h>
 
void OpenGLFramework::Init(Ref<ApplicationInfo> init_info, SDL_Window* window)
{
	glewExperimental = GL_TRUE;
	GLenum result = glewInit();
	if (result != GLEW_OK) {
		std::string error_text = "Glew init failed with error code: ";
		error_text += result;
		LP_CORE_ERROR(error_text);
	}
	this->window_access = window;
}

void OpenGLFramework::Tick()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLFramework::SwapWindow()
{
	SDL_GL_SwapWindow(this->window_access);
}

void OpenGLFramework::Cleanup()
{
}

void OpenGLFramework::OnSdlSetup()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}
