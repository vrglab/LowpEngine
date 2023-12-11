#include "pch.h"
#include "OpenGLFramework.h"

#include <Core/Debugging/Debug.h>
#include <GL/glew.h>

void OpenGLFramework::Init()
{
	if (glewInit() != GLEW_OK) {
		LP_CORE_ERROR("OpenGL Glew failed");
	}
}

void OpenGLFramework::Tick()
{
}

void OpenGLFramework::Cleanup()
{
}
