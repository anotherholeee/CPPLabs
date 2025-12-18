#include "deque.h"
#include "computer.h"
#include <iostream>
#include <functional>

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

// Специализация метода display() для Computer*
template<>
void Deque<Computer*>::display() const {
    if (empty()) {
        std::cout << "Дек пуст" << std::endl;
        return;
    }
    
    Node* current = front;
    std::cout << "Дек: ";
    int index = 1;
    while (current != nullptr) {
        Computer* comp = current->data;
        if (comp != nullptr) {
            std::cout << "[" << index << "] " << comp->getTypeName() 
                      << " (" << comp->getBrand() << ")";
        } else {
            std::cout << "[" << index << "] nullptr";
        }
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

// Реализация метода sort (пузырьковая сортировка)
template<typename T>
void Deque<T>::sort(std::function<bool(const T&, const T&)> comp) {
    if (empty() || deque_size == 1) {
        return;
    }
    
    bool swapped;
    do {
        swapped = false;
        Node* current = front;
        
        while (current != nullptr && current->next != nullptr) {
            if (comp(current->data, current->next->data)) {
                // Меняем местами данные узлов
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Реализация метода filter
template<typename T>
Deque<T> Deque<T>::filter(std::function<bool(const T&)> predicate) const {
    Deque<T> result;
    Node* current = front;
    while (current != nullptr) {
        if (predicate(current->data)) {
            result.pushBack(current->data);
        }
        current = current->next;
    }
    return result;
}

// Явная инстанциация шаблона для Computer*
template class Deque<Computer*>;