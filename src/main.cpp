#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    GLFWwindow *window;

    // GLFW initialization
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // GLFW window creation
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // GLAD initialization
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to load OpenGL." << std::endl;
        glfwTerminate();
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Your OpenGL rendering code goes here

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Cleanup
    glfwTerminate();
    return 0;
}
