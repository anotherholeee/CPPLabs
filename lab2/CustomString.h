#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>

class CustomString {
private:
    char* buffer;
    int sizeValue;

public:

    CustomString();
    explicit CustomString(const char* input);
    CustomString(const CustomString& source);
    ~CustomString();


    CustomString& operator=(const CustomString& source);

    char& operator[](int position);
    const char& operator[](int position) const;

    CustomString operator()(int begin, int count) const;

    bool operator>(const CustomString& other) const;
    bool operator<(const CustomString& other) const;
    bool operator==(const CustomString& other) const;

    CustomString operator+(const CustomString& other) const;
    CustomString operator+(const char* text) const;
    CustomString operator+(char symbol) const;

    friend CustomString operator+(const char* left, const CustomString& right);
    friend CustomString operator+(char left, const CustomString& right);

    CustomString& operator+=(const CustomString& other);
    CustomString& operator++();
    CustomString operator++(int);
    CustomString& operator--();
    CustomString operator--(int);

    friend std::ostream& operator<<(std::ostream& stream, const CustomString& text);
    friend std::istream& operator>>(std::istream& stream, CustomString& text);
    int getSize() const { return sizeValue; }
};

#endif