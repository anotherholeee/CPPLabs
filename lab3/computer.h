#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

#define BRAND_LENGTH 20

// ==================== Базовый класс Computer ====================
class Computer {
protected:
    char brand[BRAND_LENGTH];
    float screensize;
    int ram;

public:
    Computer();
    Computer(const std::string& brand, float screensize, int ram);

    // Геттеры
    std::string getBrand() const;
    float getScreensize() const;
    int getRam() const;

    // Сеттеры
    void setBrand(const std::string& newBrand);
    void setScreensize(float newScreensize);
    void setRam(int newRam);

    // Перегрузка операторов
    Computer& operator=(const Computer& other);

    // Виртуальные методы
    virtual void get_info();
    virtual void set_info();
    virtual void print_header() const;
    virtual void print_table() const;

    // Дружественные функции ввода/вывода
    friend std::istream& operator>>(std::istream& in, Computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

    virtual ~Computer() = default;
};

// ==================== Static_computer ====================
class Static_computer : public Computer {
protected:
    int power_supply;

public:
    Static_computer();
    Static_computer(const std::string& brand, float screensize, int ram, int power_supply);
    virtual ~Static_computer() = default;

    int getPowerSupply() const;
    void setPowerSupply(int newPowerSupply);

    Static_computer& operator=(const Static_computer& other);

    virtual void get_info() override;
    virtual void set_info() override;
    virtual void print_header() const override;
    virtual void print_table() const override;

    friend std::istream& operator>>(std::istream& in, Static_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Static_computer& computer);
};

// ==================== Portable_computer ====================
class Portable_computer : public Computer {
protected:
    int battery_life;

public:
    Portable_computer();
    Portable_computer(const std::string& brand, float screensize, int ram, int battery_life);

    int getBatteryLife() const;
    void setBatteryLife(int newBatteryLife);

    Portable_computer& operator=(const Portable_computer& other);

    virtual void get_info() override;
    virtual void set_info() override;
    virtual void print_header() const override;
    virtual void print_table() const override;

    friend std::istream& operator>>(std::istream& in, Portable_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Portable_computer& computer);
};

// Вспомогательная функция
void display_all_computers_table(Computer* computers[], int count);

#endif