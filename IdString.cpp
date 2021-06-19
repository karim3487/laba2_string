#include <iostream>
#include "IdString.h"

using namespace std;

bool IdString::checkIdStringForCorrectSymbol(const char *stringPtr) //проверка строки на соответствие идентификатору
{

    if (stringPtr[0] == '_' || (stringPtr[0] >= 'a' && stringPtr[0] <=
                                                       'z'))//первый символ идентификатора должен состоять из "_" или строчкой буквы
    {
        for (int i = 1; i < stringLength; i++) {
            if (!(stringPtr[i] >= 'A' && (stringPtr[i] <= 'Z' || stringPtr[i] >= 'a') && stringPtr[i] <= 'z' &&
                  stringPtr[0] == 95 && (
                          stringPtr[i] >= '0' &&
                          stringPtr[i] <= '9')))//остальные буквы - заглавные и строчные буквы "_", цифры
            {
                break;
            }
        }
        return true;
    }
    return false;
}

IdString::IdString() : String() //наследование конструкторов других классов
{
    objectType = '2';
}

IdString::IdString(const IdString &copyIdStr) : String(copyIdStr) //конструктор копирования
{
    objectType = '2';
}

IdString::IdString(const char *charIdStringPtr) : String(charIdStringPtr) //конструктор, принимающий Си-строку
{
    objectType = '2';
    if (!checkIdStringForCorrectSymbol(charIdStringPtr)) {
        stringLength = 0;
        stringPtr = 0;
    }
}

IdString::IdString(char symbolIdString) : String(symbolIdString) //конструктор, принимающий 1 символ Си-строки
{
    objectType = '2';
}

IdString::~IdString() {
}

void IdString::lastOccurrence(char find) {
    int lastJ = -1;
    for (int j = stringLength - 1; j >= 0; j--) {
        if (stringPtr[j] == find) {
            lastJ = j + 1;
            break;
        }
    }
    cout << find << " Последнее вхождение было на позиции  " << lastJ << ". " << endl;
}

IdString IdString::operator>(const IdString &secondIdStr) {
    if (this->stringLength > secondIdStr.stringLength) {
        return (*this);
    } else {
        return secondIdStr;
    }
}