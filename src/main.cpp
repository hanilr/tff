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
    int term_width = term_x, term_height = term_y;
    struct color_variable cv[256];
    cv[0].color_count = 0;

    cursor_visibility(false);
    if(argc == 2 && strcmp(argv[1], "-install") == 0)
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "Do you accept to install? (y/n)");

        goto_color_print(divide_half(term_x)-2, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">   <");
        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        char install_decision = get_char_instantly();

        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        if(install_decision == 'y')
        {
            // INSTALL SECTION
            std::string term_size_x, term_size_y;
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal width?");
            goto_color_print(divide_half(term_x)-3, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">     <");

            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cout << colorfg_green << colorbg_gray << text_bold;
            std::cin >> term_size_x;
            std::cout << esc_reset;

            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal height?");
            goto_color_print(divide_half(term_x)-3, divide_half(term_y)+2, colorfg_white, colorbg_gray, text_bold, ">     <");
            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cout << colorfg_green << colorbg_gray << text_bold;
            std::cin >> term_size_y;
            std::cout << esc_reset;

            std::string main_dir = path_current();
            std::string term_config = term_size_x + "\n" + term_size_y;
            #ifdef _WIN32
                std::string compile_com = "g++ " + main_dir + "/src/main.cpp " + main_dir + "/src/file.cpp " + main_dir + "/src/util.cpp " + main_dir + "/src/ui.cpp " + main_dir + "/src/conf.cpp " + "-o ~/.tff/tff.exe";
                std::string dir_root = "C:\\", dir_main = "Program Files\\", conf_dir = "tff\\conf\\", data_dir = "tff\\data\\";
            #else
                std::string compile_com = "g++ " + main_dir + "/src/main.cpp " + main_dir + "/src/file.cpp " + main_dir + "/src/util.cpp " + main_dir + "/src/ui.cpp " + main_dir + "/src/conf.cpp " + "-o ~/.tff/tff";
                std::string dir_root = "/", dir_main = "home/" + get_username() + "/", conf_dir = ".tff/conf/", data_dir = ".tff/data/";
            #endif

            for(int x = 0, y = 10; y > x; x+=1)
            {
                path_change("../");
                if(path_current().compare(dir_root) == 0)
                {
                    path_change(dir_main);
                    create_dir(conf_dir, true);
                    create_dir(data_dir, false);
                    create_file(conf_dir + "terminal.txt");
                    create_file(data_dir + "color.txt");
                    create_file(conf_dir + "ui_color.txt");
                    write_file(conf_dir + "terminal.txt", term_config, 'w');
                    write_file(data_dir + "color.txt", "", 'w');
                    write_file(conf_dir + "ui_color.txt", "", 'w');
                    system(compile_com.c_str());
                    break;
                }
                if(x == 9)
                {
                    clrscr();
                    user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                }
            }
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Successfully installed!");
            // ---------------
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
            char uninstall_decision = get_char_instantly();

            if(uninstall_decision == 'y')
            {
                #ifdef _WIN32
                    std::string dir_name = "tff\\";
                #else
                    std::string dir_name = ".tff/";
                #endif
                delete_dir(dir_name, true);
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
        clrscr();
        bg_color(divide_half(term_x), term_y-1, divide_half(divide_half(term_x)), 0, colorbg_gray);
        draw_frame(divide_half(term_x), term_y-1, divide_half(divide_half(term_x)), 0, colorbg_white);
        file_list(divide_half(divide_half(term_x))+2, 2, term_y, colorbg_gray, colorfg_white);
    }
    else if(argc == 2 && strcmp(argv[1], "-keymap") == 0)
    {
        user_screen(term_x, term_y, 0, 0, colorbg_gray, colorbg_blue);
        
        goto_color_print(3, 3, colorfg_white, colorbg_gray, text_bold, "[ '/' ]");
        goto_color_print(11, 3, colorfg_white, colorbg_gray, "", keymap_search);
        goto_color_print(3, 4, colorfg_white, colorbg_gray, "", guide_search);

        goto_color_print(3, 21, colorfg_white, colorbg_gray, text_bold, "[ 'q' ]");
        goto_color_print(11, 21, colorfg_white, colorbg_gray, "", keymap_quit);
        goto_color_print(3, 22, colorfg_white, colorbg_gray, "", guide_quit);
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
        std::string mfgc, mbgc, mfc, wfgc, wbgc, wfc, lfgc, lbgc, lfc, sfgc, sbgc, sfc, efgc, ebgc, efc;
        bool perm_type = false;
        struct ui_color uc[14];

        if(is_installed() == true)
        {
            #ifdef _WIN32
                path_change("Program Files\\tff\\conf\\");
            #else
                path_change("home/" + get_username() + "/.tff/conf/");
            #endif
            term_width = std::stoi(read_file("terminal.txt", 1));
            term_height = std::stoi(read_file("terminal.txt", 2));
            perm_type = true;
        }
        if(perm_type == true) // CUSTOM COLOR DEFINES
        {
            #ifdef _WIN32
                std::string conf_path = "conf\\";
                std::string data_dir = "data\\";
            #else
                std::string conf_path = "conf/";
                std::string data_dir = "data/";
            #endif
            set_path_to_main();
            int line = count_line(data_dir + "color.txt");

            for(int i = 1; line+1 > i; i+=1)
            {
                cv[i].color_name = read_file(data_dir + "color.txt", i);
                cv[i].color_value = read_file(conf_path + cv[i].color_name + ".txt", 1);
                cv[0].color_count += 1;
            }
        }
        else
        { // FGC: FOREGROUND COLOR // BGC: BACKGROUND COLOR // FC: FRAME COLOR
            
            uc[0].fgc = colorfg_white, uc[0].bgc = colorbg_black, uc[0].fc = colorbg_gray; // MAIN SCREEN
            uc[1].fgc = colorfg_black, uc[1].bgc = colorbg_gray, uc[1].fc = colorbg_red; // WARNING SCREEN
            uc[2].fgc = colorfg_white, uc[2].bgc = colorbg_black; // LIST SCREEN
            uc[3].fgc = colorfg_green, uc[3].bgc = colorbg_gray, uc[3].fc = colorbg_green; // SUCCESS SCREEN
            uc[4].fgc = colorfg_red, uc[4].bgc = colorbg_gray, uc[4].fc = colorbg_red; // ERROR SCREEN
        }

        user_screen(term_width, term_height, 0, 0, uc[0].bgc, uc[0].fc);
        while(1)
        {
            goto_color_print(3, 3, uc[0].fgc, uc[0].bgc, text_bold, "[CURRENT PATH] ");
            goto_color_print(18, 3, uc[0].fgc, uc[0].bgc, "", path_current());
            file_list(0, 0, term_height, uc[2].fgc, uc[2].bgc);
            goto_color_print(3, term_height-1, uc[0].fgc, uc[0].bgc, text_bold, ">");

            goto_color_print(term_width-get_username().length()-14, 3, uc[0].fgc, uc[0].bgc, text_bold, "[USERNAME] ");
            goto_color_print(term_width-get_username().length()-3, 3, uc[0].fgc, uc[0].bgc, "", get_username());

            goto_color_print(term_width-get_username().length()-14, 5, uc[0].fgc, uc[0].bgc, text_bold, "[WIDTH] ");
            goto_color_print(term_width-get_username().length()-6, 5, uc[0].fgc, uc[0].bgc, "", std::to_string(term_width));

            goto_color_print(term_width-get_username().length()-14, 6, uc[0].fgc, uc[0].bgc, text_bold, "[HEIGHT] ");
            goto_color_print(term_width-get_username().length()-5, 6, uc[0].fgc, uc[0].bgc, "", std::to_string(term_height));

            gotoxy(5, term_height-1);
            std::cout << uc[0].fgc << uc[0].bgc;
            char key = get_char_instantly();
            std::cout << esc_reset;
            if(key == 'q') { gotoxy(term_width, term_height); }
            key_map(key, uc[0].fgc, uc[0].bgc);
            if(key == '/')
            {
                gotoxy(3, term_height-1);
                for(int i = 3; term_width > i; i+=1) { std::cout << uc[0].fgc << uc[0].bgc << " " << esc_reset; }
            }
        }
    }
    else if(argc > 1) // MISSING ARGUMENT ERROR
    //{
        //clrscr();
        //user_warn(term_x, term_y, 0, 0, colorfg_white, colorbg_black, colorbg_red, "[ERROR] Missing argument!");
    //}
    
    cursor_visibility(true);
    gotoxy(term_width, term_height);
    return 0;
}

/* MADE BY @hanilr */