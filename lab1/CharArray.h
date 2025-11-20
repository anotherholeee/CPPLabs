#ifndef CHARARRAY_H
#define CHARARRAY_H

#include <cstddef> // для size_t

class CharArray {
private:
    char* data;
    size_t size;

public:
    // Конструкторы
    CharArray();
    explicit CharArray(size_t n);
    explicit CharArray(const char* str);
    CharArray(const CharArray& other); // Конструктор копирования

    // Деструктор
    ~CharArray();

    // Методы
    void input();
    void print() const;
    CharArray concatenate(const CharArray& other) const;

    // Геттеры
    const char* getData() const;
    size_t getSize() const;
};

#endif // CHARARRAY_H