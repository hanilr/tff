/* TERMINAL FILE FINDER (USER INTERFACE) */

// STANDARD LIBRARY
#include <iostream>

// DIY LIBRARY
#include "lib/ui.hpp"
#include "lib/config.hpp"
#include "lib/util.hpp"

void clrscr(void) { std::cout << clear_screen; }

void cursor_visibility(bool state)
{
    if(state == true) { std::cout << cursor_visible; }
    else { std::cout << cursor_invisible; }
}

void gotoxy(int pos_x, int pos_y) { printf("\033[%d;%dH", pos_y, pos_x); }

void goto_color_print(int pos_x, int pos_y, std::string arg1, std::string arg2, std::string arg3, std::string print_str)
{
    gotoxy(pos_x, pos_y);
    std::cout << arg1 << arg2 << arg3 << print_str << esc_reset;
} // 'arg1' = foregroung color, 'arg2' = background color, 'arg3' = text style code

void bg_color(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor)
{
    for(int i = 0; y_len > i; i+=1)
    {
        gotoxy(pos_x+1, pos_y+i+1);
        for(int i = 0; x_len > i; i+=1) { std::cout << bgcolor << " " << esc_reset; }
    }
}

void draw_frame(int x_len, int y_len, int pos_x, int pos_y, std::string frame_color)
{
    gotoxy(pos_x+1, pos_y+1);
    for(int i = 0; x_len > i; i+=1) { std::cout << frame_color << " " << esc_reset; }
    for(int i = 1; y_len > i+1; i+=1)
    {
        gotoxy(pos_x+1, pos_y+i+1);
        std::cout << frame_color << " " << esc_reset;
        gotoxy(pos_x+x_len, pos_y+i+1);
        std::cout << frame_color << " " << esc_reset;
    }
    gotoxy(pos_x+1, pos_y+y_len);
    for(int i = 0; x_len > i; i+=1) { std::cout << frame_color << " " << esc_reset; }
}

void user_warn(int x_len, int y_len, int pos_x, int pos_y, std::string fgcolor, std::string bgcolor, std::string frame_color, std::string warn_str)
{
    int pos_xlen = divide_half(x_len);
    int pos_ylen = divide_half(y_len);

    bg_color(pos_xlen, pos_ylen, divide_half(pos_xlen)+pos_x, divide_half(pos_ylen)+pos_y, bgcolor);
    draw_frame(pos_xlen, pos_ylen, divide_half(pos_xlen)+pos_x, divide_half(pos_ylen)+pos_y, frame_color);
    gotoxy(pos_xlen-divide_half(warn_str.length())+1, pos_ylen);
    std::cout << fgcolor << bgcolor << text_bold << warn_str << esc_reset;
}

void user_screen(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor, std::string frame_color)
{
    clrscr();
    bg_color(x_len, y_len, pos_x, pos_y,bgcolor);
    draw_frame(x_len, y_len, pos_x, pos_y, frame_color);
    gotoxy(x_len+pos_x+1, y_len+pos_y+1);
}

/* MADE BY @hanilr */