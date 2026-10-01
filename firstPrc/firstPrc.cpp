#include <iostream>
#include <ranges>
//#include <windows.h>
//#include <locale>


enum Problems {
    first = 1,
    second,
    third,
    four,
    five,
};

namespace problems {
    int problem1() {

        int number, result{};
        std::cin >> number;

        for (; number > 0;) {
            // tbd: less aritmetic ops
            result += number % 10;
            number = number / 10;
        }
        return result;
    }

    int problem1Another() {

        std::string numberRepr;
        std::cin >> numberRepr;

        auto result = 0;
        for (auto& symbol : numberRepr)
            result += (symbol - '0');

        return result;
    }

    std::pair<int, int> problem2() {
        
        std::string numberRepr;
        std::cin >> numberRepr;

        int acc_e = 0, acc_o = 0;
        for (auto [index, symbol] : std::ranges::enumerate_view(numberRepr)) {
            auto number = symbol - '0';
            if (index % 2 == 0)
                acc_e += number;
            else
                acc_o += number;
        }
        return { acc_e, acc_o };
    }


    int problem3() {
        int targetNumber, countNumbers, acc = 0;
        std::cin >> targetNumber >> countNumbers;
        
        for (auto i = 0; i < countNumbers; i++) {
            int num;
            std::cin >> num;
            if (num == targetNumber)
                acc++;
        }
        return acc;
    }

    std::pair<int, int> problem4() {
        int countNumbers, acc = 0, numbersFiltred = 0;
        std::cin >> countNumbers;

        for (auto i = 0; i < countNumbers; i++) {
            int number;
            std::cin >> number;
            if (number % 3 == 0) {
                acc += number;
                numbersFiltred++;
            }
        }
        return { acc, numbersFiltred };
    }

    int problem5() {
        int countNumbers, minNum, countMinNumbers=1;
        std::cin >> countNumbers >> minNum;

        for (auto i = 1; i < countNumbers; i++) {
            int num;
            std::cin >> num;
            if (num < minNum) {
                minNum = num;
                countMinNumbers = 1;
            }
            else if (num == minNum) {
                countMinNumbers++;
            }
        }
        return countMinNumbers;
    }
}

using namespace problems;


int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //std::setlocale(LC_ALL, "");

    int number;
    std::cin >> number;
   
    switch (number) {
    case Problems::first:
        std::cout << problem1Another();
        break;
    case Problems::second:
    {
        auto [even, odd] = problem2();
        std::cout << even << odd;
        break;
    }
    case Problems::third:
        std::cout << problem3();
        break;
    case Problems::four:
    {
        auto [acc, count] = problem4();
        if (acc == 0 && count == acc)
            std::cout << -1;
        std::cout << (double)acc / count;
        break;
    }
    case Problems::five:
        std::cout << problem5();
        break;
    default:
        std::cout << "не знаю";
    }
}