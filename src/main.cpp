/* TERMINAL FILE FINDER (MAIN) */

// STANDARD LIBRARY
#include <iostream>
#include <cstring>
#include <fstream>

// DIY LIBRARY
#include "lib/config.hpp"
#include "lib/file.hpp"
#include "lib/util.hpp"
#include "lib/ui.hpp"

int main(int argc, char* argv[])
{
    cursor_visibility(false);
    if(argc > 1 && strcmp(argv[1], "-install") == 0)
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "Do you accept to install? (y/n)");

        gotoxy(divide_half(term_x)-2, divide_half(term_y)+2);
        std::cout << colorfg_white << colorbg_gray << text_bold << ">   <" << esc_reset;
        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        char install_decision = get_char_instantly();

        gotoxy(divide_half(term_x), divide_half(term_y)+2);
        if(install_decision == 'y')
        {
            // INSTALL SECTION
            std::string term_size_x, term_size_y;
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal width?");
            gotoxy(divide_half(term_x)-3, divide_half(term_y)+2);
            std::cout << colorfg_white << colorbg_gray << text_bold << ">     <" << esc_reset;
            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cin >> term_size_x;

            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "What is your terminal height?");
            gotoxy(divide_half(term_x)-3, divide_half(term_y)+2);
            std::cout << colorfg_white << colorbg_gray << text_bold << ">     <" << esc_reset;
            gotoxy(divide_half(term_x)-1, divide_half(term_y)+2);
            std::cin >> term_size_y;
            
            #ifdef _WIN32
                std::string main_dir = path_current();
                std::string compile_com = "g++ " + main_dir + "/src/main.cpp " + main_dir + "/src/file.cpp " + main_dir + "/src/util.cpp " + main_dir + "/src/ui.cpp " + "-o ~/.tff/tff.exe";
                std::string term_config = term_size_x + "\n" + term_size_y;
                for(int x = 0, y = 10; y > x; x+=1)
                {
                    path_change("../");
                    if(path_current().compare("C:\\") == 0)
                    {
                        path_change("Program Files\\");
                        create_dir(".tff/conf/", true);
                        create_dir(".tff/data/", false);
                        create_file(".tff/conf/terminal.txt");
                        write_file(".tff/conf/terminal.txt", term_config, 'w');
                        system(compile_com.c_str());
                        break;
                    }
                    if(x == 9)
                    {
                        clrscr();
                        user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                    }
                }
            #else
                std::string main_dir = path_current();
                std::string compile_com = "g++ " + main_dir + "/src/main.cpp " + main_dir + "/src/file.cpp " + main_dir + "/src/util.cpp " + main_dir + "/src/ui.cpp " + "-o ~/.tff/tff";
                std::string term_config = term_size_x + "\n" + term_size_y;
                for(int x = 0, y = 10; y > x; x+=1)
                {
                    path_change("../");
                    if(path_current().compare("/") == 0)
                    {
                        path_change("home/" + get_username() + "/");
                        create_dir(".tff/conf/", true);
                        create_dir(".tff/data/", false);
                        create_file(".tff/conf/terminal.txt");
                        write_file(".tff/conf/terminal.txt", term_config, 'w');
                        system(compile_com.c_str());
                        break;
                    }
                    if(x == 9)
                    {
                        clrscr();
                        user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                    }
                }
            #endif

            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_green, "Successfully installed!");
            // ---------------
        }
        else { std::cout << colorfg_white << colorbg_gray << text_bold << "n" << esc_reset; }
    }
    else if(argc > 1 && strcmp(argv[1], "-uninstall") == 0)
    {
        #ifdef _WIN32
                std::string app_path = "Program Files\\tff\\tff.exe";
                for(int x = 0, y = 10; y > x; x+=1)
                    {
                        path_change("../");
                        if(path_current().compare("C:\\") == 0) { break; }
                        if(x == 9)
                        {
                            clrscr();
                            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                        }
                    }
        #else
                std::string app_path = "home/" + get_username() + "/.tff/tff";
                for(int x = 0, y = 10; y > x; x+=1)
                    {
                        path_change("../");
                        if(path_current().compare("/") == 0) { break; }
                        if(x == 9)
                        {
                            clrscr();
                            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                        }
                    }
        #endif

        if(is_file(app_path) == true)
        {
            clrscr();
            user_warn(term_x, term_y, 0, 0, colorfg_green, colorbg_gray, colorbg_white, "Do you accept to uninstall? (y/n)");

            gotoxy(divide_half(term_x)-2, divide_half(term_y)+2);
            std::cout << colorfg_white << colorbg_gray << text_bold << ">   <" << esc_reset;
            gotoxy(divide_half(term_x), divide_half(term_y)+2);
            char uninstall_decision = get_char_instantly();

            if(uninstall_decision == 'y')
            {
                #ifdef _WIN32
                    for(int x = 0, y = 10; y > x; x+=1)
                    {
                        path_change("../");
                        if(path_current().compare("C:\\") == 0)
                        {
                            path_change("Program Files\\");
                            delete_dir("tff/", true);
                            break;
                        }
                        if(x == 9)
                        {
                            clrscr();
                            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                        }
                    }
                #else
                    for(int x = 0, y = 10; y > x; x+=1)
                    {
                        path_change("../");
                        if(path_current().compare("/") == 0)
                        {
                            path_change("home/" + get_username() + "/");
                            delete_dir(".tff/", true);
                            break;
                        }
                        if(x == 9)
                        {
                            clrscr();
                            user_warn(term_x, term_y, 0, 0, colorfg_red, colorbg_gray, colorbg_red, "[ERROR] Root directory fault!");
                        }
                    }
                #endif
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
    else if(argc > 1 && strcmp(argv[1], "-list") == 0)
    {
        clrscr();
        bg_color(divide_half(term_x), term_y-1, divide_half(divide_half(term_x)), 0, colorbg_gray);
        draw_frame(divide_half(term_x), term_y-1, divide_half(divide_half(term_x)), 0, colorbg_white);
        file_list(divide_half(divide_half(term_x))+2, 2, colorbg_gray, colorfg_white);
    }
    else if(argc > 1 && strcmp(argv[1], "-keymap") == 0)
    {
        user_screen(term_x, term_y, 0, 0, colorbg_gray, colorbg_blue);
        
        gotoxy(3, 3);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ '/' ]" << esc_reset;
        gotoxy(11, 3);
        std::cout << colorfg_white << colorbg_gray << keymap_search << esc_reset;
        gotoxy(3, 4);
        std::cout << colorfg_white << colorbg_gray << guide_search << esc_reset;

        gotoxy(3, 6);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ 'l' ]" << esc_reset;
        gotoxy(11, 6);
        std::cout << colorfg_white << colorbg_gray << keymap_list << esc_reset;
        gotoxy(3, 7);
        std::cout << colorfg_white << colorbg_gray << guide_list << esc_reset;

        gotoxy(3, 21);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ 'q' ]" << esc_reset;
        gotoxy(11, 21);
        std::cout << colorfg_white << colorbg_gray << keymap_quit << esc_reset;
        gotoxy(3, 22);
        std::cout << colorfg_white << colorbg_gray << guide_quit << esc_reset;
    }
    else if(argc > 1 && strcmp(argv[1], "-help") == 0)
    {
        user_screen(term_x, term_y, 0, 0, colorbg_gray, colorbg_green);

        gotoxy(3, 3);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ -install ]" << esc_reset;
        gotoxy(3, 4);
        std::cout << colorfg_white << colorbg_gray << help_install << esc_reset;
        gotoxy(3, 5);
        std::cout << colorfg_white << colorbg_gray << suggest_install << esc_reset;

        gotoxy(3, 7);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ -uninstall ]" << esc_reset;
        gotoxy(3, 8);
        std::cout << colorfg_white << colorbg_gray << help_uninstall << esc_reset;
        gotoxy(3, 9);
        std::cout << colorfg_white << colorbg_gray << suggest_uninstall << esc_reset;

        gotoxy(3, 11);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ -list ]" << esc_reset;
        gotoxy(3, 12);
        std::cout << colorfg_white << colorbg_gray << help_list << esc_reset;
        gotoxy(3, 13);
        std::cout << colorfg_white << colorbg_gray << suggest_list << esc_reset;

        gotoxy(3, 15);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ -keymap ]" << esc_reset;
        gotoxy(3, 16);
        std::cout << colorfg_white << colorbg_gray << help_keymap << esc_reset;
        gotoxy(3, 17);
        std::cout << colorfg_white << colorbg_gray << suggest_keymap << esc_reset;

        gotoxy(3, 22);
        std::cout << colorfg_white << colorbg_gray << text_bold << "[ -help ]" << esc_reset;
        gotoxy(13, 22);
        std::cout << colorfg_white << colorbg_gray << help_help << esc_reset;
    }
    else
    {
        clrscr();
        user_warn(term_x, term_y, 0, 0, colorfg_white, colorbg_black, colorbg_red, "[ERROR] Missing argument!");
    }


    gotoxy(term_x, term_y);
    cursor_visibility(true);
    return 0;
}

/* MADE BY @hanilr */