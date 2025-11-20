#include "computer.h"
#include <cstring>

using namespace std;

// ==================== Computer ====================

Computer::Computer() : screensize(0.0f), ram(0) {
    strcpy(brand, "");
}

Computer::Computer(const std::string& brand, float screensize, int ram)
    : screensize(screensize), ram(ram) {
    setBrand(brand);
}

std::string Computer::getBrand() const { return std::string(brand); }
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
         << " | " << std::setw(20) << std::left << brand
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << screensize
         << " | " << std::setw(6) << std::right << ram
         << " | " << std::setw(12) << std::left << "Базовый"
         << " |" << std::endl;
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

Static_computer::~Static_computer() = default;

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

std::ostream& operator<<(std::ostream& out, const Static_computer& computer) {
    out << static_cast<const Computer&>(computer);
    out << "Блок питания: " << computer.power_supply << std::endl;
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
         << " | " << std::setw(20) << std::left << getBrand()
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Стационарный"
         << " | " << std::setw(14) << std::left << (std::to_string(power_supply) + " Вт")
         << " |" << std::endl;
}

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

void Monoblock::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Блок питания   |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

void Monoblock::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand()
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Моноблок"
         << " | " << std::setw(14) << std::left << (std::to_string(getPowerSupply()) + " Вт")
         << " |" << std::endl;
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
    std::cout << "Введите время автономной работы: ";
    in >> computer.battery_life;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Portable_computer& computer) {
    out << static_cast<const Computer&>(computer);
    out << "Время автономной работы: " << computer.battery_life << std::endl;
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
         << " | " << std::setw(20) << std::left << getBrand()
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Портативный"
         << " | " << std::setw(14) << std::left << (std::to_string(battery_life) + " ч")
         << " |" << std::endl;
}

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

void Tablet::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Батарея        |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

void Tablet::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand()
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Планшет"
         << " | " << std::setw(14) << std::left << (std::to_string(getBatteryLife()) + " ч")
         << " |" << std::endl;
}

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

void Laptop::display_table_header() const {
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
    std::cout << "| №  | Бренд               | Экран(\") | ОЗУ(ГБ)| Тип          | Батарея        |" << std::endl;
    std::cout << "+----+----------------------+----------+--------+--------------+----------------+" << std::endl;
}

void Laptop::display_table_row(int index) const {
    std::cout << "| " << std::setw(2) << std::right << index
         << " | " << std::setw(20) << std::left << getBrand()
         << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << getScreensize()
         << " | " << std::setw(6) << std::right << getRam()
         << " | " << std::setw(12) << std::left << "Ноутбук"
         << " | " << std::setw(14) << std::left << (std::to_string(getBatteryLife()) + " ч")
         << " |" << std::endl;
}

// ==================== Вспомогательные функции ====================

void display_all_computers_table(Deque<Computer*>& computers) {
    if (computers.empty()) {
        std::cout << "Нет компьютеров для отображения." << std::endl;
        return;
    }

    std::cout << "\nТАБЛИЦА КОМПЬЮТЕРОВ" << std::endl;

    computers.getFront()->display_table_header();

    int index = 1;
    for (auto it = computers.begin(); it != computers.end(); ++it) {
        if (*it != nullptr) {
            (*it)->display_table_row(index);
            index++;
        }
    }

    computers.getFront()->display_table_footer();
    std::cout << "Всего устройств: " << computers.size() << std::endl << std::endl;
}