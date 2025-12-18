#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

// Forward declaration для Computer
class Computer;

// ШАБЛОННЫЙ КЛАСС ДЕКА
template<typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* front;
    Node* back;
    size_t deque_size;

public:
    // Конструкторы
    Deque();
    
    // Деструктор
    ~Deque();
    
    // Копирующий конструктор
    Deque(const Deque& other);
    
    // Оператор присваивания
    Deque& operator=(const Deque& other);
    
    // Основные методы дека
    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront();
    void popBack();
    
    T& getFront();
    T& getBack();
    const T& getFront() const;
    const T& getBack() const;
    
    bool empty() const;
    size_t size() const;
    
    void clear();
    
    // Метод для отображения дека
    void display() const;
    
    // Метод для получения элемента по индексу
    T& getAt(size_t index);
    const T& getAt(size_t index) const;
    
    // Метод поиска элемента
    // Возвращает индекс элемента или -1, если не найден
    int find(const T& value) const;
};

#endif