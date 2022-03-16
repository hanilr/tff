/* TERMINAL FILE FINDER (UTILITY) [HEADER] */
#ifndef _UTIL_HPP
#define _UTIL_HPP

int hex_number(int number, bool left_side); // CONVERT HEX NUMBER TO INTEGER

int hex_letter(char letter, bool left_side); // CONVERT HEX LETTER TO INTEGER

std::string rgb_to_esc(std::string red, std::string green, std::string blue, bool is_fore); // CONVERT BUFFERS TO ASCII CODES

std::string hex_to_rgb(std::string chex, bool is_fore); // CONVERT HEX CODE TO RGB CODE

int divide_half(int number); // DIVIDE HALF A NUMBER

char get_char_instantly(void); // GET CHAR BUFFER WITHOUT <return> NEEDED

std::string get_username(void); // GET USERNAME OF CURRENT MACHINE

std::string file_find(std::string file_name); // FIND FILE WITH FILE NAME

int file_list(int pos_x, int pos_y, std::string fgcolor, std::string bgcolor, int list_start, int list_end); // LIST FILE AND DIRECTORIES IN CURRENT LOCATION

#endif /* MADE BY @hanilr */