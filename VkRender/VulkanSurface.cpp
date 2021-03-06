#include "VulkanSurface.h"

#include <GLFW/glfw3.h>

#include <vector>

void VulkanSurface::Initialize(VkInstance instance, VkPhysicalDevice physicalDevice){
    r_instance = instance;
    r_physicalDevice = physicalDevice;

    // create window
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	m_window = glfwCreateWindow(1024, 768, "VkRender", 0, 0); // TODO: fix hardcodeed values
    assert(m_window);

    // create surface
    VK_CHECK(glfwCreateWindowSurface(r_instance, m_window, NULL, &m_vk_surface));
}

std::vector<const char*> VulkanSurface::GetRequiredExtension(){
    uint32_t glfwExtensionsNum = 0;
	const char ** glfwxtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsNum);
    std::vector<const char*> extensions(glfwExtensionsNum);
    for (size_t i = 0u; i < glfwExtensionsNum; i++){
        extensions[i] = glfwxtensions[i];
    }

    return extensions;
}

bool VulkanSurface::CheckPresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) const{
    return glfwGetPhysicalDevicePresentationSupport(r_instance, physicalDevice, queueFamilyIndex);
}

void VulkanSurface::GetWindowsExtent(uint32_t &width, uint32_t &height) const{
    VkSurfaceCapabilitiesKHR surfaceCaps;
	VK_CHECK(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(r_physicalDevice, m_vk_surface, &surfaceCaps));

    width = surfaceCaps.currentExtent.width;
    height = surfaceCaps.currentExtent.height;
}

bool VulkanSurface::PollWindowEvents() const{
    if (!glfwWindowShouldClose(m_window)){
		glfwPollEvents();

        return true;
    }

    return false;
}

VkSurfaceKHR& VulkanSurface::Vk_surface(){
    return m_vk_surface;
}

VulkanSurface::VulkanSurface(){
    // init glfw
    const int rc = glfwInit();
	assert(rc);
}

VulkanSurface::~VulkanSurface(){
    vkDestroySurfaceKHR(r_instance, m_vk_surface, 0);
    glfwDestroyWindow(m_window);
}

VkFormat VulkanSurface::GetSwapchainFormat() const{
	uint32_t formatCount = 0;
	VK_CHECK(vkGetPhysicalDeviceSurfaceFormatsKHR(r_physicalDevice, m_vk_surface, &formatCount, 0));
	assert(formatCount > 0);

	std::vector<VkSurfaceFormatKHR> formats(formatCount);
	VK_CHECK(vkGetPhysicalDeviceSurfaceFormatsKHR(r_physicalDevice, m_vk_surface, &formatCount, formats.data()));

	if (formatCount == 1 && formats[0].format == VK_FORMAT_UNDEFINED)
		return VK_FORMAT_R8G8B8A8_UNORM;

	for (uint32_t i = 0; i < formatCount; ++i)
		if (formats[i].format == VK_FORMAT_R8G8B8A8_UNORM || formats[i].format == VK_FORMAT_B8G8R8A8_UNORM)
			return formats[i].format;

	return formats[0].format;
}