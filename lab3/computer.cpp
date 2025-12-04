#include "computer.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

// ==================== Computer ====================

Computer::Computer() : screensize(0.0f), ram(0) {
    strcpy(brand, "");
}

Computer::Computer(const std::string& brand, float screensize, int ram)
    : screensize(screensize), ram(ram) {
    setBrand(brand);
}

std::string Computer::getBrand() const { return std::string{brand}; }
float Computer::getScreensize() const { return screensize; }
int Computer::getRam() const { return ram; }

void Computer::setBrand(const std::string& newBrand) {
    if (newBrand.length() >= BRAND_LENGTH) {
        strncpy(brand, newBrand.c_str(), BRAND_LENGTH - 1);
        brand[BRAND_LENGTH - 1] = '\0';
    } else {
        strcpy(brand, newBrand.c_str());
    }
}

void Computer::setScreensize(float newScreensize) { screensize = newScreensize; }
void Computer::setRam(int newRam) { ram = newRam; }

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        strcpy(brand, other.brand);
        screensize = other.screensize;
        ram = other.ram;
    }
    return *this;
}

// Перегрузка ввода/вывода через friend функции
std::istream& operator>>(std::istream& in, Computer& computer) {
    std::string tempBrand;
    std::cout << "Введите бренд: ";
    in >> tempBrand;
    computer.setBrand(tempBrand);

    std::cout << "Введите диагональ экрана: ";
    in >> computer.screensize;

    std::cout << "Введите объём оперативной памяти: ";
    in >> computer.ram;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Computer& computer) {
    out << std::setw(20) << std::left << computer.brand << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.screensize << " | "
        << std::setw(6) << std::right << computer.ram << " | "
        << std::setw(12) << std::left << "Базовый"
        << " |" << std::endl;
    return out;
}

// Виртуальные методы для таблицы
void Computer::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
}

void Computer::display_table_footer() const {
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
}

void Computer::get_info() {
    std::cout << *this;
}

void Computer::set_info() {
    std::cin >> *this;
}

// ==================== Static_computer ====================

Static_computer::Static_computer() : Computer(), power_supply(0) {}

Static_computer::Static_computer(const std::string& brand, float screensize, int ram, int power_supply)
    : Computer(brand, screensize, ram), power_supply(power_supply) {}

int Static_computer::getPowerSupply() const { return power_supply; }
void Static_computer::setPowerSupply(int newPowerSupply) { power_supply = newPowerSupply; }

Static_computer& Static_computer::operator=(const Static_computer& other) {
    if (this != &other) {
        Computer::operator=(other);
        power_supply = other.power_supply;
    }
    return *this;
}

// Перегрузка ввода/вывода для Static_computer
std::istream& operator>>(std::istream& in, Static_computer& computer) {
    in >> static_cast<Computer&>(computer);
    std::cout << "Введите мощность блока питания: ";
    in >> computer.power_supply;
    return in;
}

// Перегрузка вывода для Static_computer в табличном формате
std::ostream& operator<<(std::ostream& out, const Static_computer& computer) {
    out << std::setw(20) << std::left << computer.getBrand() << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.getScreensize() << " | "
        << std::setw(6) << std::right << computer.getRam() << " | "
        << std::setw(12) << std::left << "Стационарный"
        << " | " << std::setw(14) << std::left << (std::to_string(computer.power_supply) + " Вт")
        << " |" << std::endl;
    return out;
}

void Static_computer::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Блок питания   |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

void Static_computer::display_table_footer() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

// ==================== Portable_computer ====================

Portable_computer::Portable_computer() : Computer(), battery_life(0) {}

Portable_computer::Portable_computer(const std::string& brand, float screensize, int ram, int battery_life)
    : Computer(brand, screensize, ram), battery_life(battery_life) {}

int Portable_computer::getBatteryLife() const { return battery_life; }
void Portable_computer::setBatteryLife(int newBatteryLife) { battery_life = newBatteryLife; }

Portable_computer& Portable_computer::operator=(const Portable_computer& other) {
    if (this != &other) {
        Computer::operator=(other);
        battery_life = other.battery_life;
    }
    return *this;
}

// Перегрузка ввода/вывода для Portable_computer
std::istream& operator>>(std::istream& in, Portable_computer& computer) {
    in >> static_cast<Computer&>(computer);
    std::cout << "Введите время автономной работы (в часах): ";
    in >> computer.battery_life;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Portable_computer& computer) {
    out << std::setw(20) << std::left << computer.getBrand() << " | "
        << std::setw(8) << std::right << std::fixed << std::setprecision(1) << computer.getScreensize() << " | "
        << std::setw(6) << std::right << computer.getRam() << " | "
        << std::setw(12) << std::left << "Портативный"
        << " | " << std::setw(14) << std::left << (std::to_string(computer.battery_life) + " ч")
        << " |" << std::endl;
    return out;
}

void Portable_computer::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Батарея        |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

void Portable_computer::display_table_footer() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

// ==================== Вспомогательные функции ====================

void display_all_computers_table(Computer* computers[], int count) {
    if (count == 0) {
        std::cout << "Нет компьютеров для отображения." << std::endl;
        return;
    }

    std::cout << "\nТАБЛИЦА КОМПЬЮТЕРОВ" << std::endl;

    // Выводим шапку таблицы
    computers[0]->display_table_header();

    for (int i = 0; i < count; i++) {
        if (computers[i] != nullptr) {
            // Используем перегруженный operator<< для вывода в табличном формате
            std::cout << "| " << std::setw(2) << std::right << (i + 1) << " | ";
            std::cout << *computers[i]; // Это вызовет перегруженный operator<<
        }
    }

    computers[0]->display_table_footer();
    std::cout << "Всего устройств: " << count << std::endl << std::endl;
}