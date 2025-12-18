#include "menu.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Конструктор
Menu::Menu(Deque<Computer*>& computers) : computers(computers) {}

// Метод для отображения главного меню
void Menu::show_main_menu() {
    std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ ===" << std::endl;
    std::cout << "1. Добавить устройство в конец" << std::endl;
    std::cout << "2. Добавить устройство в начало" << std::endl;
    std::cout << "3. Показать все устройства в таблице" << std::endl;
    std::cout << "4. Показать структуру дека" << std::endl;
    std::cout << "5. Удалить первое устройство" << std::endl;
    std::cout << "6. Удалить последнее устройство" << std::endl;
    std::cout << "7. Сортировать устройства" << std::endl;
    std::cout << "8. Поиск устройств" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

// Метод 1: Добавить устройство в конец
void Menu::addDeviceToEnd() {
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
}

// Метод 2: Добавить устройство в начало
void Menu::addDeviceToFront() {
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
}

// Метод 3: Показать все устройства в таблице
void Menu::showAllDevices() {
    display_all_computers_table(computers);
}

// Метод 4: Показать структуру дека
void Menu::showDequeStructure() {
    std::cout << "\n=== СТРУКТУРА ДЕКА ===" << std::endl;
    std::cout << "Размер дека: " << computers.size() << std::endl;
    computers.display();
}

// Метод 5: Удалить первое устройство
void Menu::removeFirstDevice() {
    if (!computers.empty()) {
        delete computers.getFront();
        computers.popFront();
        std::cout << "Первое устройство удалено!" << std::endl;
    } else {
        std::cout << "Дек пуст!" << std::endl;
    }
}

// Метод 6: Удалить последнее устройство
void Menu::removeLastDevice() {
    if (!computers.empty()) {
        delete computers.getBack();
        computers.popBack();
        std::cout << "Последнее устройство удалено!" << std::endl;
    } else {
        std::cout << "Дек пуст!" << std::endl;
    }
}

// Метод 7: Сортировать устройства
void Menu::sortDevices() {
    if (computers.empty()) {
        std::cout << "Дек пуст! Нечего сортировать." << std::endl;
        return;
    }
    
    std::cout << "\n=== ВЫБОР ПОЛЯ ДЛЯ СОРТИРОВКИ ===" << std::endl;
    std::cout << "1. По бренду" << std::endl;
    std::cout << "2. По размеру экрана" << std::endl;
    std::cout << "3. По объему оперативной памяти" << std::endl;
    std::cout << "Ваш выбор: ";
    
    int choice;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            // Сортировка по бренду (по возрастанию)
            computers.sort([](Computer* a, Computer* b) {
                return a->getBrand() > b->getBrand();
            });
            std::cout << "Устройства отсортированы по бренду!" << std::endl;
            break;
        case 2:
            // Сортировка по размеру экрана (по возрастанию)
            computers.sort([](Computer* a, Computer* b) {
                return a->getScreensize() > b->getScreensize();
            });
            std::cout << "Устройства отсортированы по размеру экрана!" << std::endl;
            break;
        case 3:
            // Сортировка по объему оперативной памяти (по возрастанию)
            computers.sort([](Computer* a, Computer* b) {
                return a->getRam() > b->getRam();
            });
            std::cout << "Устройства отсортированы по объему оперативной памяти!" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            return;
    }
    
    // Показываем отсортированный список
    display_all_computers_table(computers);
}

// Метод 8: Поиск устройств
void Menu::searchDevices() {
    if (computers.empty()) {
        std::cout << "Дек пуст! Нечего искать." << std::endl;
        return;
    }
    
    std::cout << "\n=== ВЫБОР ПАРАМЕТРА ДЛЯ ПОИСКА ===" << std::endl;
    std::cout << "1. По бренду" << std::endl;
    std::cout << "2. По размеру экрана" << std::endl;
    std::cout << "3. По объему оперативной памяти" << std::endl;
    std::cout << "Ваш выбор: ";
    
    int choice;
    std::cin >> choice;
    
    Deque<Computer*> results;
    
    switch (choice) {
        case 1: {
            // Поиск по бренду
            std::string searchBrand;
            std::cout << "Введите бренд для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, searchBrand);
            
            // Проходим по всем элементам дека
            for (size_t i = 0; i < computers.size(); i++) {
                Computer* comp = computers.getAt(i);
                if (comp != nullptr && comp->getBrand() == searchBrand) {
                    results.pushBack(comp);
                }
            }
            
            if (results.empty()) {
                std::cout << "Устройства с брендом \"" << searchBrand << "\" не найдены." << std::endl;
            } else {
                std::cout << "Найдено устройств: " << results.size() << std::endl;
                display_all_computers_table(results);
            }
            break;
        }
        case 2: {
            // Поиск по размеру экрана
            float searchSize;
            std::cout << "Введите размер экрана для поиска: ";
            std::cin >> searchSize;
            
            for (size_t i = 0; i < computers.size(); i++) {
                Computer* comp = computers.getAt(i);
                if (comp != nullptr && comp->getScreensize() == searchSize) {
                    results.pushBack(comp);
                }
            }
            
            if (results.empty()) {
                std::cout << "Устройства с размером экрана " << searchSize << "\" не найдены." << std::endl;
            } else {
                std::cout << "Найдено устройств: " << results.size() << std::endl;
                display_all_computers_table(results);
            }
            break;
        }
        case 3: {
            // Поиск по объему оперативной памяти
            int searchRam;
            std::cout << "Введите объем оперативной памяти для поиска: ";
            std::cin >> searchRam;
            
            for (size_t i = 0; i < computers.size(); i++) {
                Computer* comp = computers.getAt(i);
                if (comp != nullptr && comp->getRam() == searchRam) {
                    results.pushBack(comp);
                }
            }
            
            if (results.empty()) {
                std::cout << "Устройства с объемом памяти " << searchRam << " ГБ не найдены." << std::endl;
            } else {
                std::cout << "Найдено устройств: " << results.size() << std::endl;
                display_all_computers_table(results);
            }
            break;
        }
        default:
            std::cout << "Неверный выбор!" << std::endl;
            return;
    }
}

// Метод для обработки выбора пользователя
void Menu::handle_menu_choice(int choice) {
    switch (choice) {
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;
        case 1:
            addDeviceToEnd();
            break;
        case 2:
            addDeviceToFront();
            break;
        case 3:
            showAllDevices();
            break;
        case 4:
            showDequeStructure();
            break;
        case 5:
            removeFirstDevice();
            break;
        case 6:
            removeLastDevice();
            break;
        case 7:
            sortDevices();
            break;
        case 8:
            searchDevices();
            break;
        default:
            std::cout << "Неверный выбор! Повторите попытку." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }
}

// Метод для запуска главного цикла меню
void Menu::run() {
    bool exit_program = false;

    while (!exit_program) {
        show_main_menu();

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            exit_program = true;
        } else {
            handle_menu_choice(choice);
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