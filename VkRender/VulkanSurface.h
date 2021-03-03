#include "render_utils.h"
#include <volk.h>

// forward declaration
class GLFWwindow;

// class to manage window and related surface.
class VulkanSurface{
public:
    void Initialize(VkInstance instance, VkPhysicalDevice physicalDevice);
    uint32_t GetRequiredExtension(const char ** extensions) const;
    bool CheckPresentationSupport(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) const;
    void GetWindowsExtent(uint32_t &width, uint32_t &height) const;
    bool PollWindowEvents() const;
    VkFormat GetSwapchainFormat() const;

    VkSurfaceKHR& Vk_surface();

    ~VulkanSurface();
private:
    VkSurfaceKHR m_vk_surface;
    GLFWwindow* m_window;

    VkInstance r_instance;
    VkPhysicalDevice r_physicalDevice;
};