/* TERMINAL FILE FINDER (MAIN) */

// STANDARD LIBRARY
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

// DIY LIBRARY
#include "lib/config.hpp"
#include "lib/file.hpp"
#include "lib/util.hpp"
#include "lib/conf.hpp"
#include "lib/ui.hpp"

int main(int argc, char* argv[])
{
    int term_width = term_x, term_height = term_y; // SET TERMINAL SIZES WITH DEFAULT VALUES
    cursor_visibility(false); // SET CURSOR TO INVISIBLE
    if(argc == 2 && strcmp(argv[1], "-install") == 0) // INSTALL SECTION
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "Do you accept to install? (y/n)"); // USER AGREEMENT

        goto_color_print(divide_half(term_x)-2, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">   <");
        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        char install_decision = get_char_instantly(); // IF DECISION IS 'y' THEN INSTALL IF NOT TERMINATE THE PROCESS

        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        if(install_decision == 'y') // IF DECISION IS YES
        {
            // INSTALL SECTION
            std::string term_size_x, term_size_y;
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal width?");
            goto_color_print(divide_half(term_x)-3, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">     <");

            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cout << colorfg_green << colorbg_gray << text_bold;
            std::cin >> term_size_x; // GET TERMINAL WIDTH
            std::cout << esc_reset;

            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal height?");
            goto_color_print(divide_half(term_x)-3, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">     <");
            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cout << colorfg_green << colorbg_gray << text_bold;
            std::cin >> term_size_y; // GET TERMINAL HEIGHT
            std::cout << esc_reset;

            std::string main_dir = path_current(), term_config = term_size_x + "\n" + term_size_y;
            std::string compile_com = "g++ " + main_dir + "/src/main.cpp " + main_dir + "/src/file.cpp " + main_dir + "/src/util.cpp " + main_dir + "/src/ui.cpp " + main_dir + "/src/conf.cpp " + "-o ~/.tff/tff";

            for(int x = 0, y = 20; y > x; x+=1)
            {
                path_change("../"); // GO TO PARENT DIRECTORY
                if(path_current().compare("/") == 0) // IF DIRECTORY IS '/'
                {
                    path_change("home/" + get_username() + "/"); // CHANGE PATH TO HOME + USERNAME
                    create_dir(".tff/conf/", true); // Create '.tff/' and 'conf/' DIRECTORIES
                    create_dir(".tff/data/history/", true); // CREATE 'data/' and 'history/' DIRECTORIES

                    create_file(".tff/conf/terminal.txt"); // CREATE TERMINAL SIZE FILE
                    create_file(".tff/data/search_history.txt"); // CREATE SEARCH HISTORY
                    create_file(".tff/conf/ui_color.txt"); // CREATE CUSTOM UI COLOR FILE

                    write_file(".tff/conf/terminal.txt", term_config, 'w'); // ENTER TERMINAL SIZE TO FILE
                    write_file(".tff/data/search_history.txt", "", 'w');
                    write_file(".tff/conf/ui_color.txt", ui_conf_color, 'w'); // ENTER UI COLORS TO FILE

                    system(compile_com.c_str()); // COMPILE FILE TO CURRENT DIRECTORY
                    break; // FINISH THE INSTALL SECTION
                }
                if(x == 19)
                {
                    clrscr();
                    user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                }
            }

            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Successfully installed!");
        }
        else
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "Installation cancelled!");
        }
    }
    else if(argc == 2 && strcmp(argv[1], "-uninstall") == 0)
    {
        if(is_installed() == true)
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "Do you accept to uninstall? (y/n)");

            goto_color_print(divide_half(term_x)-2, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">   <");
            gotoxy(divide_half(term_x), divide_half(term_y)+2);
            char uninstall_decision = get_char_instantly(); // IF DECISION IS 'y' THEN UNINSTALL IF NOT TERMINATE THE PROCESS

            if(uninstall_decision == 'y') // IF DECISION IS YES
            {
                delete_dir(".tff/", true); // DELETE '.tff/' DIRECTORY WITH SUBFOLDERS
                clrscr();
                user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Successfully uninstalled!");
            }
            else
            {
                clrscr();
                user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Uninstall cancalled!");
            }
        }
        else
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Not installed!");
        }
    }
    else if(argc == 2 && strcmp(argv[1], "-list") == 0)
    {
        int pos = 0; // CURSOR POSITION
        while(1)
        {
            user_screen(term_width-4, term_height-4, 2, 2, colorbg_gray, colorbg_white);
            goto_color_print(5, 5, colorfg_white, colorbg_gray, text_bold, "[CURRENT PATH] ");
            goto_color_print(20, 5, colorfg_white, colorbg_gray, "", path_current());

            goto_color_print(term_width-get_username().length()-16, 5, colorfg_white, colorbg_gray, text_bold, "[USERNAME] ");
            goto_color_print(term_width-get_username().length()-5, 5, colorfg_white, colorbg_gray, "", get_username());

            goto_color_print(term_width-get_username().length()-16, 7, colorfg_white, colorbg_gray, text_bold, "[WIDTH] ");
            goto_color_print(term_width-get_username().length()-8, 7, colorfg_white, colorbg_gray, "", std::to_string(term_width));

            goto_color_print(term_width-get_username().length()-16, 8, colorfg_white, colorbg_gray, text_bold, "[HEIGHT] ");
            goto_color_print(term_width-get_username().length()-7, 8, colorfg_white, colorbg_gray, "", std::to_string(term_height));

            int list_length = file_list(5, 7, colorfg_white, colorbg_gray, 0+pos, 12+pos); // PRINT FILE LIST WITH CERTAIN POSITION AND NUMBER

            goto_color_print(5, term_height-3, colorfg_white, colorbg_gray, text_bold, ">");
            std::cout << colorfg_white << colorbg_gray;
            char key = get_char_instantly(); // GET COMMAND AS KEYMAPS
            std::cout << esc_reset;

            if(key == 'k' && pos != 0) { pos-=1; } // CURSOR UP
            else if(key == 'j' && pos != list_length-13 && list_length > 13) { pos+=1; } // CURSOR DOWN
            else if(key == 'c') { path_change("../"); } // CHANGE PATH TO PARENT DIRECTORY
            else if(key == ':') // CHANGE PATH TO TYPED DIRECTORY
            {
                std::string enter_dir;
                std::cout << colorfg_white << colorbg_gray;
                std::cin >> enter_dir;
                std::cout << esc_reset;
                path_change(enter_dir);
            }
            else if(key == 'q') { break; } // QUIT
        }
    }
    else if(argc == 2 && strcmp(argv[1], "-keymap") == 0)
    {
        user_screen(term_x, term_y, 0, 0, colorbg_gray, colorbg_blue);
        
        goto_color_print(3, 3, colorfg_white, colorbg_gray, text_bold, "[ '/' ]");
        goto_color_print(11, 3, colorfg_white, colorbg_gray, "", keymap_search);
        goto_color_print(3, 4, colorfg_white, colorbg_gray, "", guide_search);

        goto_color_print(3, 6, colorfg_white, colorbg_gray, text_bold, "[ ':' ]");
        goto_color_print(11, 6, colorfg_white, colorbg_gray, "", keymap_enter_dir);
        goto_color_print(3, 7, colorfg_white, colorbg_gray, "", guide_enter_dir);

        goto_color_print(55, 20, colorfg_white, colorbg_gray, text_bold, direction_comment);
        goto_color_print(52, 21, colorfg_white, colorbg_gray, text_bold, "[ 'k' ]");
        goto_color_print(60, 21, colorfg_white, colorbg_gray, "", keymap_up);

        goto_color_print(52, 22, colorfg_white, colorbg_gray, text_bold, "[ 'j' ]");
        goto_color_print(60, 22, colorfg_white, colorbg_gray, "", keymap_down);

        goto_color_print(3, 21, colorfg_white, colorbg_gray, text_bold, "[ 'c' ]");
        goto_color_print(11, 21, colorfg_white, colorbg_gray, "", keymap_exit_dir);

        goto_color_print(3, 22, colorfg_white, colorbg_gray, text_bold, "[ 'q' ]");
        goto_color_print(11, 22, colorfg_white, colorbg_gray, "", keymap_quit);
    }
    else if(argc == 2 && strcmp(argv[1], "-help") == 0)
    {
        user_screen(term_x, term_y, 0, 0, colorbg_gray, colorbg_green);

        goto_color_print(3, 3, colorfg_white, colorbg_gray, text_bold, "[ -install ]");
        goto_color_print(3, 4, colorfg_white, colorbg_gray, "", help_install);
        goto_color_print(3, 5, colorfg_white, colorbg_gray, "", suggest_install);

        goto_color_print(3, 7, colorfg_white, colorbg_gray, text_bold, "[ -uninstall ]");
        goto_color_print(3, 8, colorfg_white, colorbg_gray, "", help_uninstall);
        goto_color_print(3, 9, colorfg_white, colorbg_gray, "", suggest_uninstall);

        goto_color_print(3, 11, colorfg_white, colorbg_gray, text_bold, "[ -list ]");
        goto_color_print(3, 12, colorfg_white, colorbg_gray, "", help_list);
        goto_color_print(3, 13, colorfg_white, colorbg_gray, "", suggest_list);

        goto_color_print(3, 18, colorfg_white, colorbg_gray, text_bold, "[ -keymap ]");
        goto_color_print(3, 19, colorfg_white, colorbg_gray, "", help_keymap);
        goto_color_print(3, 20, colorfg_white, colorbg_gray, "", suggest_keymap);

        goto_color_print(3, 22, colorfg_white, colorbg_gray, text_bold, "[ -help ]");
        goto_color_print(13, 22, colorfg_white, colorbg_gray, "", help_help);
    }
    else if(argc == 1) // USER INTERFACE
    {
        bool perm_type = false; // IF USER INSTALLED THEN 'perm_type' IS TRUE
        struct ui_color uc[5]; // CUSTOM COLOR STRUCTURE DEFINATION
        int reverse_count = 4, pos = 0;

        if(is_installed() == true) // IF INSTALLED THEN GET TERMINAL SIZES
        {
            path_change(".tff/conf/");
            term_width = std::stoi(read_file("terminal.txt", 1));
            term_height = std::stoi(read_file("terminal.txt", 2));
            perm_type = true;
        }
        if(perm_type == true) // IF INSTALLED THEN GET TERMINAL UI COLORS
        { // FGC: FOREGROUND COLOR // BGC: BACKGROUND COLOR // FC: FRAME COLOR
            uc[0].fgc = hex_to_rgb(read_file("ui_color.txt", 8), true), uc[0].bgc = hex_to_rgb(read_file("ui_color.txt", 11), false), uc[0].fc = hex_to_rgb(read_file("ui_color.txt", 14), false); // MAIN SCREEN
            uc[1].fgc = hex_to_rgb(read_file("ui_color.txt", 18), true), uc[1].bgc = hex_to_rgb(read_file("ui_color.txt", 21), false), uc[1].fc = hex_to_rgb(read_file("ui_color.txt", 24), false); // WARNING SCREEN
            uc[2].fgc = hex_to_rgb(read_file("ui_color.txt", 28), true), uc[2].bgc = hex_to_rgb(read_file("ui_color.txt", 31), false); // LIST SCREEN
            uc[3].fgc = hex_to_rgb(read_file("ui_color.txt", 35), true), uc[3].bgc = hex_to_rgb(read_file("ui_color.txt", 38), false), uc[3].fc = hex_to_rgb(read_file("ui_color.txt", 41), false); // SUCCESS SCREEN
            uc[4].fgc = hex_to_rgb(read_file("ui_color.txt", 45), true), uc[4].bgc = hex_to_rgb(read_file("ui_color.txt", 48), false), uc[4].fc = hex_to_rgb(read_file("ui_color.txt", 51), false); // ERROR SCREEN
        }
        else // IF NOT INSTALLED THEN SET UI COLOR TO DEFAULT VALUES
        { // FGC: FOREGROUND COLOR // BGC: BACKGROUND COLOR // FC: FRAME COLOR
            
            uc[0].fgc = colorfg_white, uc[0].bgc = colorbg_black, uc[0].fc = colorbg_gray; // MAIN SCREEN
            uc[1].fgc = colorfg_black, uc[1].bgc = colorbg_gray, uc[1].fc = colorbg_red; // WARNING SCREEN
            uc[2].fgc = colorfg_white, uc[2].bgc = colorbg_black; // LIST SCREEN
            uc[3].fgc = colorfg_green, uc[3].bgc = colorbg_gray, uc[3].fc = colorbg_green; // SUCCESS SCREEN
            uc[4].fgc = colorfg_red, uc[4].bgc = colorbg_gray, uc[4].fc = colorbg_red; // ERROR SCREEN
        }

        for(int i = 0; 20 > i; i+=1) { path_change("../"); } // SET PATH TO MAIN OS DIRECTORY
        while(1)
        {
            user_screen(term_width, term_height, 0, 0, uc[0].bgc, uc[0].fc);
            goto_color_print(3, 3, uc[0].fgc, uc[0].bgc, text_bold, "[CURRENT PATH] ");
            goto_color_print(18, 3, uc[0].fgc, uc[0].bgc, "", path_current());
            
            goto_color_print(term_width-get_username().length()-14, 3, uc[0].fgc, uc[0].bgc, text_bold, "[USERNAME] ");
            goto_color_print(term_width-get_username().length()-3, 3, uc[0].fgc, uc[0].bgc, "", get_username());

            goto_color_print(term_width-get_username().length()-14, 5, uc[0].fgc, uc[0].bgc, text_bold, "[WIDTH] ");
            goto_color_print(term_width-get_username().length()-6, 5, uc[0].fgc, uc[0].bgc, "", std::to_string(term_width));

            goto_color_print(term_width-get_username().length()-14, 6, uc[0].fgc, uc[0].bgc, text_bold, "[HEIGHT] ");
            goto_color_print(term_width-get_username().length()-5, 6, uc[0].fgc, uc[0].bgc, "", std::to_string(term_height));

            int list_length = file_list(3, 5, uc[0].fgc, uc[0].bgc, 0+pos, (term_height-8)+pos);
            goto_color_print(3, term_height-1, uc[0].fgc, uc[0].bgc, text_bold, ">");
            gotoxy(5, term_height-1);

            // KEY MAP SECTION
            std::cout << uc[0].fgc << uc[0].bgc;
            char key = get_char_instantly();
            std::cout << esc_reset;

            // KEY MAPS
            if(key == '/') // SEARCH KEYMAP
            {
                std::string file_name;
                std::cout << uc[0].fgc << uc[0].bgc;
                std::cin >> file_name;
                std::cout << esc_reset;

                std::string file_buffer = file_find(file_name);
                if(is_installed() == true) // IF APPLICATION INSTALLED THEN SAVE TO HISTORY
                {
                    path_change(".tff/data/");
                    write_file("search_history.txt", "\n" + file_name, 'a');
                    path_change("history/");
                    if(is_file(file_name) == true) { write_file(file_name, file_buffer, 'w'); }
                    else
                    {
                        create_file(file_name);
                        write_file(file_name, file_buffer, 'w');
                    }
                }
                else // CREATE A TEMPORARY FILE IN TEMP
                {
                    for(int i = 0; 20 > i; i+=1) { path_change("../"); }
                    path_change("tmp/");
                    create_file(file_name);
                    write_file(file_name, file_buffer, 'w');
                }
                
                int buffer_line = count_line(file_name), move_count, file_line_position = 0;
                if(buffer_line > term_y - 4) { move_count = buffer_line - (term_y - 5); }
                while(1)
                {
                    user_screen(term_width, term_height, 0, 0, uc[0].bgc, uc[0].fc);
                    goto_color_print(3, term_height-1, uc[0].fgc, uc[0].bgc, text_bold, ">");

                    for(int i = 0; buffer_line > i; i+=1)
                    {
                        goto_color_print(1, i+3, uc[0].fgc, uc[0].bgc, "", read_file(file_name, file_line_position+i));
                        if(i == term_y - 4) { break; }
                    }
                    draw_frame(term_width, term_height, 0, 0, uc[0].fc);

                    gotoxy(5, term_height-1);
                    std::cout << uc[0].fgc << uc[0].bgc;
                    char key_list = get_char_instantly();
                    std::cout << esc_reset;

                    if(key_list == 'k' && move_count != '\0' && file_line_position != 0) { file_line_position-=1; } // MOVE CURSOR TO UP
                    else if(key_list == 'j' && move_count != '\0' && file_line_position != move_count) { file_line_position+=1; } // MOVE CURSOR TO DOWN
                    else if(key_list == 'q') { break; }
                }
                if(is_installed() == false) // DELETE TEMPORARY FILE IF NOT INSTALLED
                {
                    for(int i = 0; reverse_count > i; i+=1) { path_change("../"); }
                    path_change("tmp/");
                    delete_file(file_name.c_str());
                }

                for(int i = 0; reverse_count+1 > i; i+=1) { path_change("../"); }
            }
            else if(key == 'k' && pos != 0) { pos-=1; } // CURSOR UP
            else if(key == 'j' && pos != list_length-(term_height-7)) { pos+=1; } // CURSOR DOWN
            else if(key == 'c') { path_change("../"); } // SET PATH TO PARENT DIRECTORY
            else if(key == ':') // CHANGE PATH TO TYPED DIRECTORY
            {
                std::string enter_dir;
                std::cout << uc[0].fgc << uc[0].bgc;
                std::cin >> enter_dir;
                std::cout << esc_reset;
                path_change(enter_dir);
            }
            else if(key == 'q') // CLOSE THE APPLICATION
            {
                gotoxy(term_width, term_height);
                return 0;
            }
            gotoxy(3, term_height-1);
            for(int i = 3; term_width > i; i+=1) { std::cout << uc[0].fgc << uc[0].bgc << " " << esc_reset; }
        }
    }
    else if(argc > 1) // MISSING ARGUMENT ERROR
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_white, colorbg_black, colorbg_red, "[ERROR] Missing argument!");
    }
    
    cursor_visibility(true); // SET CURSOR TO VISIBLE
    gotoxy(term_width, term_height); // SET POSITION TO END OF THE TERMINAL
    return 0; // EXIT THE APPLICATION
}

/* MADE BY @hanilr */