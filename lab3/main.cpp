#include "computer.h"
#include "menu.h"
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Computer* computers[MAX_COMPUTERS] = {nullptr};
    run_main_menu(computers, MAX_COMPUTERS);

    return 0;
}