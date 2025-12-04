#ifndef TABLET_H
#define TABLET_H

#include "computer.h"

class Tablet : public Portable_computer {
private:
    bool has_stylus;

public:
    Tablet();
    Tablet(const std::string& brand, float screensize, int ram, int battery_life,
           bool has_stylus);

    virtual void get_info() override;
    virtual void set_info() override;
    virtual void print_header() const override;
    virtual void print_table() const override;

    bool getHasStylus() const;
    void setHasStylus(bool stylus);

    friend std::istream& operator>>(std::istream& in, Tablet& computer);
    friend std::ostream& operator<<(std::ostream& out, const Tablet& computer);
};

#endif