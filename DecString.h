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
    bool checkStringForDec(const char* stringPtr);
    char* strRev(char *str);
    bool isSmaller(char* num1, char* num2);
    void findDiff(char* _num1, char* _num2,char* _diff);
public:
    ~DecString();

    DecString();

    DecString(const DecString&);

    DecString(const char*);

    DecString(char);

    DecString  operator - (const DecString& _s);
    bool operator>(const DecString& _n);
    bool operator<(const DecString& _n);

};

#endif //LAB2_STRING_DECSTRING_H
