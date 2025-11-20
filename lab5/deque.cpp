#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "deque.h"
#include <iostream>

// ==================== Реализация Deque ====================

template<typename T>
Deque<T>::Deque() : front(nullptr), back(nullptr), currentSize(0) {}

template<typename T>
Deque<T>::~Deque() {
    while (!empty()) {
        popFront();
    }
}

template<typename T>
Deque<T>::Deque(const Deque& other) : front(nullptr), back(nullptr), currentSize(0) {
    Node<T>* current = other.front;
    while (current != nullptr) {
        pushBack(current->data);
        current = current->next;
    }
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    if (this != &other) {
        while (!empty()) {
            popFront();
        }

        Node<T>* current = other.front;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void Deque<T>::pushFront(const T& value) {
    auto* newNode = new Node<T>(value);

    if (empty()) {
        front = back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    currentSize++;
}

template<typename T>
void Deque<T>::pushBack(const T& value) {
    auto* newNode = new Node<T>(value);

    if (empty()) {
        front = back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    currentSize++;
}

template<typename T>
void Deque<T>::popFront() {
    if (empty()) {
        throw std::runtime_error("Дек пуст");
    }

    Node<T>* temp = front;
    front = front->next;

    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        back = nullptr;
    }

    delete temp;
    currentSize--;
}

template<typename T>
void Deque<T>::popBack() {
    if (empty()) {
        throw std::runtime_error("Дек пуст");
    }

    Node<T>* temp = back;
    back = back->prev;

    if (back != nullptr) {
        back->next = nullptr;
    } else {
        front = nullptr;
    }

    delete temp;
    currentSize--;
}

template<typename T>
T& Deque<T>::getFront() {
    if (empty()) throw std::runtime_error("Дек пуст");
    return front->data;
}

template<typename T>
T& Deque<T>::getBack() {
    if (empty()) throw std::runtime_error("Дек пуст");
    return back->data;
}

template<typename T>
const T& Deque<T>::getFront() const {
    if (empty()) throw std::runtime_error("Дек пуст");
    return front->data;
}

template<typename T>
const T& Deque<T>::getBack() const {
    if (empty()) throw std::runtime_error("Дек пуст");
    return back->data;
}

template<typename T>
bool Deque<T>::empty() const { return front == nullptr; }

template<typename T>
size_t Deque<T>::getSize() const { return currentSize; }

template<typename T>
void Deque<T>::display() const {
    Node<T>* current = front;
    std::cout << "Дек (размер: " << currentSize << "): ";
    std::cout << "front → ";
    while (current != nullptr) {
        if constexpr (std::is_pointer_v<T>) {
            if (current->data != nullptr) {
                auto* comp = static_cast<Computer*>(current->data);
                std::cout << "[" << comp->getType() << "]";
            } else {
                std::cout << "[null]";
            }
        } else {
            std::cout << current->data;
        }

        if (current->next != nullptr) {
            std::cout << " ↔ ";
        } else {
            std::cout << " ← back";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
bool Deque<T>::contains(const T& value) const {
    Node<T>* current = front;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool Deque<T>::remove(const T& value) {
    Node<T>* current = front;

    while (current != nullptr) {
        if (current->data == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                front = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                back = current->prev;
            }

            delete current;
            currentSize--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
Deque<T> Deque<T>::find(const T& value) const {
    Deque<T> results;
    Node<T>* current = front;

    while (current != nullptr) {
        if (current->data == value) {
            results.pushBack(current->data);
        }
        current = current->next;
    }
    return results;
}

template<typename T>
void Deque<T>::sort() {
    if (this->isEmpty() || this->front->next == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = this->front;
        while (current->next != nullptr) {
            if (*(current->next->data) < *(current->data)) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template<typename T>
size_t Deque<T>::size() const { return getSize(); }

template<typename T>
bool Deque<T>::isEmpty() const { return empty(); }

template<typename T>
T& Deque<T>::peekFirst() { return getFront(); }

template<typename T>
T& Deque<T>::peekLast() { return getBack(); }

#endif // DEQUE_CPP