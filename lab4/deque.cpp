#include "deque.h"
#include "computer.h"
#include <iostream>

// ==================== Реализация методов шаблона Deque ====================

template<typename T>
Deque<T>::Deque() : front(nullptr), back(nullptr), deque_size(0) {}

template<typename T>
Deque<T>::~Deque() {
    clear();
}

template<typename T>
Deque<T>::Deque(const Deque& other) : front(nullptr), back(nullptr), deque_size(0) {
    Node* current = other.front;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    if (this != &other) {
        clear();
        Node* current = other.front;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Реализация основных методов дека
template<typename T>
void Deque<T>::pushFront(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        front = back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    deque_size++;
}

template<typename T>
void Deque<T>::pushBack(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        front = back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    deque_size++;
}

template<typename T>
void Deque<T>::popFront() {
    if (empty()) {
        std::cout << "Дек пуст!" << std::endl;
        return;
    }
    
    Node* temp = front;
    if (front == back) {
        front = back = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    
    delete temp;
    deque_size--;
}

template<typename T>
void Deque<T>::popBack() {
    if (empty()) {
        std::cout << "Дек пуст!" << std::endl;
        return;
    }
    
    Node* temp = back;
    if (front == back) {
        front = back = nullptr;
    } else {
        back = back->prev;
        back->next = nullptr;
    }
    
    delete temp;
    deque_size--;
}

template<typename T>
T& Deque<T>::getFront() {
    return front->data;
}

template<typename T>
T& Deque<T>::getBack() {
    return back->data;
}

template<typename T>
const T& Deque<T>::getFront() const {
    return front->data;
}

template<typename T>
const T& Deque<T>::getBack() const {
    return back->data;
}

template<typename T>
bool Deque<T>::empty() const {
    return deque_size == 0;
}

template<typename T>
size_t Deque<T>::size() const {
    return deque_size;
}

template<typename T>
void Deque<T>::clear() {
    while (!empty()) {
        popFront();
    }
}

// Реализация метода display()
template<typename T>
void Deque<T>::display() const {
    if (empty()) {
        std::cout << "Дек пуст" << std::endl;
        return;
    }
    
    Node* current = front;
    std::cout << "Дек: ";
    int index = 1;
    while (current != nullptr) {
        std::cout << "[" << index << "] " << current->data;
        if (current->next != nullptr) std::cout << " <-> ";
        current = current->next;
        index++;
    }
    std::cout << " | Размер: " << deque_size << std::endl;
}

// Реализация метода getAt
template<typename T>
T& Deque<T>::getAt(size_t index) {
    Node* current = front;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
const T& Deque<T>::getAt(size_t index) const {
    Node* current = front;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Реализация метода find
template<typename T>
int Deque<T>::find(const T& value) const {
    Node* current = front;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}


// Явное инстанцирование для Computer*
template class Deque<Computer*>;
