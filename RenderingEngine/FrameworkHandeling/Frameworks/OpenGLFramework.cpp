#include "pch.h"
#include "OpenGLFramework.h"


#include <Core/Debugging/Debug.h>
#include <GL/glew.h>
#include <SceneEngine/SceneManager.h>
 
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
#ifdef GAME
	float* clear_Color = static_cast<float*>(current_scene->GetConfig("bgd_color"));
	glClearColor(clear_Color[0], clear_Color[1], clear_Color[2], clear_Color[3]);
#endif
#ifdef EDITOR
	glClearColor(0, 0, 0, 0);
#endif

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
