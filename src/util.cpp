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
    if(left_side == false)
    {
        if(number == '1') { return 1; }
        else if(number == '2') { return 2; }
        else if(number == '3') { return 3; }
        else if(number == '4') { return 4; }
        else if(number == '5') { return 5; }
        else if(number == '6') { return 6; }
        else if(number == '7') { return 7; }
        else if(number == '8') { return 8; }
        else if(number == '9') { return 9; }
    }
    else
    {
        if(number == '1') { return 16; }
        else if(number == '2') { return 32; }
        else if(number == '3') { return 48; }
        else if(number == '4') { return 64; }
        else if(number == '5') { return 80; }
        else if(number == '6') { return 96; }
        else if(number == '7') { return 112; }
        else if(number == '8') { return 128; }
        else if(number == '9') { return 144; }
    }
    return 0;
}

int hex_letter(char letter, bool left_side)
{
    if(left_side == false)
    {
        if(letter == 'a') { return 10; }
        else if(letter == 'b') { return 11; }
        else if(letter == 'c') { return 12; }
        else if(letter == 'd') { return 13; }
        else if(letter == 'e') { return 14; }
        else if(letter == 'f') { return 15; }
    }
    else
    {
        if(letter == 'a') { return 160; }
        else if(letter == 'b') { return 176; }
        else if(letter == 'c') { return 192; }
        else if(letter == 'd') { return 208; }
        else if(letter == 'e') { return 224; }
        else if(letter == 'f') { return 240; }
    }
    return 0;
}

std::string rgb_to_esc(std::string red, std::string green, std::string blue, bool is_fore)
{
    std::string result;
    if(is_fore == true) { result = "\033[38;2;" + red + ";" + green + ";" + blue + "m"; }
    else { result = "\033[48;2;" + red + ";" + green + ";" + blue + "m"; }
    return result;
}

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
}

char get_char_instantly(void)
{
    system("stty raw");
    char key = getchar();
    system("stty cooked");
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

void file_list(int pos_x, int pos_y, int theight, std::string fgcolor, std::string bgcolor)
{
    int i = 0;
    for(const auto & get_file_name : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        std::string file_name = get_file_name.path();
        std::string cpath = std::filesystem::current_path();
        int file_name_length = file_name.length() - cpath.length();
        goto_color_print(pos_x+3, pos_y+i+5, fgcolor, bgcolor, "", file_name.substr(cpath.length(), file_name_length));
        i+=1;
        if(i == theight-7)
        {
            goto_color_print(pos_x+3, pos_y+i+3, fgcolor, bgcolor, "", "/..");
            break;
        }
    }
}

/* MADE BY @hanilr */