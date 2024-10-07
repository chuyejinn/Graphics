#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

const unsigned int WIN_W = 300; // window size in pixels, (Width, Height)
const unsigned int WIN_H = 300;

int main(void) {
    // start GLFW
    if (!glfwInit()) {
        printf("GLFW initialization failed\n");
        return -1;
    }

    // Create window
    GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "Hello GLEW", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW after making the context current
    if (glewInit() != GLEW_OK) {
        printf("GLEW initialization failed!\n");
        return -1;
    } else {
        // Print GLEW and OpenGL version information
        printf("GLEW initialized successfully!\n");
        printf("OpenGL version: %s\n", glGetString(GL_VERSION));
        printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen to a specific color (e.g., red)
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Set clear color to red
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}

