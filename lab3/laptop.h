#ifndef LAPTOP_H
#define LAPTOP_H

#include "computer.h"

class Laptop : public Portable_computer {
private:
    bool has_numeric_keypad;

public:
    Laptop();
    Laptop(const std::string& brand, float screensize, int ram, int battery_life,
           bool has_numeric_keypad);

     void get_info() override;
     void set_info() override;
     void print_header() const override;
     void print_table() const override;

    bool getHasNumericKeypad() const;
    void setHasNumericKeypad(bool hasKeypad);

    friend std::istream& operator>>(std::istream& in, Laptop& computer);
    friend std::ostream& operator<<(std::ostream& out, const Laptop& computer);
};

#endif