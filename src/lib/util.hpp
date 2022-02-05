/* TERMINAL FILE FINDER (UTILITY) [HEADER] */
#ifndef _UTIL_HPP
#define _UTIL_HPP

int hex_letter(char letter, bool left_side);

std::string rgb_to_esc(std::string rgb, bool is_fore);

std::string hex_to_rgb(std::string chex, bool is_fore);

int divide_half(int number);

char get_char_instantly(void);

std::string get_username(void);

std::string file_find(std::string file_name);

void file_list(int pos_x, int pos_y, std::string fgcolor, std::string bgcolor);

void key_map(char key);

#endif /* MADE BY @hanilr */