/* TERMINAL FILE FINDER (CONFIGURATION) */

// STANDARD LIBRARY
#include <iostream>

// DIY LIBRARY
#include "lib/conf.hpp"
#include "lib/config.hpp"
#include "lib/file.hpp"
#include "lib/util.hpp"
#include "lib/ui.hpp"

bool is_installed(void)
{
    for(int x = 0, y = 20; y > x; x+=1)
    {
        path_change("../"); // GO TO PARENT DIRECTORY
        if(path_current().compare("/") == 0) // IF CURRENT DIRECTORY IS '/'
        {
            path_change("home/" + get_username() + "/"); // SET PATH TO HOME + USERNAME
            break;
        }
        if(x == 19)
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
        }
    }
    return is_dir(".tff/"); // CHECK IF '.tff/' DIRECTORY EXIST
}

/* MADE BY @hanilr */