#include "monoblock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Monoblock::Monoblock() : Static_computer(), has_touchscreen(false) {}

Monoblock::Monoblock(const std::string& brand, float screensize, int ram, int power_supply,
                     bool has_touchscreen)
    : Static_computer(brand, screensize, ram, power_supply),
      has_touchscreen(has_touchscreen) {}

bool Monoblock::getHasTouchscreen() const { return has_touchscreen; }
void Monoblock::setHasTouchscreen(bool hasTouch) { has_touchscreen = hasTouch; }

std::istream& operator>>(std::istream& in, Monoblock& computer) {
    in >> static_cast<Static_computer&>(computer);

    cout << "Есть сенсорный экран? (1 - да, 0 - нет): ";
    int hasTouch;
    in >> hasTouch;
    computer.has_touchscreen = (hasTouch == 1);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Monoblock& computer) {
    out << std::setw(20) << std::left << computer.getBrand() << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.getScreensize() << " | "
        << std::setw(6) << std::right << computer.getRam() << " | "
        << std::setw(12) << std::left << "Моноблок"
        << " | " << std::setw(14) << std::left << (std::to_string(computer.getPowerSupply()) + " Вт")
        << " | " << std::setw(10) << std::left << (computer.has_touchscreen ? "Есть" : "Нет")
        << " |" << std::endl;
    return out;
}

void Monoblock::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Блок питания   | Сенсорный  |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+------------+" << std::endl;
}