#include "CharArray.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== Демонстрация работы класса CharArray ===" << std::endl;

    // Создание двух массивов фиксированного размера
    CharArray arr1(100);
    CharArray arr2(100);

    // Ввод данных для первого массива
    std::cout << "Введите первую строку: ";
    arr1.input();

    // Ввод данных для второго массива
    std::cout << "Введите вторую строку: ";
    arr2.input();

    // Вывод введенных массивов
    std::cout << "Первая строка: ";
    arr1.print();
    std::cout << std::endl;

    std::cout << "Вторая строка: ";
    arr2.print();
    std::cout << std::endl;

    // Создание копии первой строки с помощью конструктора копирования
    CharArray arr1_copy(arr1);
    std::cout << "Копия первой строки: ";
    arr1_copy.print();
    std::cout << std::endl;

    // Создание копии второй строки с помощью конструктора копирования
    CharArray arr2_copy = arr2;
    std::cout << "Копия второй строки: ";
    arr2_copy.print();
    std::cout << std::endl;

    // Сложение массивов
    CharArray result = arr1.concatenate(arr2);
    std::cout << "Результат сложения: ";
    result.print();
    std::cout << std::endl;

    return 0;
}