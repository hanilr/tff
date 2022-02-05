/* TERMINAL FILE FINDER (CONFIGURATION) */

// STANDARD LIBRARY
#include <iostream>

// DIY LIBRARY
#include "lib/conf.hpp"
#include "lib/file.hpp"

bool is_installed(void)
{
    set_path_to_main();
    #ifdef _WIN32
        std::string app_path = path_current() + "\\tff.exe";
    #else
        std::string app_path = path_current() + "/tff";
    #endif
    return is_file(app_path);
}

void change_term_size(int terminal_width, int terminal_height);

void add_color(std::string color_name, std::string hex_color);

void remove_color(std::string color_name);

void save_in_data(std::string file_name);

/* MADE BY @hanilr */