/* TERMINAL FILE FINDER (FILE) */

// STANDARD LIBRARY
#include <iostream>
#include <fstream>
#include <filesystem>

// DIY LIBRARY
#include "lib/file.hpp"

bool is_file(std::string file_name)
{
    if(std::filesystem::exists(file_name) == true) { return true; }
    else { return false; }
}

void create_file(std::string file_name)
{
    if(is_file(file_name) == false)
    {
        std::ofstream cf(file_name);
        cf.close();
    }
    else { fprintf(stderr, "\nFILE ERROR: File already exist!\n"); }
}

void delete_file(const char* file_name)
{
    if(is_file(file_name) == true) { remove(file_name); }
    else { fprintf(stderr, "\nFILER ERROR: File doesn't exist! (DELETE)\n"); }
}

void create_dir(std::string dir_name, bool plurality)
{
    if(plurality == true) { std::filesystem::create_directories(dir_name); }
    else { std::filesystem::create_directory(dir_name); }
}

void delete_dir(std::string dir_name) { std::filesystem::remove(dir_name); }

void write_file(std::string file_name, std::string file_content, char perm_type)
{
    if(is_file(file_name) == true)
    {
        std::fstream wf(file_name);
        if(perm_type == 'w') { wf << file_content; }
        else if(perm_type == 'a')
        {
            std::string file_content_temp;
            wf >> file_content_temp;
            file_content_temp = file_content_temp + file_content;
            wf << file_content_temp;
        }
        else { fprintf(stderr, "\nFILE ERROR: Permission type fault! (WRITE)\n"); }
        wf.close();
    }
    else { fprintf(stderr, "\nFILE ERROR: File doesn't exist! (WRITE)\n"); }
}

std::string read_file(std::string file_name, int line)
{
    if(is_file(file_name) == true)
    {
        std::string file_content;

        std::ifstream rf(file_name);
        if(line == 0)
        {
            std::string file_content_line;
            while(getline(rf, file_content_line)) { file_content = file_content + file_content_line + '\n'; }
        }
        else
        {
            int i = 0;

            while(line > i)
            {
                getline(rf, file_content);
                i+=1;
            }
        }
        rf.close();
        return file_content;
    }
    else
    {
        fprintf(stderr, "\nFILE ERROR: File doesn't exist! (READ)\n");
        return "!ERROR!";
    }
}

std::uintmax_t size_file(std::string file_name)
{
    if(is_file(file_name) == true) { return std::filesystem::file_size(file_name); }
    else
    {
        fprintf(stderr, "\nFILE ERROR: File doesn't exist! (SIZE)\n");
        return 0;
    }
}

/* MADE BY @hanilr */