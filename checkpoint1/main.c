#include <stdio.h> // printf, fprintf, stderr
#include <GLFW/glfw3.h>


GLFWwindow* window;

void error_callback(int error, const char* description);

int main()
{
    if (!glfwInit()) {
        printf("Error initializeing GLFW\n");
        return -1;
    }

    glfwSetErrorCallback(error_callback);

    window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -2;
    }
    glfwMakeContextCurrent(window); 
    glfwSwapInterval(0); // disable v-sync for now

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    
    return 0;
}

// This function is called internally by GLFW whenever an error occur.
void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}