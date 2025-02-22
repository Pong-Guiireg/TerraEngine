// ---------------------------------------------------
// |                 main.c                 |
// ---------------------------------------------------
//
// This file contains the main function for the
// Engine.
// ---------------------------------------------------
#include "../include/main.h"

int main(void)
{
    GLFWwindow* window = openWindow();
    if (!window) {
        return -1;
    }
    main_loop(window);

}
