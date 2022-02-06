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
    #ifdef _WIN32
        std::string dir_root = "C:\\", dir_main = "Program Files\\", dir_name = "tff\\";
    #else
        std::string dir_root = "/", dir_main = "home/" + get_username() + "/", dir_name = ".tff/";
    #endif
    for(int x = 0, y = 10; y > x; x+=1)
    {
        path_change("../");
        if(path_current().compare(dir_root) == 0)
        {
            path_change(dir_main);
            break;
        }
        if(x == 9)
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
        }
    }
    return is_dir(dir_name);
}

void change_term_size(int terminal_width, int terminal_height)
{
    #ifdef _WIN32
        std::string conf_path = "conf\\";
    #else
        std::string conf_path = "conf/";
    #endif
    set_path_to_main();
    write_file(conf_path + "terminal.txt", terminal_width + "\n" + terminal_height, 'w');
}

void add_color(std::string color_name, std::string hex_color, bool is_fore)
{
    #ifdef _WIN32
        std::string conf_path = "conf\\";
    #else
        std::string conf_path = "conf/";
    #endif
    set_path_to_main();
    if(is_file(conf_path + color_name + ".txt") == false)
    {
        std::string rgb = hex_to_rgb(hex_color, is_fore);
        create_file(conf_path + color_name + ".txt");
        write_file(conf_path + color_name + ".txt", rgb, 'w');
        save_in_data("color.txt", color_name);
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Color successfully added!");
    }
    else
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Color name already exist!");
    }
}

void change_color(std::string color_name, std::string hex_color, bool is_fore)
{
    #ifdef _WIN32
        std::string conf_path = "conf\\";
    #else
        std::string conf_path = "conf/";
    #endif
    if(is_file(conf_path + color_name + ".txt") == true)
    {
        std::string rgb = hex_to_rgb(hex_color, is_fore);
        write_file(conf_path + color_name + ".txt", rgb, 'w');
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Color successfully changed!");
    }
    else
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Color name not found!");
    }
}

void remove_color(std::string color_name)
{
    #ifdef _WIN32
        std::string conf_path = "conf\\";
    #else
        std::string conf_path = "conf/";
    #endif
    std::string color_path = conf_path + color_name + ".txt";
    set_path_to_main();
    if(is_file(color_path) == true)
    {
        delete_file(color_path.c_str());
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Color successfully removed!");
    }
    else
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Color name not found!");
    }
}

void save_in_data(std::string file_name, std::string file_content)
{
    #ifdef _WIN32
        std::string data_path = "data\\";
    #else
        std::string data_path = "data/";
    #endif
    set_path_to_main();
    if(is_file(data_path + file_name + ".txt") == false)
    {
        create_file(file_name + ".txt");
        write_file(file_name, file_content, 'w');
    }
    else
    {
        create_file(file_name + ".txt");
        write_file(file_name, "\n" + file_content, 'a');
    }
    clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Data successfully saved!");
}

/* MADE BY @hanilr */