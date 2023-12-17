#include "pch.h"
#include "VulkanFramework.h"

void VulkanFramework::Init(Ref<ApplicationInfo> app_info, SDL_Window* window)
{
	LP_CORE_ERROR("Starting Vulkan");
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = app_info->name.c_str();
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "LowpEngine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		LP_CORE_ERROR("Vulkan creation failed");
	}
}

void VulkanFramework::Tick()
{
}

void VulkanFramework::SwapWindow()
{
}

void VulkanFramework::Cleanup()
{
}
