//
// Created by Renat Kabirov on 2021-06-16.
//

#ifndef LAB2_STRING_STRING_H
#define LAB2_STRING_STRING_H


#include "MyObject.h"

using namespace std;

class String : public MyObject {
protected:
    char* stringPtr;//указатель на блок динамической памяти
    int stringLength;// длина строки
    static int countCopyConstructor;//количество вызово конструкторов копирования
public:
    String();
    String(const String& copyStr); //конструктор копирования
    String(const char* charStringPtr); //конструктор, принимающий Си-строку
    String(char symbol); //конструктор, принимающий 1 символ Си-строки
    ~String();
    friend std::ostream& operator<<(ostream& out, const String& str);

    String& operator=(const String& str);
    int getCharStringLength();
};


#endif //LAB2_STRING_STRING_H
