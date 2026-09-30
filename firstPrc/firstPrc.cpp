// firstPrc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <windows.h>
//#include <locale>

enum Problems {
    first = 1,
    second,
    third
};


int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //std::setlocale(LC_ALL, "");

    int number;
    std::wcin >> number;
   
    /*
    if (number == 1)
        std::cout << "один";
    else if (number == 2)
        std::cout << "два";
    else
        std::cout << "неизвестно";
        */
 
    switch (number) {
    case Problems::first:
        std::cout << "first";
        break;
    case Problems::second:
        std::cout << "second";
        break;
    default:
        std::cout << "unknown";
    }
}