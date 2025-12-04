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
    
    bool getHasStylus() const;
    void setHasStylus(bool stylus);
    
    virtual void display_table_header() const override;
    
    friend std::istream& operator>>(std::istream& in, Tablet& computer);
    friend std::ostream& operator<<(std::ostream& out, const Tablet& computer);
};

#endif