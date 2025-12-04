#include "tablet.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tablet::Tablet() : Portable_computer(), has_stylus(false) {}

Tablet::Tablet(const std::string& brand, float screensize, int ram, int battery_life,
               bool has_stylus)
    : Portable_computer(brand, screensize, ram, battery_life),
      has_stylus(has_stylus) {}

void Tablet::set_info() {
    std::cin >> *this;
}

void Tablet::get_info() {
    std::cout << *this;
}

bool Tablet::getHasStylus() const { return has_stylus; }
void Tablet::setHasStylus(bool stylus) { has_stylus = stylus; }

std::istream& operator>>(std::istream& in, Tablet& computer) {
    in >> static_cast<Portable_computer&>(computer);

    cout << "Поддержка стилуса? (1 - да, 0 - нет): ";
    int hasStylus;
    in >> hasStylus;
    computer.has_stylus = (hasStylus == 1);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Tablet& computer) {

    out << static_cast<const Portable_computer&>(computer);

    std::string extra_param = "Нет";
    if (computer.getHasStylus()) {
        extra_param = "Есть (стилус)";
    }

    out << std::setw(17) << std::left << extra_param << " |" << std::endl;
    return out;
}

void Tablet::print_header() const {
    Portable_computer::print_header();
}

void Tablet::print_table() const {
    std::cout << *this;
}