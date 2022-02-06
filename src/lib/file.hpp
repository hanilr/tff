/* TERMINAL FILE FINDER (FILE) [HEADER] */
#ifndef _FILE_HPP
#define _FILE_HPP

bool is_file(std::string file_name);

bool is_dir(std::string dir_path);

void create_file(std::string file_name);

void delete_file(const char* file_name);

void create_dir(std::string dir_name, bool plurality);

void delete_dir(std::string dir_name, bool plurality);

void write_file(std::string file_name, std::string file_content, char perm_type);

std::string read_file(std::string file_name, int line);

int count_line(std::string file_name);

std::uintmax_t size_file(std::string file_name);

std::string path_current(void);

void path_change(std::string new_path);

void set_path_to_main(void);

#endif /* MADE BY @hanilr */