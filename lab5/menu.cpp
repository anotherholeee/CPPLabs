#include "menu.h"

void show_main_menu() {
    std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ ===" << std::endl;
    std::cout << "1. Добавить устройство в начало" << std::endl;
    std::cout << "2. Добавить устройство в конец" << std::endl;
    std::cout << "3. Удалить первое устройство" << std::endl;
    std::cout << "4. Удалить последнее устройство" << std::endl;
    std::cout << "5. Показать все устройства в таблице" << std::endl;
    std::cout << "6. Показать структуру дека" << std::endl;
    std::cout << "7. Сортировка устройств" << std::endl;
    std::cout << "8. Поиск устройств" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

void show_device_type_menu() {
    std::cout << "\n=== ВЫБОР ТИПА УСТРОЙСТВА ===" << std::endl;
    std::cout << "1. Моноблок" << std::endl;
    std::cout << "2. Ноутбук" << std::endl;
    std::cout << "3. Планшет" << std::endl;
    std::cout << "Ваш выбор: ";
}

void show_sort_menu() {
    std::cout << "\n=== ВЫБОР ПОЛЯ ДЛЯ СОРТИРОВКИ ===" << std::endl;
    std::cout << "1. По бренду" << std::endl;
    std::cout << "2. По размеру экрана" << std::endl;
    std::cout << "3. По объему оперативной памяти" << std::endl;
    std::cout << "Ваш выбор: ";
}

void show_search_menu() {
    std::cout << "\n=== ВЫБОР ПОЛЯ ДЛЯ ПОИСКА ===" << std::endl;
    std::cout << "1. По бренду" << std::endl;
    std::cout << "2. По размеру экрана" << std::endl;
    std::cout << "3. По объему оперативной памяти" << std::endl;
    std::cout << "4. По типу устройства" << std::endl;
    std::cout << "Ваш выбор: ";
}

Computer* create_computer_by_type(int type) {
    switch (type) {
        case 1: return new Monoblock();
        case 2: return new Laptop();
        case 3: return new Tablet();
        default: return nullptr;
    }
}

void display_all_computers_table(Deque<Computer*>& computers) {
    if (computers.empty()) {
        std::cout << "Нет компьютеров для отображения." << std::endl;
        return;
    }

    std::cout << "\nТАБЛИЦА КОМПЬЮТЕРОВ" << std::endl;

    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Доп. параметр  |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;

    Deque<Computer*> temp;
    int index = 1;

    while (!computers.empty()) {
        Computer* comp = computers.getFront();
        computers.popFront();

        std::string additionalParam;
        if (auto* mb = dynamic_cast<Monoblock*>(comp)) {
            additionalParam = std::to_string(mb->getPowerSupply()) + " Вт";
        }
        else if (auto* laptop = dynamic_cast<Laptop*>(comp)) {
            additionalParam = std::to_string(laptop->getBatteryLife()) + " ч";
        }
        else if (auto* tablet = dynamic_cast<Tablet*>(comp)) {
            additionalParam = std::to_string(tablet->getBatteryLife()) + " ч";
        }
        else if (auto* sc = dynamic_cast<Static_computer*>(comp)) {
            additionalParam = std::to_string(sc->getPowerSupply()) + " Вт";
        }
        else if (auto* pc = dynamic_cast<Portable_computer*>(comp)) {
            additionalParam = std::to_string(pc->getBatteryLife()) + " ч";
        }
        else {
            additionalParam = " - ";
        }

        std::cout << "| " << std::setw(2) << std::right << index
             << " | " << std::setw(20) << std::left << comp->getBrand().substr(0, 20)
             << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << comp->getScreensize()
             << " | " << std::setw(6) << std::right << comp->getRam()
             << " | " << std::setw(12) << std::left << comp->getType()
             << " | " << std::setw(14) << std::left << additionalParam
             << " |" << std::endl;

        temp.pushBack(comp);
        index++;
    }

    while (!temp.empty()) {
        Computer* comp = temp.getFront();
        temp.popFront();
        computers.pushBack(comp);
    }

    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "Всего устройств: " << computers.size() << std::endl << std::endl;
}

void sort_computers(Deque<Computer*>& computers) {
    if (computers.empty()) {
        std::cout << "Дек пуст! Нечего сортировать." << std::endl;
        return;
    }

    show_sort_menu();
    int choice;
    std::cin >> choice;

    Deque<Computer*> elements;
    Deque<Computer*> temp;

    while (!computers.empty()) {
        Computer* comp = computers.getFront();
        computers.popFront();
        elements.pushBack(comp);
        temp.pushBack(comp);
    }

    while (!temp.empty()) {
        Computer* comp = temp.getFront();
        temp.popFront();
        computers.pushBack(comp);
    }

    bool swapped;
    do {
        swapped = false;
        Deque<Computer*> tempSort;

        while (!elements.empty()) {
            Computer* current = elements.getFront();
            elements.popFront();
            tempSort.pushBack(current);
        }

        while (!tempSort.empty()) {
            Computer* current = tempSort.getFront();
            tempSort.popFront();

            if (!tempSort.empty()) {
                Computer* next = tempSort.getFront();

                bool needSwap = false;
                switch (choice) {
                    case 1:
                        needSwap = current->getBrand() > next->getBrand();
                        break;
                    case 2:
                        needSwap = current->getScreensize() > next->getScreensize();
                        break;
                    case 3:
                        needSwap = current->getRam() > next->getRam();
                        break;
                    default:
                        std::cout << "Неверный выбор!" << std::endl;
                        return;
                }

                if (needSwap) {
                    std::swap(current, next);
                    swapped = true;
                }
            }
            elements.pushBack(current);
        }
    } while (swapped);

    while (!computers.empty()) {
        computers.popFront();
    }

    while (!elements.empty()) {
        Computer* comp = elements.getFront();
        elements.popFront();
        computers.pushBack(comp);
    }

    std::cout << "Устройства отсортированы!" << std::endl;
    display_all_computers_table(computers);
}

void search_computers(Deque<Computer*>& computers) {
    if (computers.empty()) {
        std::cout << "Дек пуст! Нечего искать." << std::endl;
        return;
    }

    show_search_menu();
    int choice;
    std::cin >> choice;

    std::string searchStr;
    float searchFloat;
    int searchInt;

    Deque<Computer*> results;

    switch (choice) {
        case 1:
            std::cout << "Введите бренд для поиска: ";
            std::cin >> searchStr;
            break;
        case 2:
            std::cout << "Введите размер экрана для поиска: ";
            std::cin >> searchFloat;
            break;
        case 3:
            std::cout << "Введите объем ОЗУ для поиска: ";
            std::cin >> searchInt;
            break;
        case 4:
            std::cout << "Введите тип устройства (Моноблок/Ноутбук/Планшет): ";
            std::cin >> searchStr;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            return;
    }

    Deque<Computer*> temp;
    while (!computers.empty()) {
        Computer* comp = computers.getFront();
        computers.popFront();

        bool match = false;
        switch (choice) {
            case 1: match = (comp->getBrand() == searchStr); break;
            case 2: match = (comp->getScreensize() == searchFloat); break;
            case 3: match = (comp->getRam() == searchInt); break;
            case 4: match = (comp->getType() == searchStr); break;
            default: match = false; break;
        }

        if (match) {
            results.pushBack(comp);
        }
        temp.pushBack(comp);
    }

    while (!temp.empty()) {
        Computer* comp = temp.getFront();
        temp.popFront();
        computers.pushBack(comp);
    }

    if (results.empty()) {
        std::cout << "Устройства не найдены!" << std::endl;
    } else {
        std::cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===" << std::endl;
        display_all_computers_table(results);
    }
}

void handle_menu_choice(Deque<Computer*>& computers, int choice) {
    switch (choice) {
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;
        case 1:
        case 2:
            show_device_type_menu();
            int type;
            std::cin >> type;

            if (type >= 1 && type <= 3) {
                if (Computer* newComputer = create_computer_by_type(type)) {
                    newComputer->set_info();

                    if (choice == 1) {
                        computers.pushFront(newComputer);
                    } else {
                        computers.pushBack(newComputer);
                    }
                    std::cout << "Устройство добавлено!" << std::endl;
                }
            } else {
                std::cout << "Неверный выбор типа устройства!" << std::endl;
            }
            break;
        case 3:
            if (!computers.empty()) {
                delete computers.getFront();
                computers.popFront();
                std::cout << "Первое устройство удалено!" << std::endl;
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        case 4:
            if (!computers.empty()) {
                delete computers.getBack();
                computers.popBack();
                std::cout << "Последнее устройство удалено!" << std::endl;
            } else {
                std::cout << "Дек пуст!" << std::endl;
            }
            break;
        case 5:
            display_all_computers_table(computers);
            break;
        case 6:
            std::cout << "\n=== СТРУКТУРА ДЕКА ===" << std::endl;
            std::cout << "Размер дека: " << computers.size() << std::endl;
            computers.display();
            break;
        case 7:
            sort_computers(computers);
            break;
        case 8:
            search_computers(computers);
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

    if (!computers.empty()) {
        std::cout << "\n=== ФИНАЛЬНЫЙ СПИСОК УСТРОЙСТВ ===" << std::endl;
        display_all_computers_table(computers);
    }

    while (!computers.empty()) {
        delete computers.getFront();
        computers.popFront();
    }

    std::cout << "Память освобождена. Программа завершена." << std::endl;
}