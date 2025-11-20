#include "CharArray.h"
#include <iostream>
#include <cstring>
#include <limits>

// Конструктор без параметров
CharArray::CharArray() {
    data = nullptr;
    size = 0;
}

// Конструктор с параметрами (размер массива) создание пустого буфера
CharArray::CharArray(size_t n) {
    size = n;                      //размер
    data = new char[size + 1];
    memset(data, 0, size + 1); //для заполнения блока памяти заданным значением.
}

// Конструктор с параметрами (строка)
CharArray::CharArray(const char* str) {
    if (str) {                      // Если строка не nullptr
        size = strlen(str);         // Определяем длину существующей строки
        data = new char[size + 1];  // Выделяем память под копию
        strcpy(data, str);          // Копируем содержимое строки
    } else {
        size = 0;                   // Для nullptr создаем пустой объект
        data = nullptr;
    }
}

// Конструктор копирования
CharArray::CharArray(const CharArray& other) {
    size = other.size;
    if (other.data) {
        data = new char[size + 1];
        strcpy(data, other.data);
    } else {
        data = nullptr;
    }
}

// Деструктор
CharArray::~CharArray() {
    delete[] data;
}

// Метод ввода данных в массив
void CharArray::input() {
    if (data == nullptr) {
        std::cout << "Массив не инициализирован." << std::endl;
        return;
    }

    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.getline(data, size + 1);
    data[size] = '\0';
    size = strlen(data);
}

// Метод вывода на экран
void CharArray::print() const {
    if (data) {
        std::cout << "\"" << data << "\"";
    } else {
        std::cout << "null";
    }
}

// Метод cложения
CharArray CharArray::concatenate(const CharArray& other) const {
    if (!data && !other.data) return {};
    if (!data) return CharArray(other);
    if (!other.data) return CharArray(*this);

    CharArray result;
    result.size = size + other.size;
    result.data = new char[result.size + 1];
    strcpy(result.data, data);
    strcat(result.data, other.data);

    return result;
}

// Геттеры
const char* CharArray::getData() const { return data; }
size_t CharArray::getSize() const { return size; }