/* TERMINAL FILE FINDER (CONFIG) */
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

// DEFAULT TERMINAL SIZE
#define term_x 80
#define term_y 24

// ASCII ESCAPE SEQUENCE RESET CODE
#define esc_reset "\033[0m"

// ASCII ESCAPE SEQUENCE COLOR CODES
// FOREGROUND COLORS //
#define colorfg_white "\033[38;2;233;233;233m"
#define colorfg_black "\033[38;2;22;22;22m"
#define colorfg_gray "\033[38;2;48;48;48m"
#define colorfg_red "\033[38;2;200;55;55m"
#define colorfg_green "\033[38;2;55;200;55m"
#define colorfg_blue "\033[38;2;55;55;200m"
// BACKGROUND COLORS //
#define colorbg_white "\033[48;2;233;233;233m"
#define colorbg_black "\033[48;2;22;22;22m"
#define colorbg_gray "\033[48;2;48;48;48m"
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

// MESSAGES
#define help_install "Install this app to your device. You can uninstall later."
#define suggest_install "> You can change terminal size and add new colors, if you did."
#define help_uninstall "Uninstall this app from your device."
#define suggest_uninstall "> There is no empty directory after uninstalling."
#define help_list "Display what's inside a directory."
#define suggest_list "> You don't have to execute whole program for listing files."
#define help_keymap "Guide of keymaps. If you don't know keymaps of this app."
#define suggest_keymap "> You can have much more comfort while using this app."
#define help_help "This section."

#define keymap_search "File search section."
#define guide_search "Type '/', enter file name then type 'return'."
#define keymap_list "Get file list of current path."
#define guide_list "Type 'l' then you'll get panel at right side."
#define keymap_quit "To quit this app."
#define guide_quit "Type 'q' then quit."

#endif /* MADE BY @hanilr */