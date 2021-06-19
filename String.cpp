//
// Created by Renat Kabirov on 2021-06-16.
//
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String() {
    objectType = '1';
    stringPtr = 0;
    stringLength = 0;
}

String::String(const String& copyStr) //конструктор копирования
{
    objectType = '1';
    stringPtr = copyStr.stringPtr;
    stringLength = copyStr.stringLength;
    countCopyConstructor++;
    cout << "Количество вызовов конструктора копирования: " << countCopyConstructor << endl;
}

String::String(const char* charStringPtr) //конструктор, принимающий Си-строку
{
    objectType = '1';
    stringLength = strlen(charStringPtr);
    stringPtr = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++) {
        stringPtr[i] = charStringPtr[i];
    }
    stringPtr[stringLength] = '\0';
    countConstructorCString++;
    cout << "Количество вызовов конструктора принимающего Си-строку: " << countConstructorCString << endl;
}

String::String(char symbol) //конструктор, принимающий 1 символ Си-строки
{
    objectType = '1';
    //длина строки = 2, один под символ и вторая под конец строки \0
    stringLength = 2;
    stringPtr = new char[stringLength];
    stringPtr[0] = symbol;
    stringPtr[1] = '\0';
    countConstructorCSymbol++;
    cout << "Количество вызовов конструктора принимающего 1 символ Си-строки: " << countConstructorCSymbol << endl;
}

String::~String() {
    stringPtr = nullptr;
    stringLength = 0;
    countConstructorCSymbol++;
    cout << "Количество вызовов деструктора: " << countDestructor << endl;
}



String& String::operator=(const String& str)//перегрузка оператора сравнения
{
    stringPtr = str.stringPtr;
    stringLength = str.stringLength;
    return *this;//возвращение указателя на текущий объект
    str.~String();//удаление строки ввода
}

ostream& operator<<(ostream& out, const String& str) //перегрузка оператора поточного вывода
{
    //посимвольное считывание строки
    out << "Вывод строки: ";
    for (int i = 0; i < str.stringLength; i++) {
        cout << str.stringPtr[i];
    }
    out << "\nДлина строки: " << str.stringLength << endl;
    return out;
}
