#include "monoblock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Monoblock::Monoblock() : Static_computer(), has_touchscreen(false) {}

Monoblock::Monoblock(const std::string& brand, float screensize, int ram, int power_supply, bool has_touchscreen)
    : Static_computer(brand, screensize, ram, power_supply), has_touchscreen(has_touchscreen) {}

bool Monoblock::getHasTouchscreen() const { return has_touchscreen; }
void Monoblock::setHasTouchscreen(bool hasTouch) { has_touchscreen = hasTouch; }

std::istream& operator>>(std::istream& in, Monoblock& computer) {
    in >> static_cast<Static_computer&>(computer);
    std::cout << "Есть сенсорный экран? (1 - да, 0 - нет): ";
    int hasTouch;
    in >> hasTouch;
    computer.has_touchscreen = (hasTouch == 1);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Monoblock& computer) {
    out << static_cast<const Computer&>(computer);
    
    std::string extra_param = "Нет";
    if (computer.getHasTouchscreen()) {
        extra_param = "Есть (сенсор)";
    }
    
    out << std::setw(12) << std::left << "Моноблок" << " | "
        << std::setw(14) << std::left << (std::to_string(computer.getPowerSupply()) + " Вт") << " | "
        << std::setw(17) << std::left << extra_param << " |" << std::endl;
    return out;
}

void Monoblock::print_header() const {
    Static_computer::print_header();
}

void Monoblock::print_table() const {
    std::cout << *this;
}

void Monoblock::set_info() {
    std::cin >> *this;
}

std::string Monoblock::getTypeName() const {
    return "Моноблок";
}