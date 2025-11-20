#include "menu.h"
#include <iostream>
#include <limits>

void show_main_menu() {
    std::cout << "\nМеню:" << std::endl;
    std::cout << "1. Добавить моноблок" << std::endl;
    std::cout << "2. Добавить ноутбук" << std::endl;
    std::cout << "3. Добавить планшет" << std::endl;
    std::cout << "4. Показать все устройства в таблице" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

void handle_menu_choice(Computer* computers[], int& actual_count, int choice) {
    switch (choice) {
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;
        case 1:
            if (actual_count < MAX_COMPUTERS) {
                computers[actual_count] = new Monoblock();
                computers[actual_count]->set_info();
                actual_count++;
                std::cout << "Моноблок добавлен!" << std::endl;
            } else {
                std::cout << "Достигнут лимит устройств!" << std::endl;
            }
            break;
        case 2:
            if (actual_count < MAX_COMPUTERS) {
                computers[actual_count] = new Laptop();
                computers[actual_count]->set_info();
                actual_count++;
                std::cout << "Ноутбук добавлен!" << std::endl;
            } else {
                std::cout << "Достигнут лимит устройств!" << std::endl;
            }
            break;
        case 3:
            if (actual_count < MAX_COMPUTERS) {
                computers[actual_count] = new Tablet();
                computers[actual_count]->set_info();
                actual_count++;
                std::cout << "Планшет добавлен!" << std::endl;
            } else {
                std::cout << "Достигнут лимит устройств!" << std::endl;
            }
            break;
        case 4:
            // Вывод шапки и перегрузка вывода через setw
            display_all_computers_table(computers, actual_count);
            break;
        default:
            std::cout << "Неверный выбор! Повторите попытку." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }
}

void run_main_menu(Computer* computers[], int size) {
    int actual_count = 0;
    bool exit_program = false;

    while (actual_count < size && !exit_program) {
        show_main_menu();

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            exit_program = true;
        }

        handle_menu_choice(computers, actual_count, choice);
    }

    // Показываем финальную таблицу перед выходом
    if (actual_count > 0) {
        std::cout << "\nФинальный список устройств:" << std::endl;
        display_all_computers_table(computers, actual_count);
    }

    // Освобождаем память
    for (int i = 0; i < actual_count; i++) {
        delete computers[i];
    }
}