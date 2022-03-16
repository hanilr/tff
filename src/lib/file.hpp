/* TERMINAL FILE FINDER (FILE) [HEADER] */
#ifndef _FILE_HPP
#define _FILE_HPP

bool is_file(std::string file_name); // IS FILE EXIST THEN RETURN TRUE

bool is_dir(std::string dir_path); // IS DIRECTORY EXIST THEN RETURN TRUE

void create_file(std::string file_name); // CREATE FILE IN CURRENT DIRECTORY

void delete_file(const char* file_name); // DELETE FILE IN CURRENT DIRECTORY

void create_dir(std::string dir_name, bool plurality); // CREATE DIRECTORY WITH PLURALITY

void delete_dir(std::string dir_name, bool plurality); // DELETE DIRECTORY WITH PLURALITY

void write_file(std::string file_name, std::string file_content, char perm_type); // WRITE IN A FILE WITH PERMISSION TYPE

std::string read_file(std::string file_name, int line); // READ IN A FILE WITH LINE

int count_line(std::string file_name); // COUNT LINE IN A FILE

std::string path_current(void); // GET CURRENT PATH

void path_change(std::string new_path); // CHANGE CURRENT PATH

void set_path_to_main(void); // SET PATH TO INSTALLED DIRECTORY

#endif /* MADE BY @hanilr */