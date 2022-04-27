/* TERMINAL FILE FINDER (UTILITY) */

// STANDARD LIBRARY
#include <iostream>
#include <filesystem>

// DIY LIBRARY
#include "lib/util.hpp"
#include "lib/config.hpp"
#include "lib/ui.hpp"

int hex_number(int number, bool left_side)
{
    if(left_side == false) { return number; }
    else if(left_side == true) { return number*16; }
    return 0;
} // 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN ORIGINAL NUMBER IF NOT THEN MULTIPLY WITH 16

int hex_letter(char letter, bool left_side)
{
    int result;
    if(letter == 'a') { result = 10; }
    else if(letter == 'b') { result = 11; }
    else if(letter == 'c') { result = 12; }
    else if(letter == 'd') { result = 13; }
    else if(letter == 'e') { result = 14; }
    else if(letter == 'f') { result = 15; }
    if(left_side == true) { result*=16; }
    return result;
} // 'left_side' MEAN IS IF AT LEFT SIDE THEN RETURN 2 DIGIT NUMBER WHO START WITH 10 IF NOT THEN MULTIPLY WITH 16

std::string rgb_to_esc(std::string red, std::string green, std::string blue, bool is_fore)
{
    std::string result;
    if(is_fore == true) { result = "\033[38;2;" + red + ";" + green + ";" + blue + "m"; }
    else { result = "\033[48;2;" + red + ";" + green + ";" + blue + "m"; }
    return result;
} // '\033' IS ASCII ESCAPE CODE

std::string hex_to_rgb(std::string chex, bool is_fore)
{
    int red_a, red_b, green_a, green_b, blue_a, blue_b;

    if(std::isdigit(chex[1]) == 0) { red_a = hex_letter(chex[1], true); }
    else { red_a = hex_number(chex[1], true); }
    if(std::isdigit(chex[2]) == 0) { red_b = hex_letter(chex[2], false); }
    else { red_b = hex_number(chex[2], false); }
    if(std::isdigit(chex[3]) == 0) { green_a = hex_letter(chex[3], true); }
    else { green_a = hex_number(chex[3], true); }
    if(std::isdigit(chex[4]) == 0) { green_b = hex_letter(chex[4], false); }
    else { green_b = hex_number(chex[4], false); }
    if(std::isdigit(chex[5]) == 0) { blue_a = hex_letter(chex[5], true); }
    else { blue_a = hex_number(chex[5], true); }
    if(std::isdigit(chex[6]) == 0) { blue_b = hex_letter(chex[6], false); }
    else { blue_b = hex_number(chex[6], false); }
    
    int red = red_a + red_b, green = green_a + green_b, blue = blue_a + blue_b;
    return rgb_to_esc(std::to_string(red), std::to_string(green), std::to_string(blue), is_fore);
}

int divide_half(int number)
{
    if(number%2 == 0) { return number/2; }
    else { return (number-1)/2; }
} // IF CAN'T DIVIDE THEN MINUS 1 AND THEN DIVIDE 2

char get_char_instantly(void)
{
    system("stty raw"); // TERMINAL 'raw' MODE
    char key = getchar();
    system("stty cooked"); // TERMINAL 'cooked' MODE
    return key;
}

std::string get_username(void)
{
    std::string username = getenv("USER");
    return username;
}

std::string file_find(std::string file_name)
{
    std::string file_path;
    std::filesystem::recursive_directory_iterator end;
    std::filesystem::recursive_directory_iterator rdi("/", std::filesystem::directory_options::skip_permission_denied);

    while(rdi != end)
    {
        const std::string path = rdi->path().string();
        if(path.find(file_name) != std::string::npos) { file_path += path + "\n  "; }

        try { ++rdi; }
        catch(std::filesystem::filesystem_error e)
        {
            rdi.std::filesystem::recursive_directory_iterator::disable_recursion_pending();
            ++rdi;
        }
    }
    return file_path;
}   

int file_list(int pos_x, int pos_y, std::string fgcolor, std::string bgcolor, int list_start, int list_end)
{
    int x = 0, y = 0;
    for(const auto & get_file_name : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        std::string file_name = get_file_name.path();
        std::string cpath = std::filesystem::current_path();
        int file_name_length = file_name.length() - cpath.length();

        if(x >= list_start && x <= list_end)
        {
            goto_color_print(pos_x, pos_y+y, fgcolor, bgcolor, "", file_name.substr(cpath.length(), file_name_length));
            y+=1;
        }
        x+=1;
    }
    return x;
}

/* MADE BY @hanilr */