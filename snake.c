#include <stdio.h>
#include <stdlib.h>
#ifdef __WIN32
#include <winbase.h>
#include <wincon.h>
#include <windef.h>
#endif

void init_console();
void enable_vt_mode();

void clean_screen() {
}

int main() {
    init_console();
    int width = 50;
    int height = 20;

    return EXIT_SUCCESS;
}

void init_console() {
    enable_vt_mode();
}

void enable_vt_mode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}