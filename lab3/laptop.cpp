#include "laptop.h"
#include <iostream>
#include <iomanip>

using namespace std;

Laptop::Laptop() : Portable_computer(), has_numeric_keypad(true) {}

Laptop::Laptop(const std::string& brand, float screensize, int ram, int battery_life,
               bool has_numeric_keypad)
    : Portable_computer(brand, screensize, ram, battery_life),
      has_numeric_keypad(has_numeric_keypad) {}

bool Laptop::getHasNumericKeypad() const { return has_numeric_keypad; }
void Laptop::setHasNumericKeypad(bool hasKeypad) { has_numeric_keypad = hasKeypad; }

std::istream& operator>>(std::istream& in, Laptop& computer) {
    in >> static_cast<Portable_computer&>(computer);

    cout << "Есть цифровая клавиатура (numpad)? (1 - да, 0 - нет): ";
    int hasKeypad;
    in >> hasKeypad;
    computer.has_numeric_keypad = (hasKeypad == 1);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Laptop& computer) {
    out << std::setw(20) << std::left << computer.getBrand() << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.getScreensize() << " | "
        << std::setw(6) << std::right << computer.getRam() << " | "
        << std::setw(12) << std::left << "Ноутбук"
        << " | " << std::setw(14) << std::left << (std::to_string(computer.getBatteryLife()) + " ч")
        << " | " << std::setw(10) << std::left << (computer.has_numeric_keypad ? "Есть" : "Нет")
        << " |" << std::endl;
    return out;
}

void Laptop::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Батарея        | Цифр. клав.|" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
}