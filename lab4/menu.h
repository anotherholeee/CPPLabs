#ifndef MENU_H
#define MENU_H

#include "computer.h"
#include "monoblock.h"
#include "laptop.h"
#include "tablet.h"
#include "deque.h"

// Класс меню
class Menu {
private:
    Deque<Computer*>& computers;
    int selectedDeviceType;  // Выбранный тип устройства (1-Моноблок, 2-Ноутбук, 3-Планшет)

public:
    // Конструктор
    Menu(Deque<Computer*>& computers);

    // Метод для отображения меню выбора типа устройства
    void show_device_type_menu();

    // Метод для выбора типа устройства
    int selectDeviceType();

    // Метод для отображения главного меню
    void show_main_menu();

    // Методы для пунктов меню
    void addDeviceToEnd();           // Пункт 1
    void addDeviceToFront();         // Пункт 2
    void showAllDevices();           // Пункт 3
    void showDequeStructure();       // Пункт 4
    void removeFirstDevice();        // Пункт 5
    void removeLastDevice();         // Пункт 6
    void sortDevices();              // Пункт 7 - сортировка устройств
    void searchDevices();            // Пункт 8 - поиск устройств

    // Метод для обработки выбора пользователя
    void handle_menu_choice(int choice);

    // Метод для запуска главного цикла меню
    void run();
};

#endif