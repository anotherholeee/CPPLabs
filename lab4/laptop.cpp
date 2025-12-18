#include "laptop.h"
#include <iostream>
#include <iomanip>

using namespace std;

Laptop::Laptop() : Portable_computer(), has_numeric_keypad(true) {}

Laptop::Laptop(const std::string& brand, float screensize, int ram, int battery_life, bool has_numeric_keypad)
    : Portable_computer(brand, screensize, ram, battery_life), has_numeric_keypad(has_numeric_keypad) {}

bool Laptop::getHasNumericKeypad() const { return has_numeric_keypad; }
void Laptop::setHasNumericKeypad(bool hasKeypad) { has_numeric_keypad = hasKeypad; }

std::istream& operator>>(std::istream& in, Laptop& computer) {
    in >> static_cast<Portable_computer&>(computer);
    std::cout << "Есть цифровая клавиатура (numpad)? (1 - да, 0 - нет): ";
    int hasKeypad;
    in >> hasKeypad;
    computer.has_numeric_keypad = (hasKeypad == 1);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Laptop& computer) {
    out << static_cast<const Portable_computer&>(computer);
    
    std::string extra_param = "Нет";
    if (computer.getHasNumericKeypad()) {
        extra_param = "Есть (numpad)";
    }
    
    out << std::setw(15) << std::left << extra_param << " |" << std::endl;
    return out;
}

void Laptop::print_header() const {
    Portable_computer::print_header();
}

void Laptop::print_table() const {
    std::cout << *this;
}

void Laptop::set_info() {
    std::cin >> *this;
}

std::string Laptop::getTypeName() const {
    return "Ноутбук";
}