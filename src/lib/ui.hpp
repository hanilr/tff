/* TERMINAL FILE FINDER (USER INTERFACE) [HEADER] */
#ifndef _UI_HPP
#define _UI_HPP

void clrscr(void); // CLEAR SCREEN

void cursor_visibility(bool state); // CHANGE CURSOR VISIBILITY

void gotoxy(int pos_x, int pos_y); // GO TO X AND Y POSITIONS

void goto_color_print(int pos_x, int pos_y, std::string arg1, std::string arg2, std::string arg3, std::string print_str); // CHANGE POSITION AND PRINT WITH COLOR

void bg_color(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor); // SET BACKGROUND COLOR

void draw_frame(int x_len, int y_len, int pos_x, int pos_y, std::string frame_color); // DRAW A FRAME WITH COLOR

void user_warn(int x_len, int y_len, int pos_x, int pos_y, std::string fgcolor, std::string bgcolor, std::string frame_color, std::string warn_str); // WARN THE USER WITH COLOR

void user_screen(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor, std::string frame_color); // PREPARE USER SCREEN WITH COLOR

#endif /* MADE BY @hanilr */