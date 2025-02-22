// ---------------------------------------------------
// |                 open_window.c                    |
// ---------------------------------------------------
//
// This header file declares the function to open
// an OpenGL window using GLFW.
//
// ---------------------------------------------------
#include "../include/includes.h"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void openWindow(void)
{
    // Initialisation de GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Échec de l'initialisation de GLFW\n");
        return;
    }

    // Configuration des paramètres de la fenêtre
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4.6);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4.6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Création de la fenêtre
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Échec de la création de la fenêtre GLFW\n");
        glfwTerminate();
        return;
    }

    // Définir le contexte courant et la taille du framebuffer
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}
