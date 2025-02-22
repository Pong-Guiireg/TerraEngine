// ---------------------------------------------------
// |                 main.h                 |
// ---------------------------------------------------
//
// This header file contains the main function for the
// Engine.
//
// ---------------------------------------------------
#ifndef MAIN_H
  #define MAIN_H

  #include "includes.h"

  GLFWwindow* openWindow(void);
  void main_loop(GLFWwindow* window);
  void draw_interface(void);

#endif // MAIN_H
