/* TERMINAL FILE FINDER (USER INTERFACE) [HEADER] */
#ifndef _UI_HPP
#define _UI_HPP

void clrscr(void);

void cursor_visibility(bool state);

void gotoxy(int pos_x, int pos_y);

void nline(int times); // NEW LINE

void bg_color(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor);

void draw_frame(int x_len, int y_len, int pos_x, int pos_y, std::string frame_color);

void user_warn(int x_len, int y_len, int pos_x, int pos_y, std::string fgcolor, std::string bgcolor, std::string frame_color, std::string warn_str);

void user_screen(int x_len, int y_len, int pos_x, int pos_y, std::string bgcolor, std::string frame_color);

#endif /* MADE BY @hanilr */