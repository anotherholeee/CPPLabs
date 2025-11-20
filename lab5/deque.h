#ifndef DEQUE_H
#define DEQUE_H

#include "computer.h"


template<typename T>
class Deque {
private:
    template<typename U>
    struct Node {
        U data;
        Node<U>* prev;
        Node<U>* next;

        explicit Node(const U& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node<T>* front;
    Node<T>* back;
    size_t currentSize;

public:
    // Конструкторы и деструктор
    Deque();
    ~Deque();
    Deque(const Deque& other);
    Deque& operator=(const Deque& other);

    // Основные операции
    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront();
    void popBack();

    // Доступ к элементам
    T& getFront();
    T& getBack();
    const T& getFront() const;
    const T& getBack() const;

    // Информация
    bool empty() const;
    size_t getSize() const;

    // Вывод
    void display() const;

    // Поиск и удаление
    bool contains(const T& value) const;
    bool remove(const T& value);

    // Дополнительные операции
    Deque<T> find(const T& value) const;
    void sort();

    // Для совместимости с существующим кодом
    size_t size() const;
    bool isEmpty() const;
    T& peekFirst();
    T& peekLast();
};

// Реализация шаблонного класса
#include "deque.cpp"

#endif // DEQUE_H