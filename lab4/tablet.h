#ifndef TABLET_H
#define TABLET_H

#include "computer.h"

class Tablet : public Portable_computer {
private:
    bool has_stylus;

public:
    Tablet();
    Tablet(const std::string& brand, float screensize, int ram, int battery_life, bool has_stylus);

    bool getHasStylus() const;
    void setHasStylus(bool stylus);

    // Дружественные функции для перегрузки ввода/вывода
    friend std::istream& operator>>(std::istream& in, Tablet& computer);
    friend std::ostream& operator<<(std::ostream& out, const Tablet& computer);

    void print_header() const override;
    void print_table() const override;
    void set_info() override;
    std::string getTypeName() const override;
};

#endif

