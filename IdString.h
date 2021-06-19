#ifndef LAB2_STRING_IDSTRING_H
#define LAB2_STRING_IDSTRING_H


#include "String.h"

class IdString : public String {
    bool checkIdStringForCorrectSymbol(const char *stringPtr); //проверка строки на соответствие идентификатору
public:
    IdString();
    IdString(const IdString& copyIdStr);
    IdString(const char* charIdStringPtr);
    IdString(char symbolIdString);
    ~IdString();
    void lastOccurrence(char find);
    IdString operator>(const IdString& secondIdStr);
};


#endif //LAB2_STRING_IDSTRING_H
