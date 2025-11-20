#include <iostream>
#include "CustomString.h"
#include <windows.h>

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Создаем две строки
    CustomString firstString, secondString;

    // Ввод первых двух строк
    std::cout << "Введите первую строку: ";
    std::cin >> firstString;
    std::cout << "Введите вторую строку: ";
    std::cin >> secondString;

    // Вывод введенных строк
    std::cout << "\nПервая строка: " << firstString << std::endl;
    std::cout << "Вторая строка: " << secondString << std::endl;

    // Сравнение строк по длине через тернарные операторы
    std::cout << "\nСравнение строк:" << std::endl;
    (firstString > secondString) ? std::cout << "Первая строка длиннее." << std::endl :
    (firstString < secondString) ? std::cout << "Вторая строка длиннее." << std::endl :
    std::cout << "Строки равны по длине." << std::endl;

    // Демонстрация всех перегрузок в одной строке через тернарные операторы
    std::cout << "\nДемонстрация перегрузок операторов:" << std::endl;

    // Объект + Объект, Объект + Строка, Строка + Объект через тернарные операторы
    CustomString result1 = (firstString.getSize() > 2) ? firstString + secondString : secondString + firstString;
    CustomString result2 = (secondString.getSize() > 3) ? firstString + "_appended" : "_prefix_" + firstString;
    CustomString result3 = (firstString[0] == 'A') ? 'X' + firstString : firstString + 'Z';

    std::cout << "result1: " << result1 << std::endl;
    std::cout << "result2: " << result2 << std::endl;
    std::cout << "result3: " << result3 << std::endl;

    // Инкремент/декремент через тернарные операторы
    std::cout << "\nИнкремент/декремент:" << std::endl;
    CustomString testString("TEST");
    (testString.getSize() > 2) ? ++testString : testString++;
    std::cout << "После условного инкремента: " << testString << std::endl;

    (testString.getSize() > 4) ? --testString : testString--;
    std::cout << "После условного декремента: " << testString << std::endl;

    // Сложение строк
    std::cout << "\nКонкатенация строк:" << std::endl;
    CustomString thirdString = firstString + secondString;
    std::cout << "thirdString = " << thirdString << std::endl;

    // Создание строки по умолчанию
    std::cout << "\nСоздание строки по умолчанию (TEST):" << std::endl;
    CustomString defaultString("TEST");
    std::cout << defaultString << std::endl;

    // Вычисление выражения с подстроками и отдельными символами
    std::cout << "\nВычисление выражения: result = defaultString(1,4) + thirdString[1] + firstString[0]" << std::endl;
    CustomString finalResult = defaultString(1, 4) + thirdString[1] + firstString[0];
    std::cout << "finalResult = " << finalResult << std::endl;

    // Присвоение одной строки другой
    std::cout << "\nПрисвоение firstString = defaultString:" << std::endl;
    firstString = defaultString;
    std::cout << firstString << std::endl;

    // Дополнительные проверки с тернарными операторами
    std::cout << "\nДополнительные проверки:" << std::endl;
    CustomString check = (firstString == secondString) ?
                        CustomString("Строки равны") :
                        (firstString > secondString) ?
                        CustomString("Первая больше") :
                        CustomString("Вторая больше");
    std::cout << "Результат сравнения: " << check << std::endl;

    return 0;
}