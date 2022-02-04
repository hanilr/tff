/* TERMINAL FILE FINDER (UTILITY) */

// STANDARD LIBRARY
#include <iostream>
#include <filesystem>

// DIY LIBRARY
#include "lib/util.hpp"

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

void file_list(void)
{
    for(const auto & get_file_name : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        std::string file_name = get_file_name.path();
        std::string cpath = std::filesystem::current_path();
        int file_name_length = file_name.length() - cpath.length();
        std::cout << file_name.substr(cpath.length(), file_name_length) << std::endl;
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
    else if(key == 'l') { file_list(); }
    else if(key == 'q') { exit(0); }
}

/* MADE BY @hanilr */