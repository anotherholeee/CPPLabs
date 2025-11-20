#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "deque.h"

class Computer {
protected:
    static const int BRAND_LENGTH = 20;
    char brand[BRAND_LENGTH];
    float screensize;
    int ram;

public:
    Computer();
    Computer(const std::string& brand, float screensize, int ram);
    virtual ~Computer() = default;

    std::string getBrand() const;
    float getScreensize() const;
    int getRam() const;

    void setBrand(const std::string& newBrand);
    void setScreensize(float newScreensize);
    void setRam(int newRam);

    Computer& operator=(const Computer& other);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

    virtual void display_table_header() const;
    virtual void display_table_footer() const;
    virtual void display_table_row(int index) const;

    virtual void get_info();
    virtual void set_info();
};

class Static_computer : public Computer {
protected:
    int power_supply;

public:
    Static_computer();
    Static_computer(const std::string& brand, float screensize, int ram, int power_supply);
    ~Static_computer() override;

    int getPowerSupply() const;
    void setPowerSupply(int newPowerSupply);

    Static_computer& operator=(const Static_computer& other);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Static_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Static_computer& computer);

    void display_table_header() const override;
    void display_table_footer() const override;
    void display_table_row(int index) const override;
};

class Monoblock : public Static_computer {
public:
    Monoblock();
    Monoblock(const std::string& brand, float screensize, int ram, int power_supply);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Monoblock& computer);
    friend std::ostream& operator<<(std::ostream& out, const Monoblock& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;
};

class Portable_computer : public Computer {
protected:
    int battery_life;

public:
    Portable_computer();
    Portable_computer(const std::string& brand, float screensize, int ram, int battery_life);

    int getBatteryLife() const;
    void setBatteryLife(int newBatteryLife);

    Portable_computer& operator=(const Portable_computer& other);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Portable_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Portable_computer& computer);

    void display_table_header() const override;
    void display_table_footer() const override;
    void display_table_row(int index) const override;
};

class Tablet : public Portable_computer {
public:
    Tablet();
    Tablet(const std::string& brand, float screensize, int ram, int battery_life);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Tablet& computer);
    friend std::ostream& operator<<(std::ostream& out, const Tablet& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;
};

class Laptop : public Portable_computer {
public:
    Laptop();
    Laptop(const std::string& brand, float screensize, int ram, int battery_life);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Laptop& computer);
    friend std::ostream& operator<<(std::ostream& out, const Laptop& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;
};

// Функции для работы с деком компьютеров
void display_all_computers_table(Deque<Computer*>& computers);

#endif