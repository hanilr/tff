/* TERMINAL FILE FINDER (CONFIGURATION) [HEADER] */
#ifndef _CONF_HPP
#define _CONF_HPP

bool is_installed(void);

void change_term_size(int terminal_width, int terminal_height);

void add_color(std::string color_name, std::string hex_color);

void remove_color(std::string color_name);

void save_in_data(std::string file_name);

#endif /* MADE BY @hanilr */