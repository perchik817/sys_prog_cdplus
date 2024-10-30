// practice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "lesson002.h"

using namespace std;

int main()
{
    int userNum;
    cout << "Enter a number: ";
    cin >> userNum;
    cout << f(userNum);
    return 0;
}
