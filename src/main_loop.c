// ---------------------------------------------------
// |                 main_loop.c                    |
// ---------------------------------------------------
//
// This file contains the main loop for the engine.
//
// ---------------------------------------------------
#include "../include/main.h"

void main_loop(GLFWwindow* window)
{
  while (!glfwWindowShouldClose(window)) {
    draw_interface();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}
