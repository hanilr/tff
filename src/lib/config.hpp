/* TERMINAL FILE FINDER (CONFIG) */
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

// ASCII ESCAPE SEQUENCE RESET CODE
#define esc_reset "\033[0m"

// ASCII ESCAPE SEQUENCE COLOR CODES
#define color_white "\033[38;2;233;233;233m"
#define color_black "\033[38;2;22;22;22m"
#define color_red "\033[38;2;200;55;55m"
#define color_green "\033[38;2;55;200;55m"
#define color_blue "\033[38;2;55;55;200m"

// ASCII ESCAPE SEQUENCE TEXT STYLES
#define text_bold "\033[1m"
#define text_italic "\033[3m"
#define text_underline "\033[4m"

// ASCII ESCAPE SEQUENCE UTIL CODES
#define clear_screen "\033[2J\033[H"
#define cursor_visible "\033[?25h"
#define cursor_invisible "\033[?25l"

#endif /* MADE BY @hanilr */