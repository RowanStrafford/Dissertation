#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Shader.h"
#include "stb_image.h"

#include "Camera.h"
#include "Shader.h"
#include "Cube.h"

// GLM - MATHS/VECTORS/MATRICES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class System
{
public:
	System();
	~System();

	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	//void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	void ProcessInput(GLFWwindow* window);
	void SetCallbackFunctions();
	void Update();

private:
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	float lastX = SCR_WIDTH / 2.0f;
	float lastY = SCR_HEIGHT / 2.0f;

	bool firstMouse = true;

	float deltaTime = 0.0f;	
	float lastFrame = 0.0f;

	Camera* m_cam;
	Shader* m_shader;

	Cube* m_cube1;

	GLFWwindow* m_window;

	void MousePositionCallback(GLFWwindow* window, double positionX, double positionY);
	void KeyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mods);
	void FramebufferCallback(GLFWwindow* window, int width, int height);

	class GLFWCallbackWrapper
	{
	public:
		GLFWCallbackWrapper() = delete;
		GLFWCallbackWrapper(const GLFWCallbackWrapper&) = delete;
		GLFWCallbackWrapper(GLFWCallbackWrapper&&) = delete;
		~GLFWCallbackWrapper() = delete;

		static void MousePositionCallback(GLFWwindow* window, double positionX, double positionY);
		static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void FramebufferCallback(GLFWwindow* window, int width, int height);
		static void SetSystem(System *system);

	private:
		static System* s_system;
	};
};

