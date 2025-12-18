#ifndef LAPTOP_H
#define LAPTOP_H

#include "computer.h"

class Laptop : public Portable_computer {
private:
    bool has_numeric_keypad;

public:
    Laptop();
    Laptop(const std::string& brand, float screensize, int ram, int battery_life, bool has_numeric_keypad);

    bool getHasNumericKeypad() const;
    void setHasNumericKeypad(bool hasKeypad);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Laptop& computer);
    friend std::ostream& operator<<(std::ostream& out, const Laptop& computer);

    void print_header() const override;
    void print_table() const override;
    void set_info() override;
    std::string getTypeName() const override;
};

#endif

