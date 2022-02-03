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

void nline(int times) { for(int i = 0; times > i; i+=1) { std::cout << std::endl; } }

void draw_frame(int x_len, int y_len, std::string frame_color)
{
    clrscr();
    for(int i = 0; x_len > i; i+=1) { std::cout << frame_color << " " << esc_reset; }
    nline(1);
    for(int i = 1; y_len > i; i+=1)
    {
        gotoxy(0, i);
        std::cout << frame_color << " " << esc_reset;
        gotoxy(x_len, i);
        std::cout << frame_color << " " << esc_reset;
    }
    nline(1);
    for(int i = 0; x_len > i; i+=1) { std::cout << frame_color << " " << esc_reset; }
}

/* MADE BY @hanilr */