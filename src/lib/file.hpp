/* TERMINAL FILE FINDER (FILE) [HEADER] */
#ifndef _FILE_HPP
#define _FILE_HPP

bool is_file(std::string file_name);

void create_file(std::string file_name);

void delete_file(const char* file_name);

void create_dir(std::string dir_name, bool plurality);

void delete_dir(std::string dir_name);

void write_file(std::string file_name, std::string file_content, char perm_type);

std::string read_file(std::string file_name, int line);

std::uintmax_t size_file(std::string file_name);

#endif /* MADE BY @hanilr */