/* TERMINAL FILE FINDER (CONFIG) */
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

// ASCII ESCAPE SEQUENCE RESET CODE
#define esc_reset "\033[0m"

// ASCII ESCAPE SEQUENCE COLOR CODES
// FOREGROUND COLORS //
#define colorfg_white "\033[38;2;233;233;233m"
#define colorfg_black "\033[38;2;22;22;22m"
#define colorfg_red "\033[38;2;200;55;55m"
#define colorfg_green "\033[38;2;55;200;55m"
#define colorfg_blue "\033[38;2;55;55;200m"
// BACKGROUND COLORS //
#define colorbg_white "\033[48;2;233;233;233m"
#define colorbg_black "\033[48;2;22;22;22m"
#define colorbg_red "\033[48;2;200;55;55m"
#define colorbg_green "\033[48;2;55;200;55m"
#define colorbg_blue "\033[48;2;55;55;200m"

// ASCII ESCAPE SEQUENCE TEXT STYLES
#define text_bold "\033[1m"
#define text_italic "\033[3m"
#define text_underline "\033[4m"

// ASCII ESCAPE SEQUENCE UTILITY CODES
#define clear_screen "\033[2J\033[H"
#define cursor_visible "\033[?25h"
#define cursor_invisible "\033[?25l"

#endif /* MADE BY @hanilr */