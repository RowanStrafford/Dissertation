#include "System.h"



System::System()
{
	m_cam = new Camera(glm::vec3(0, 0, 3));
	m_shader = new Shader("vertShad.vert", "fragShad.frag");
	
	//m_cube1 = new Cube(glm::vec3(0, 0, 0));
	//m_cube1->SetTexture("Me.jpg");

	// Initialisation of GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Legend", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();		
	}

	glfwMakeContextCurrent(m_window);	
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	
}

System::~System()
{
	delete m_cam;
	m_cam = nullptr;
}

/*void System::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void System::mouse_callback(GLFWwindow * window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	cam->ProcessMouseMovement(xoffset, yoffset);
}*/

void System::ProcessInput(GLFWwindow * window)
{

}

void System::SetCallbackFunctions()
{
	GLFWCallbackWrapper::SetSystem(this);
	glfwSetCursorPosCallback(m_window, GLFWCallbackWrapper::MousePositionCallback);
	glfwSetKeyCallback(m_window, GLFWCallbackWrapper::KeyboardCallback);
}

void System::Update()
{
	while (!glfwWindowShouldClose(m_window))
	{	
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_shader->Use();

		glm::mat4 projection = glm::perspective(glm::radians(m_cam->m_zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		m_shader->SetMatrix("projection", projection);

		glm::mat4 view = m_cam->GetViewMatrix();
		m_shader->SetMatrix("view", view);

		m_cube1->Draw(m_shader);

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

void System::MousePositionCallback(GLFWwindow * window, double positionX, double positionY)
{
	double newX = positionX + 1;
	double newY = positionY + 1;
}

void System::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	int newKey = key;
}

void System::FramebufferCallback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void System::GLFWCallbackWrapper::MousePositionCallback(GLFWwindow * window, double positionX, double positionY)
{
	s_system->MousePositionCallback(window, positionX, positionY);
}

void System::GLFWCallbackWrapper::KeyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	s_system->KeyboardCallback(window, key, scancode, action, mods);
}

void System::GLFWCallbackWrapper::FramebufferCallback(GLFWwindow * window, int width, int height)
{
	s_system->FramebufferCallback(window, width, height);
}

void System::GLFWCallbackWrapper::SetSystem(System * system)
{
	GLFWCallbackWrapper::s_system = system;
}

System* System::GLFWCallbackWrapper::s_system = nullptr;
