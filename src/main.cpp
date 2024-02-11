#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

// GLFW: Callbacks
void
framebuffer_size_callback(GLFWwindow* window, int width, int height);

void
processInput(GLFWwindow* window);

int
main()
{
  // GLFW Init
  // ---------
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW!" << std::endl;
    return -1;
  }

  // Set OpenGL version and Profile (Immediate vs. Core)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // GLFW Window Init
  // ----------------
  const int WINDOW_WIDTH = 1024;
  const int WINDOW_HEIGHT = 768;

  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH, WINDOW_HEIGHT, "learning openGL", nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW Window!" << std::endl;
    glfwTerminate();
    return -1;
  }
  // Tell GLFW to make the window context the main context on the current
  // thread.
  glfwMakeContextCurrent(window);

  // Registering cb function for window resize: cb function called every time a
  // window is resized.
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // GLAD Init - Load all OpenGL function pointers
  // ---------------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD!" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Registration of callback functions is done after window creation and before
  // the render loop initiation.
  // ---------------------------------------------------------------------------

  // Render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // Input
    // -----
    processInput(window);

    // Rendering
    // ---------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers and poll IO events (key press/release, mouse events, etc.)
    // -----------------------------------------------------------------------
    glfwSwapBuffers(window); // swap between front and back buffers? to prevent
                             // render flickering issues
    glfwPollEvents();
  }

  // Clean up GLFW resources
  // -----------------------
  glfwTerminate();
  return 0;
}

// Process all input
// -----------------
void
processInput(GLFWwindow* window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    std::cout << "processInput(): closing window." << std::endl;
    glfwSetWindowShouldClose(window, true);
  }
}

// GLFW: Callbacks
// ---------------
void
framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  std::cout << "framebuffer_size_callback(): (width: " << width
            << ", height: " << height << ")" << std::endl;

  // GLint x, GLint y = set locn of the lower left corner of the window.
  // GLsizei width, GLsizei height = set rendering viewport dimensions in pixels
  // (can be smaller than Window dimensions).
  glViewport(0, 0, width, height);
}