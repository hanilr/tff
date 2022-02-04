/* TERMINAL FILE FINDER (MAIN) */

// STANDARD LIBRARY
#include <iostream>
#include <cstring>

// DIY LIBRARY
#include "lib/config.hpp"
#include "lib/file.hpp"
#include "lib/util.hpp"
#include "lib/ui.hpp"

int main(int argc, char* argv[])
{
    if(strcmp(argv[1], "-install") == 0)
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, warn_install);

        gotoxy(divide_half(term_x)-2, divide_half(term_y)+2);
        std::cout << colorfg_white << colorbg_gray << text_bold << ">   <" << esc_reset;
        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        char install_decision = get_char_instantly();

        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        if(install_decision == 'y')
        {
            std::cout << colorfg_white << colorbg_gray << text_bold << "y" << esc_reset;
            // INSTALL SECTION
        }
        else { std::cout << colorfg_white << colorbg_gray << text_bold << "n" << esc_reset; }

        gotoxy(term_x, term_y);
    }
    return 0;
}

/* MADE BY @hanilr */