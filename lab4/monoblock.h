#ifndef MONOBLOCK_H
#define MONOBLOCK_H

#include "computer.h"

class Monoblock : public Static_computer {
private:
    bool has_touchscreen;

public:
    Monoblock();
    Monoblock(const std::string& brand, float screensize, int ram, int power_supply, bool has_touchscreen);

    bool getHasTouchscreen() const;
    void setHasTouchscreen(bool hasTouch);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Monoblock& computer);
    friend std::ostream& operator<<(std::ostream& out, const Monoblock& computer);

    void print_header() const override;
    void print_table() const override;
    void set_info() override;
    std::string getTypeName() const override;
};

#endif