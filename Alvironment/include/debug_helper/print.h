#include <iostream>

/**
 * @brief C++ macros for writting texts in the terminal with colors and backgrounds in order to give a much better looking and make it simpler to debug
 * @file print.h
 * @version 1.0
 * @date 2026-06-20
 * @author Álvaro Fernández Barrero
 */

#define RESET_COLOR "\x1b[0m"

// ------------------------------------------------------
// TEXT COLORS
// ------------------------------------------------------

#define BLACK "\x1B[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1B[37m"
#define ORANGE "\x1B[38;2;255;128;0m"
#define ROSE "\x1B[38;2;255;151;203m"
#define LIGHT_BLUE "\x1B[38;2;53;149;240m"
#define LIGHT_GREEN "\x1B[38;2;17;245;120m"
#define GRAY "\x1B[38;2;176;174;174m"

// ------------------------------------------------------
// BACKGROUND COLORS
// ------------------------------------------------------

#define BACKGROUND_BLACK "\x1B[40m"
#define BACKGROUND_RED "\x1B[41m"
#define BACKGROUND_GREEN "\x1B[42m"
#define BACKGROUND_YELLOW "\x1B[43m"
#define BACKGROUND_BLUE "\x1B[44m"
#define BACKGROUND_MAGENTA "\x1B[45m"
#define BACKGROUND_CYAN "\x1B[46m"
#define BACKGROUND_WHITE "\x1B[47m"
#define BACKGROUND_ORANGE "\x1B[48;2;255;128;0m"
#define BACKGROUND_LIGHT_BLUE "\x1B[48;2;53;149;240m"
#define BACKGROUND_LIGHT_GREEN "\x1B[48;2;17;245;120m"
#define BACKGROUND_GRAY "\x1B[48;2;176;174;174m"
#define BACKGROUND_ROSE "\x1B[48;2;255;151;203m"

// ------------------------------------------------------
// PRINT FUNCTIONS
// ------------------------------------------------------

#define PRINT(x) std::cout << x << std::endl

#define DEBUG_PRINT(x) PRINT(CYAN << "[DEBUG]: " << x << RESET_COLOR)
#define WARNING_PRINT(x) PRINT(YELLOW << "[WARN]: " << x << RESET_COLOR)
#define ERROR_PRINT(x) PRINT(RED << "[ERROR]: " << x << RESET_COLOR)
#define SUCCESS_PRINT(x) PRINT(GREEN << "[SUCCESS]: " << x << RESET_COLOR)