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
    std::cin >> *this;  // Вызывает operator>> для Tablet
}

void Tablet::get_info() {
    std::cout << *this;  // Вызывает operator<< для Tablet
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
    out << std::setw(20) << std::left << computer.getBrand() << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.getScreensize() << " | "
        << std::setw(6) << std::right << computer.getRam() << " | "
        << std::setw(12) << std::left << "Планшет"
        << " | " << std::setw(14) << std::left << (std::to_string(computer.getBatteryLife()) + " ч")
        << " | " << std::setw(10) << std::left << (computer.getHasStylus() ? "Есть" : "Нет")
        << " |" << std::endl;
    return out;
}

void Tablet::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Батарея        | Стилус     |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
}