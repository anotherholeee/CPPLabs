#include "computer.h"

// ==================== Computer ====================

Computer::Computer() : screensize(0.0f), ram(0) {}

Computer::Computer(std::string brand, float screensize, int ram)
    : brand(std::move(brand)), screensize(screensize), ram(ram) {}

std::string Computer::getBrand() const { return brand; }
float Computer::getScreensize() const { return screensize; }
int Computer::getRam() const { return ram; }

void Computer::setBrand(const std::string& newBrand) { brand = newBrand; }
void Computer::setScreensize(float newScreensize) { screensize = newScreensize; }
void Computer::setRam(int newRam) { ram = newRam; }

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        brand = other.brand;
        screensize = other.screensize;
        ram = other.ram;
    }
    return *this;
}

bool Computer::operator==(const Computer& other) const {
    return brand == other.brand &&
           screensize == other.screensize &&
           ram == other.ram;
}

bool Computer::operator<(const Computer& other) const {
    return brand < other.brand;
}

std::istream& operator>>(std::istream& in, Computer& computer) {
    std::cout << "Введите бренд: ";
    in >> computer.brand;
    std::cout << "Введите диагональ экрана: ";
    in >> computer.screensize;
    std::cout << "Введите объём оперативной памяти: ";
    in >> computer.ram;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Computer& computer) {
    out << "Бренд: " << computer.brand << std::endl
        << "Диагональ экрана: " << computer.screensize << std::endl
        << "Объём оперативной памяти: " << computer.ram << std::endl;
    return out;
}

void Computer::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
}

void Computer::display_table_footer() const {
    std::cout << "+----+----------------------+----------+--------+--------------+" << std::endl;
}

void Computer::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(15) << std::left << brand.substr(0, 15)
         << " | " << std::setw(6) << std::right << std::fixed << std::setprecision(1) << screensize
         << " | " << std::setw(4) << std::right << ram
         << " | " << std::setw(8) << std::left << "Basic"
         << " |" << std::endl;
}

void Computer::get_info() { std::cout << *this; }
void Computer::set_info() { std::cin >> *this; }

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

bool Static_computer::operator==(const Static_computer& other) const {
    return Computer::operator==(other) && power_supply == other.power_supply;
}

bool Static_computer::operator<(const Static_computer& other) const {
    return Computer::operator<(other);
}

std::istream& operator>>(std::istream& in, Static_computer& computer) {
    in >> static_cast<Computer&>(computer);
    std::cout << "Введите мощность блока питания: ";
    in >> computer.power_supply;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Static_computer& computer) {
    out << static_cast<const Computer&>(computer);
    out << "Блок питания: " << computer.power_supply << " Вт" << std::endl;
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

void Static_computer::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand().substr(0, 20)
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Стационарный"
         << " | " << std::setw(14) << std::left << (std::to_string(power_supply) + " Вт")
         << " |" << std::endl;
}

void Static_computer::set_info() {
    Computer::set_info();
    std::cout << "Введите мощность блока питания: ";
    std::cin >> power_supply;
}

std::string Static_computer::getType() const { return "Стационарный"; }

// ==================== Monoblock ====================

Monoblock::Monoblock() : Static_computer() {}

Monoblock::Monoblock(const std::string& brand, float screensize, int ram, int power_supply)
    : Static_computer(brand, screensize, ram, power_supply) {}

std::istream& operator>>(std::istream& in, Monoblock& computer) {
    in >> static_cast<Static_computer&>(computer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Monoblock& computer) {
    out << static_cast<const Static_computer&>(computer);
    return out;
}

void Monoblock::display_table_header() const { Static_computer::display_table_header(); }

void Monoblock::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand().substr(0, 20)
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Monoblock"
         << " | " << std::setw(14) << std::left << (std::to_string(getPowerSupply()) + " Вт")
         << " |" << std::endl;
}

void Monoblock::set_info() { Static_computer::set_info(); }
std::string Monoblock::getType() const { return "Monoblock"; }

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

bool Portable_computer::operator==(const Portable_computer& other) const {
    return Computer::operator==(other) && battery_life == other.battery_life;
}

bool Portable_computer::operator<(const Portable_computer& other) const {
    return Computer::operator<(other);
}

std::istream& operator>>(std::istream& in, Portable_computer& computer) {
    in >> static_cast<Computer&>(computer);
    std::cout << "Введите время автономной работы: ";
    in >> computer.battery_life;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Portable_computer& computer) {
    out << static_cast<const Computer&>(computer);
    out << "Время автономной работы: " << computer.battery_life << " ч" << std::endl;
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

void Portable_computer::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand().substr(0, 20)
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Портативный"
         << " | " << std::setw(14) << std::left << (std::to_string(battery_life) + " ч")
         << " |" << std::endl;
}

void Portable_computer::set_info() {
    Computer::set_info();
    std::cout << "Введите время автономной работы: ";
    std::cin >> battery_life;
}

std::string Portable_computer::getType() const { return "Портативный"; }

// ==================== Tablet ====================

Tablet::Tablet() : Portable_computer() {}

Tablet::Tablet(const std::string& brand, float screensize, int ram, int battery_life)
    : Portable_computer(brand, screensize, ram, battery_life) {}

std::istream& operator>>(std::istream& in, Tablet& computer) {
    in >> static_cast<Portable_computer&>(computer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Tablet& computer) {
    out << static_cast<const Portable_computer&>(computer);
    return out;
}

void Tablet::display_table_header() const { Portable_computer::display_table_header(); }

void Tablet::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand().substr(0, 20)
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Tablet"
         << " | " << std::setw(14) << std::left << (std::to_string(getBatteryLife()) + " ч")
         << " |" << std::endl;
}

void Tablet::set_info() { Portable_computer::set_info(); }
std::string Tablet::getType() const { return "Tablet"; }

// ==================== Laptop ====================

Laptop::Laptop() : Portable_computer() {}

Laptop::Laptop(const std::string& brand, float screensize, int ram, int battery_life)
    : Portable_computer(brand, screensize, ram, battery_life) {}

std::istream& operator>>(std::istream& in, Laptop& computer) {
    in >> static_cast<Portable_computer&>(computer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Laptop& computer) {
    out << static_cast<const Portable_computer&>(computer);
    return out;
}

void Laptop::display_table_header() const { Portable_computer::display_table_header(); }

void Laptop::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand().substr(0, 20)
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Laptop"
         << " | " << std::setw(14) << std::left << (std::to_string(getBatteryLife()) + " ч")
         << " |" << std::endl;
}

void Laptop::set_info() { Portable_computer::set_info(); }
std::string Laptop::getType() const { return "Laptop"; }