#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

#define BRAND_LENGTH 20

class Computer {
protected:
    char brand[BRAND_LENGTH]{};
    float screensize;
    int ram;

public:
    Computer();
    Computer(const std::string& brand, float screensize, int ram);

    std::string getBrand() const;
    float getScreensize() const;
    int getRam() const;


    void setBrand(const std::string& newBrand);
    void setScreensize(float newScreensize);
    void setRam(int newRam);


    Computer& operator=(const Computer& other);


    virtual void get_info();
    virtual void set_info();
    virtual void print_table() const;
    virtual void print_header() const;


    friend std::istream& operator>>(std::istream& in, Computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

    virtual ~Computer() = default;
};


class Static_computer : public Computer {
protected:
    int power_supply;

public:
    Static_computer();
    Static_computer(const std::string& brand, float screensize, int ram, int power_supply);

    ~Static_computer() override = default;

    int getPowerSupply() const;
    void setPowerSupply(int newPowerSupply);

    Static_computer& operator=(const Static_computer& other);

    void get_info() override;
    void set_info() override;
    void print_table() const override;
    void print_header() const override;

    friend std::istream& operator>>(std::istream& in, Static_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Static_computer& computer);
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

    void get_info() override;
    void set_info() override;
    void print_table() const override;
    void print_header() const override;

    friend std::istream& operator>>(std::istream& in, Portable_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Portable_computer& computer);
};


void display_all_computers_table(Computer* computers[], int count);

#endif