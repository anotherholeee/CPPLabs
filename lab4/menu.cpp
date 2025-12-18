#include "menu.h"
#include <iostream>
#include <limits>

using namespace std;

void show_main_menu() {
    std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ ===" << std::endl;
    std::cout << "1. Добавить устройство в конец" << std::endl;
    std::cout << "2. Добавить устройство в начало" << std::endl;
    std::cout << "3. Показать все устройства в таблице" << std::endl;
    std::cout << "4. Показать структуру дека" << std::endl;
    std::cout << "5. Удалить первое устройство" << std::endl;
    std::cout << "6. Удалить последнее устройство" << std::endl;
    std::cout << "7. Показать первое устройство" << std::endl;
    std::cout << "8. Показать последнее устройство" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

void handle_menu_choice(Deque<Computer*>& computers, int choice) {
    switch (choice) {
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;
        case 1: {
            int type;
            std::cout << "Выберите тип устройства для добавления в конец:" << std::endl;
            std::cout << "1. Моноблок" << std::endl;
            std::cout << "2. Ноутбук" << std::endl;
            std::cout << "3. Планшет" << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> type;
            
            Computer* newComputer = nullptr;
            switch (type) {
                case 1: newComputer = new Monoblock(); break;
                case 2: newComputer = new Laptop(); break;
                case 3: newComputer = new Tablet(); break;
                default: 
                    std::cout << "Неверный выбор!" << std::endl;
                    return;
            }
            
            if (newComputer) {
                newComputer->set_info();
                computers.pushBack(newComputer);
                std::cout << "Устройство добавлено в конец дека!" << std::endl;
            }
            break;
        }
        case 2: {
            int type;
            std::cout << "Выберите тип устройства для добавления в начало:" << std::endl;
            std::cout << "1. Моноблок" << std::endl;
            std::cout << "2. Ноутбук" << std::endl;
            std::cout << "3. Планшет" << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> type;
            
            Computer* newComputer = nullptr;
            switch (type) {
                case 1: newComputer = new Monoblock(); break;
                case 2: newComputer = new Laptop(); break;
                case 3: newComputer = new Tablet(); break;
                default: 
                    std::cout << "Неверный выбор!" << std::endl;
                    return;
            }
            
            if (newComputer) {
                newComputer->set_info();
                computers.pushFront(newComputer);
                std::cout << "Устройство добавлено в начало дека!" << std::endl;
            }
            break;
        }
        case 3:
            display_all_computers_table(computers);
            break;
        case 4:
            std::cout << "\n=== СТРУКТУРА ДЕКА ===" << std::endl;
            std::cout << "Размер дека: " << computers.size() << std::endl;
            computers.display();
            break;
        case 5:
            if (!computers.empty()) {
                delete computers.getFront();
                computers.popFront();
                std::cout << "Первое устройство удалено!" << std::endl;
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        case 6:
            if (!computers.empty()) {
                delete computers.getBack();
                computers.popBack();
                std::cout << "Последнее устройство удалено!" << std::endl;
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        case 7:
            if (!computers.empty()) {
                std::cout << "\n=== ПЕРВОЕ УСТРОЙСТВО ===" << std::endl;
                computers.getFront()->get_info();
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        case 8:
            if (!computers.empty()) {
                std::cout << "\n=== ПОСЛЕДНЕЕ УСТРОЙСТВО ===" << std::endl;
                computers.getBack()->get_info();
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        default:
            std::cout << "Неверный выбор! Повторите попытку." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }
}

void run_main_menu(Deque<Computer*>& computers) {
    bool exit_program = false;

    while (!exit_program) {
        show_main_menu();

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            exit_program = true;
        } else {
            handle_menu_choice(computers, choice);
        }
    }

    // Показываем финальную таблицу перед выходом
    if (!computers.empty()) {
        std::cout << "\n=== ФИНАЛЬНЫЙ СПИСОК УСТРОЙСТВ ===" << std::endl;
        display_all_computers_table(computers);
    }

    // Освобождаем память
    while (!computers.empty()) {
        delete computers.getFront();
        computers.popFront();
    }
    
    std::cout << "Память освобождена. Программа завершена." << std::endl;
}