#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>

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
    Deque() : front(nullptr), back(nullptr), deque_size(0) {}
    
    // Деструктор
    ~Deque() {
        clear();
    }
    
    // Копирующий конструктор
    Deque(const Deque& other) : front(nullptr), back(nullptr), deque_size(0) {
        Node* current = other.front;
        while (current != nullptr) {
            pushBack(current->data);
            current = current->next;
        }
    }
    
    // Оператор присваивания
    Deque& operator=(const Deque& other) {
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
    
    // Основные методы дека
    void pushFront(const T& value) {
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
    
    void pushBack(const T& value) {
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
    
    void popFront() {
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
    
    void popBack() {
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
    
    T& getFront() {
        if (empty()) {
            throw "Дек пуст!";
        }
        return front->data;
    }
    
    T& getBack() {
        if (empty()) {
            throw "Дек пуст!";
        }
        return back->data;
    }
    
    const T& getFront() const {
        if (empty()) {
            throw "Дек пуст!";
        }
        return front->data;
    }
    
    const T& getBack() const {
        if (empty()) {
            throw "Дек пуст!";
        }
        return back->data;
    }
    
    bool empty() const { return deque_size == 0; }
    size_t size() const { return deque_size; }
    
    void clear() {
        while (!empty()) {
            popFront();
        }
    }
    
    // Метод для отображения дека
    void display() const {
        if (empty()) {
            std::cout << "Дек пуст" << std::endl;
            return;
        }
        
        Node* current = front;
        std::cout << "Дек: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) std::cout << " <-> ";
            current = current->next;
        }
        std::cout << " | Размер: " << deque_size << std::endl;
    }
    
    // Итератор для прохода по деку
    class Iterator {
    private:
        Node* current;
        
    public:
        Iterator(Node* node) : current(node) {}
        
        T& operator*() { return current->data; }
        Iterator& operator++() { 
            if (current) current = current->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }
    };
    
    Iterator begin() { return Iterator(front); }
    Iterator end() { return Iterator(nullptr); }
};

#endif