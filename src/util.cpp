/* TERMINAL FILE FINDER (UTILITY) */

// STANDARD LIBRARY
#include <iostream>
#include <filesystem>

// DIY LIBRARY
#include "lib/util.hpp"
#include "lib/config.hpp"
#include "lib/ui.hpp"

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