#ifndef LAB2_STRING_IDSTRING_H
#define LAB2_STRING_IDSTRING_H


#include "String.h"

class IdString : public String {
    bool checkIdStringForCorrectSymbol(const char *stringPtr); //проверка строки на соответствие идентификатору
protected:
    static int countAnotherConstructor;//количество вызовов конструкторов других классов
    static int countCopyConstructor;//количество вызовов конструкторов копирования
    static int countConstructorCString;//количество вызовов конструкторов принимающих Си-Строку
    static int countDestructor;//количество вызовов деструктора

public:
    IdString();

    IdString(const IdString &copyIdStr);

    IdString(const char *charIdStringPtr);

    ~IdString();

    void lastOccurrence(char find);

    IdString operator>(const IdString &secondIdStr);
};


#endif //LAB2_STRING_IDSTRING_H
