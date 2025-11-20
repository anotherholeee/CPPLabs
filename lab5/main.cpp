#include "menu.h"
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=== ПРОГРАММА УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ ===" << std::endl;
    std::cout << "Используется двунаправленная очередь (дек)" << std::endl;

    Deque<Computer*> computers;
    run_main_menu(computers);

    return 0;
}