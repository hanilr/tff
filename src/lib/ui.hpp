/* TERMINAL FILE FINDER (USER INTERFACE) [HEADER] */
#ifndef _UI_HPP
#define _UI_HPP

void clrscr(void);

void cursor_visibility(bool state);

void gotoxy(int pos_x, int pos_y);

void nline(int times); // NEW LINE

void draw_frame(int x_len, int y_len, std::string frame_color);

#endif /* MADE BY @hanilr */