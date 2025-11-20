#include "CustomString.h"
#include <cstring>


CustomString::CustomString() : buffer(nullptr), sizeValue(0) {
    buffer = new char[1];
    buffer[0] = '\0';
}

CustomString::CustomString(const char* input) {
    if (!input) {
        sizeValue = 0;  //проверка на нулевой указатель
        buffer = new char[1];
        buffer[0] = '\0';
    } else {
        sizeValue = static_cast<int>(std::strlen(input));
        buffer = new char[sizeValue + 1];
        std::strcpy(buffer, input);
    }
}

CustomString::CustomString(const CustomString& source) : sizeValue(source.sizeValue) {
    buffer = new char[sizeValue + 1];
    std::strcpy(buffer, source.buffer);
}


CustomString::~CustomString() {
    delete[] buffer;
}


CustomString& CustomString::operator=(const CustomString& source) {
    if (this != &source) {
        delete[] buffer;
        sizeValue = source.sizeValue;
        buffer = new char[sizeValue + 1];
        std::strcpy(buffer, source.buffer);
    }
    return *this;
}


char& CustomString::operator[](int position) {
    return buffer[position];
}

const char& CustomString::operator[](int position) const {
    return buffer[position];
}


CustomString CustomString::operator()(int begin, int count) const {
    if (begin < 0 || begin >= sizeValue || count <= 0) return CustomString("");

    if (begin + count > sizeValue) count = sizeValue - begin;

    char* tempBuffer = new char[count + 1];
    std::strncpy(tempBuffer, buffer + begin, count);
    tempBuffer[count] = '\0';
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}


bool CustomString::operator>(const CustomString& other) const {
    return sizeValue > other.sizeValue;
}

bool CustomString::operator<(const CustomString& other) const {
    return sizeValue < other.sizeValue;
}

bool CustomString::operator==(const CustomString& other) const {
    if (sizeValue != other.sizeValue) return false;
    return std::strcmp(buffer, other.buffer) == 0;
}


CustomString CustomString::operator+(const CustomString& other) const { //объект+объект
    char* tempBuffer = new char[sizeValue + other.sizeValue + 1];
    std::strcpy(tempBuffer, buffer);
    std::strcat(tempBuffer, other.buffer);
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}

CustomString CustomString::operator+(const char* text) const { //объект+строка
    int additionalLength = static_cast<int>(std::strlen(text));
    char* tempBuffer = new char[sizeValue + additionalLength + 1];
    std::strcpy(tempBuffer, buffer);
    std::strcat(tempBuffer, text);
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}

CustomString CustomString::operator+(char symbol) const { //объект+символ
    char* tempBuffer = new char[sizeValue + 2];
    std::strcpy(tempBuffer, buffer);
    tempBuffer[sizeValue] = symbol;
    tempBuffer[sizeValue + 1] = '\0';
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}

CustomString operator+(const char* left, const CustomString& right) { //строка+объект
    int leftLength = static_cast<int>(std::strlen(left));
    char* tempBuffer = new char[leftLength + right.sizeValue + 1];
    std::strcpy(tempBuffer, left);
    std::strcat(tempBuffer, right.buffer);
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}

CustomString operator+(char left, const CustomString& right) { //символ+объект
    char* tempBuffer = new char[right.sizeValue + 2];
    tempBuffer[0] = left;
    std::strcpy(tempBuffer + 1, right.buffer);
    CustomString result(tempBuffer);
    delete[] tempBuffer;
    return result;
}

CustomString& CustomString::operator+=(const CustomString& other) {
    *this = *this + other;
    return *this;
}


CustomString& CustomString::operator++() {
    for (int i = 0; i < sizeValue; i++) buffer[i]++;
    return *this;
}

CustomString CustomString::operator++(int) {
    CustomString temp(*this);
    ++(*this);
    return temp;
}

CustomString& CustomString::operator--() {
    for (int i = 0; i < sizeValue; i++) buffer[i]--;
    return *this;
}

CustomString CustomString::operator--(int) {
    CustomString temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& stream, const CustomString& text) {
    stream << text.buffer;
    return stream;
}

std::istream& operator>>(std::istream& stream, CustomString& text) {
    char inputBuffer[1024];
    stream >> inputBuffer;
    text = CustomString(inputBuffer);
    return stream;
}