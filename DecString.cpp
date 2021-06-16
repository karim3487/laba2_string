//
// Created by Renat Kabirov on 2021-06-16.
//

#include "DecString.h"

using namespace std;

DecString::DecString() {

}

//конструктор, принимающий Си-строку
DecString::DecString(const char *charHextStringPtr) : String(charHextStringPtr) {
    objectType = '3';
    if (!checkStringForDec(charHextStringPtr)) {
        stringLength = 0;
        stringPtr = 0;
    }
}

//конструктор, принимающий 1 символ Си-строки
DecString::DecString(char symbolDecString) : String(symbolDecString) {
    objectType = '3';
}

//конструктор копирования
DecString::DecString(const DecString &copyIdStr) : String(copyIdStr) {
    objectType = '3';
}

DecString::~DecString() {}

//проверка строки на соответствие dec-формату
bool DecString::checkStringForDec(const char *stringPtr) {
    if (stringPtr[0] == '+' || stringPtr[0] == '-')//первый символ идентификатора должен состоять из "+" или "-"
    {
        for (int i = 1; i < stringLength; i++) {
            if (!(stringPtr[i] >= '0' && stringPtr[i] <= '9')) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i < stringLength; i++) {
            if (!(stringPtr[i] >= '0' && stringPtr[i] <= '9')) {
                return false;
            }
        }
        return true;
    }
}

DecString DecString::operator-(const DecString& a) {
    DecString firstTempHexString(this->stringPtr), secondTempHexString(a), result('0');//использование конструктора копирования для получения значений

    findDiff(firstTempHexString.stringPtr, secondTempHexString.stringPtr, result.stringPtr);

    return DecString(result.stringPtr);
}


bool DecString::operator<(const DecString &a) {
    return this->isSmaller(a.stringPtr, this->stringPtr);
}

char *DecString::strRev(char* str)
{
    char* p1, * p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void DecString::findDiff(char* _num1, char* _num2,char* _diff) {
    int sub,i,n1,n2,carry,addMinus = 0;
    if (isSmaller(_num1, _num2))
    {
        char* temp = _num1;
        _num1 = _num2;
        _num2 = temp;
        addMinus = 1;

    }
    n1 = strlen(_num1);
    n2 = strlen(_num2);
    strRev(_num1);
    strRev(_num2);
    carry = 0;
    for (i=0; i<n2; ++i)
    {
        sub = ((_num1[i]-'0')-(_num2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        _diff[i] = sub + '0';
    }
    for (i = n2; i < n1; ++i)
    {
        sub = ((_num1[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        _diff[i] = sub + '0';
    }
    if(addMinus)
    {
        _diff[strlen(_diff)] = '-';
        _diff[strlen(_diff)+1] = '\0';
    }
    _diff =  strRev(_diff);
}

bool DecString::isSmaller(char* _num1, char* _num2)
{
    int n1 = strlen(_num1), n2 = strlen(_num2),i;
    char num1,num2;

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (i = 0; i < n1; i++) {
        num1 = _num1[i];
        num2 = _num2[i];
        if (num1 < num2) {
            return true;
        }  else if (num1 > num2){
            return false;
        }
    }
    return false;
}

bool DecString::operator>(const DecString &a) {
    return this->isSmaller(this->stringPtr, a.stringPtr);
}

