#include"lve_window.h"

namespace lve
{
	LveWindow::LveWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
	{
		initWindow();
	}
	LveWindow::~LveWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void LveWindow::initWindow()
	{
		glfwInit();
		glfwInitHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwInitHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}