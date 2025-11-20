#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iomanip>
#include<limits>
#include <iostream>
#include <utility>

class Computer {
protected:
    std::string brand;
    float screensize;
    int ram;

public:
    Computer();
    Computer(std::string brand, float screensize, int ram);
    virtual ~Computer() = default;

    std::string getBrand() const;
    float getScreensize() const;
    int getRam() const;

    void setBrand(const std::string& newBrand);
    void setScreensize(float newScreensize);
    void setRam(int newRam);

    Computer& operator=(const Computer& other);
    bool operator==(const Computer& other) const;
    bool operator<(const Computer& other) const;

    friend std::istream& operator>>(std::istream& in, Computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Computer& computer);

    virtual void display_table_header() const;
    virtual void display_table_footer() const;
    virtual void display_table_row(int index) const;

    virtual void get_info();
    virtual void set_info();
    virtual std::string getType() const = 0;
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
    bool operator==(const Static_computer& other) const;
    bool operator<(const Static_computer& other) const;

    friend std::istream& operator>>(std::istream& in, Static_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Static_computer& computer);

    void display_table_header() const override;
    void display_table_footer() const override;
    void display_table_row(int index) const override;

    void set_info() override;
    std::string getType() const override;
};

class Monoblock : public Static_computer {
public:
    Monoblock();
    Monoblock(const std::string& brand, float screensize, int ram, int power_supply);

    friend std::istream& operator>>(std::istream& in, Monoblock& computer);
    friend std::ostream& operator<<(std::ostream& out, const Monoblock& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;

    void set_info() override;
    std::string getType() const override;
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
    bool operator==(const Portable_computer& other) const;
    bool operator<(const Portable_computer& other) const;

    friend std::istream& operator>>(std::istream& in, Portable_computer& computer);
    friend std::ostream& operator<<(std::ostream& out, const Portable_computer& computer);

    void display_table_header() const override;
    void display_table_footer() const override;
    void display_table_row(int index) const override;

    void set_info() override;
    std::string getType() const override;
};

class Tablet : public Portable_computer {
public:
    Tablet();
    Tablet(const std::string& brand, float screensize, int ram, int battery_life);

    friend std::istream& operator>>(std::istream& in, Tablet& computer);
    friend std::ostream& operator<<(std::ostream& out, const Tablet& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;

    void set_info() override;
    std::string getType() const override;
};

class Laptop : public Portable_computer {
public:
    Laptop();
    Laptop(const std::string& brand, float screensize, int ram, int battery_life);

    friend std::istream& operator>>(std::istream& in, Laptop& computer);
    friend std::ostream& operator<<(std::ostream& out, const Laptop& computer);

    void display_table_header() const override;
    void display_table_row(int index) const override;

    void set_info() override;
    std::string getType() const override;
};

#endif // COMPUTER_H