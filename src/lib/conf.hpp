/* TERMINAL FILE FINDER (CONFIGURATION) [HEADER] */
#ifndef _CONF_HPP
#define _CONF_HPP

struct color_variable
{
    std::string color_name, color_value;
    int color_count;
};

bool is_installed(void);

void change_term_size(int terminal_width, int terminal_height);

void add_color(std::string color_name, std::string hex_color, bool is_fore);

void change_color(std::string color_name, std::string hex_color, bool is_fore);

void remove_color(std::string color_name);

void save_in_data(std::string file_name, std::string file_content);

#endif /* MADE BY @hanilr */