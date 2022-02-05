/* TERMINAL FILE FINDER (UTILITY) */

// STANDARD LIBRARY
#include <iostream>
#include <filesystem>

// DIY LIBRARY
#include "lib/util.hpp"
#include "lib/config.hpp"
#include "lib/ui.hpp"

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

std::string rgb_to_esc(std::string rgb, bool is_fore)
{
    std::string red, green, blue, result;
    red = rgb[0] + rgb[1];
    green = rgb[2] + rgb[3];
    blue = rgb[4] + rgb[5];

    if(is_fore == true) { result = "\033[38;2;" + red + ";" + green + ";" + blue + "m"; }
    else { result = "\033[48;2;" + red + ";" + green + ";" + blue + "m"; }
    return result;
}

std::string hex_to_rgb(std::string chex, bool is_fore)
{
    int red_a, red_b, green_a, green_b, blue_a, blue_b;

    if(std::isdigit(chex[1]) == 0) { red_a = hex_letter(chex[1], true); }
    else { red_a = chex[1]; }
    if(std::isdigit(chex[2]) == 0) { red_b = hex_letter(chex[2], false); }
    else { red_b = chex[2]; }
    if(std::isdigit(chex[3]) == 0) { green_a = hex_letter(chex[3], true); }
    else { green_a = chex[3]; }
    if(std::isdigit(chex[4]) == 0) { green_b = hex_letter(chex[4], false); }
    else { green_b = chex[4]; }
    if(std::isdigit(chex[5]) == 0) { blue_a = hex_letter(chex[5], true); }
    else { blue_a = chex[5]; }
    if(std::isdigit(chex[6]) == 0) { blue_b = hex_letter(chex[6], false); }
    else { blue_b = chex[6]; }
    
    int red = red_a + red_b, green = green_a + green_b, blue = blue_a + blue_b;
    return rgb_to_esc(std::to_string(red) + std::to_string(green) + std::to_string(blue), is_fore);
}

int divide_half(int number)
{
    if(number%2 == 0) { return number/2; }
    else { return (number-1)/2; }
}

char get_char_instantly(void)
{
    char key;
    #ifdef _WIN32
        #include <conio.h>
        key = getch();
    #else 
        system("stty raw");
        key = getchar();
        system("stty cooked");
    #endif
    return key;
}

std::string get_username(void)
{
    #ifdef _WIN32
        #include <windows.h>
        #include <Lmcons.h>

        char username[UNLEN+1];
        DWORD username_len = UNLEN+1;
        GetUserName(username, &username_len);
        return username;
    #else
        std::string username = getenv("USER");
        return username;
    #endif
}

std::string file_find(std::string file_name)
{
    #ifdef _WIN32
        std::string os_path = "C:\\";
    #else
        std::string os_path = "/";
    #endif

    std::string file_path;
    std::filesystem::recursive_directory_iterator end;
    std::filesystem::recursive_directory_iterator rdi(os_path, std::filesystem::directory_options::skip_permission_denied);

    while(rdi != end)
    {
        const std::string path = rdi->path().string();
        if(path.find(file_name) != std::string::npos) { file_path += path + "\n "; }

        try { ++rdi; }
        catch(std::filesystem::filesystem_error e)
        {
            rdi.std::filesystem::recursive_directory_iterator::disable_recursion_pending();
            ++rdi;
        }
    }
    return file_path;
}   

void file_list(int pos_x, int pos_y, std::string fgcolor, std::string bgcolor)
{
    int i = 0;
    for(const auto & get_file_name : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        std::string file_name = get_file_name.path();
        std::string cpath = std::filesystem::current_path();
        int file_name_length = file_name.length() - cpath.length();
        gotoxy(pos_x+1, pos_y+i+1);
        std::cout << fgcolor << bgcolor << file_name.substr(cpath.length(), file_name_length) << esc_reset;
        i+=1;
    }
}

void key_map(char key)
{
    if(key == '/')
    {
        std::string file_name;
        std::cin >> file_name;
        file_find(file_name);
    }
    else if(key == 'l')
    {
        clrscr();
        file_list(0, 0, colorfg_white, colorbg_gray);
    }
    else if(key == 'q') { exit(0); }
}

/* MADE BY @hanilr */