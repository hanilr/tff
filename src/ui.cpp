/* TERMINAL FILE FINDER (USER INTERFACE) */

// STANDARD LIBRARY
#include <iostream>

// DIY LIBRARY
#include "lib/ui.hpp"
#include "lib/config.hpp"

void clrscr(void) { std::cout << clear_screen; }

void cursor_visibility(bool state)
{
    if(state == true) { std::cout << cursor_visible; }
    else { std::cout << cursor_invisible; }
}

void gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

/* MADE BY @hanilr */