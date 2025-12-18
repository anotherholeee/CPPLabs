#include "computer.h"
#include "menu.h"
#include "deque.h"
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=== ПРОГРАММА УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ ===" << std::endl;
    std::cout << "Используется двунаправленная очередь (дек)" << std::endl;

    Deque<Computer*> computers;
    Menu menu(computers);
    menu.run();

    return 0;
}