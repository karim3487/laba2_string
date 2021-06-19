//
// Created by Renat Kabirov on 2021-06-16.
//

#ifndef LAB2_STRING_DECSTRING_H
#define LAB2_STRING_DECSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "String.h"

using namespace std;

class DecString : public String {
private:
    bool checkStringForDec(const char *stringPtr);

    char *strRev(char *str);

    bool isSmaller(char *num1, char *num2);

    void findDiff(char *_num1, char *_num2, char *_diff);

protected:
    static int countCopyConstructor;//количество вызовов конструкторов копирования
    static int countConstructorCString;//количество вызовов конструкторов принимающих Си-Строку
    static int countConstructorCSymbol;//количество вызовов конструкторов  принимающих 1 символ Си-Строки
    static int countDestructor;//количество вызовов деструктора
public:
    ~DecString();

    DecString();

    DecString(const DecString &);

    DecString(const char *);

    DecString(char);

    DecString operator-(const DecString &_s);

    bool operator>(const DecString &_n);

    bool operator<(const DecString &_n);

};

#endif //LAB2_STRING_DECSTRING_H
